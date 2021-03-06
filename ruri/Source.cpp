#define _WINSOCK_DEPRECATED_NO_WARNINGS

enum Privileges{
	UserBanned = 0,
	UserPublic = 1,
	UserNormal = 2 << 0,
	UserDonor = 2 << 1,
	AdminAccessRAP = 2 << 2,
	AdminManageUsers = 2 << 3,
	AdminBanUsers = 2 << 4,
	AdminSilenceUsers = 2 << 5,
	AdminWipeUsers = 2 << 6,
	AdminManageBeatmaps = 2 << 7,
	AdminManageServers = 2 << 8,
	AdminManageSettings = 2 << 9,
	AdminManageBetaKeys = 2 << 10,
	AdminManageReports = 2 << 11,
	AdminManageDocs = 2 << 12,
	AdminManageBadges = 2 << 13,
	AdminViewRAPLogs = 2 << 14,
	AdminManagePrivileges = 2 << 15,
	AdminSendAlerts = 2 << 16,
	AdminChatMod = 2 << 17,
	AdminKickUsers = 2 << 18,
	UserPendingVerification = 2 << 19,
	UserTournamentStaff = 2 << 20,
	AdminDev = 2 << 21,
	Premium = 2 << 22,
	AdminQAT = 2 << 23
};
enum UserType
{
	None = 0,
	Normal = 1,
	BAT = 2,
	Supporter = 4,
	Friend = 8,
	Peppy = 16,
	Tournament = 32
};
enum bStatus
{
	sIdle,
	sAfk,
	sPlaying,
	sEditing,
	sModding,
	sMultiplayer,
	sWatching,
	sUnknown,
	sTesting,
	sSubmitting,
	sPaused,
	sLobby,
	sMultiplaying,
	sOsuDirect
};

enum Mods
{
	noMod = 0,
	NoFail = 1 << 0,
	Easy = 1 << 1,
	//NoVideo              = 1 << 2,
	Hidden = 1 << 3,
	HardRock = 1 << 4,
	SuddenDeath = 1 << 5,
	DoubleTime = 1 << 6,
	Relax = 1 << 7,
	HalfTime = 1 << 8,
	Nightcore = 1 << 9,
	Flashlight = 1 << 10,
	Autoplay = 1 << 11,
	SpunOut = 1 << 12,
	Relax2 = 1 << 13,
	Perfect = 1 << 14,
	Key4 = 1 << 15,
	Key5 = 1 << 16,
	Key6 = 1 << 17,
	Key7 = 1 << 18,
	Key8 = 1 << 19,
	FadeIn = 1 << 20,
	Random = 1 << 21,
	Cinema = 1 << 22,
	Target = 1 << 23,
	Key9 = 1 << 24,
	KeyCoop = 1 << 25,
	Key1 = 1 << 26,
	Key3 = 1 << 27,
	Key2 = 1 << 28,
	LastMod = 1 << 29,
	KeyMod = Key1 | Key2 | Key3 | Key4 | Key5 | Key6 | Key7 | Key8 | Key9 | KeyCoop,
	FreeModAllowed = NoFail | Easy | Hidden | HardRock | SuddenDeath | Flashlight | FadeIn | Relax | Relax2 | SpunOut | KeyMod,
	ScoreIncreaseMods = Hidden | HardRock | DoubleTime | Flashlight | FadeIn,
	TimeAltering = DoubleTime | HalfTime | Nightcore

};

enum RankStatus {
	RANK_LOCKED = -3,
	UNKNOWN = -2,
	NOT_SUBMITTED = -1,
	PENDING = 0,
	NEED_UPDATE = 1,
	RANKED = 2,
	APPROVED = 3,
	QUALIFIED = 4,
	LOVED = 5
};

#define WIN32_LEAN_AND_MEAN

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KGRY  "\x1B[37m"
#define KRESET "\033[0m"
#define BOT_LOCATION 38

#define MIRROR_IP "5.9.151.156"
#define MIRROR_PORT 80
#define OSU_IP "1.1.1.1"

#define MAX_USER_COUNT 256
#define MAX_USERNAME_LENGTH 19
#define MAX_MULTI_COUNT 64

#define al_min(a, b) ((a) < (b) ? (a) : (b))
#define al_max(a, b) ((a) > (b) ? (a) : (b))

#define MUTEX_LOCK(a) std::lock_guard<std::mutex> LOCKGUARD(a)
#define SHARED_MUTEX_LOCK(a) std::shared_lock<std::shared_mutex> LOCKGUARD(a)

#define CHO_VERSION 19

#define _M(a) std::move(a)

const int PING_TIMEOUT_OSU = 80000;//yes thanks peppy
const bool USER_TEST = 0;

enum OPac {
	NULL_PACKET = 1000,
	client_changeAction = 0,
	client_sendPublicMessage = 1,
	client_logout = 2,
	client_requestStatusUpdate = 3,
	client_pong = 4,
	server_userID = 5,
	server_commandError = 6,
	server_sendMessage = 7,
	server_ping = 8,
	server_handleIRCUsernameChange = 9,
	server_handleIRCQuit = 10,
	server_userStats = 11,
	server_userLogout = 12,
	server_spectatorJoined = 13,
	server_spectatorLeft = 14,
	server_spectateFrames = 15,
	client_startSpectating = 16,
	client_stopSpectating = 17,
	client_spectateFrames = 18,
	server_versionUpdate = 19,
	client_errorReport = 20,
	client_cantSpectate = 21,
	server_spectatorCantSpectate = 22,
	server_getAttention = 23,
	server_notification = 24,
	client_sendPrivateMessage = 25,
	server_updateMatch = 26,
	server_newMatch = 27,
	server_disposeMatch = 28,
	client_partLobby = 29,
	client_joinLobby = 30,
	client_createMatch = 31,
	client_joinMatch = 32,
	client_partMatch = 33,
	server_matchJoinSuccess = 36,
	server_matchJoinFail = 37,
	client_matchChangeSlot = 38,
	client_matchReady = 39,
	client_matchLock = 40,
	client_matchChangeSettings = 41,
	server_fellowSpectatorJoined = 42,
	server_fellowSpectatorLeft = 43,
	client_matchStart = 44,
	AllPlayersLoaded = 45,
	server_matchStart = 46,
	client_matchScoreUpdate = 47,
	server_matchScoreUpdate = 48,
	client_matchComplete = 49,
	server_matchTransferHost = 50,
	client_matchChangeMods = 51,
	client_matchLoadComplete = 52,
	server_matchAllPlayersLoaded = 53,
	client_matchNoBeatmap = 54,
	client_matchNotReady = 55,
	client_matchFailed = 56,
	server_matchPlayerFailed = 57,
	server_matchComplete = 58,
	client_matchHasBeatmap = 59,
	client_matchSkipRequest = 60,
	server_matchSkip = 61,
	server_unauthorised = 62,
	client_channelJoin = 63,
	server_channelJoinSuccess = 64,
	server_channelInfo = 65,
	server_channelKicked = 66,
	server_channelAvailableAutojoin = 67,
	client_beatmapInfoRequest = 68,
	server_beatmapInfoReply = 69,
	client_matchTransferHost = 70,
	server_supporterGMT = 71,
	server_friendsList = 72,
	client_friendAdd = 73,
	client_friendRemove = 74,
	server_protocolVersion = 75,
	server_mainMenuIcon = 76,
	client_matchChangeTeam = 77,
	client_channelPart = 78,
	client_receiveUpdates = 79,
	server_topBotnet = 80,
	server_matchPlayerSkipped = 81,
	client_setAwayMessage = 82,
	server_userPanel = 83,
	IRC_only = 84,
	client_userStatsRequest = 85,
	server_restart = 86,
	client_invite = 87,
	server_invite = 88,
	server_channelInfoEnd = 89,
	client_matchChangePassword = 90,
	server_matchChangePassword = 91,
	server_silenceEnd = 92,
	client_specialMatchInfoRequest = 93,
	server_userSilenced = 94,
	server_userPresenceSingle = 95,
	server_userPresenceBundle = 96,
	client_userPresenceRequest = 97,
	client_userPresenceRequestAll = 98,
	client_userToggleBlockNonFriendPM = 99,
	server_userPMBlocked = 100,
	server_targetIsSilenced = 101,
	server_versionUpdateForced = 102,
	server_switchServer = 103,
	server_accountRestricted = 104,
	server_jumpscare = 105,
	client_matchAbort = 106,
	server_switchTourneyServer = 107,
	client_specialJoinMatchChannel = 108,
	client_specialLeaveMatchChannel = 109
};

enum LoginReply {
	Login_Failed = -1
};

const int MAX_PACKET_LENGTH = 2816;

#ifndef LINUX

#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include <Windows.h>

#define clock_ms clock

#define RURIPORT 420
#define ARIAPORT 421

#define likely(x) x 
#define unlikely(x) x 

#else

#include "Linux.h"


#define RURI_UNIX_SOCKET "/tmp/ruri.sock"
#define ARIA_UNIX_SOCKET "/tmp/aria.sock"


#define likely(x)      __builtin_expect(!!(x), 1) 
#define unlikely(x)    __builtin_expect(!!(x), 0) 

#endif


#include <thread>

typedef unsigned char byte;

WSADATA wsData;

#include <iostream>
#include <vector>
#include <string>
#include <array>

constexpr size_t _strlen_(const char* s)noexcept{
	return *s ? 1 + _strlen_(s + 1) : 0;
}

#define FastVByteAlloc(x)[&]{const char*const a = x; const std::vector<byte> b(a,a + _strlen_(a) + 1); return b;}()
#define MemToData(TYPE, LOC,LEN)\
	[](const size_t mem, const DWORD size)->TYPE{\
		if(!mem || !size)return 0;\
		TYPE ret = 0;\
		const char*const c = (char*)mem;\
		for(DWORD i=0;i<size;i++){\
			if(c[i] < '0' || c[i] > '9')\
				continue;\
			ret = (ret * 10) + (c[i] - '0');\
		}\
		return (c[0] != '-') ? ret : -ret;\
	}((size_t)LOC,LEN)

#define MemToInt32(LOC,LEN)MemToData(int, LOC, LEN)
#define MemToUInt32(LOC,LEN)MemToData(DWORD, LOC, LEN)

#define MemToUInt64(LOC,LEN)MemToData(uint64_t, LOC, LEN)
#define MemToInt64(LOC,LEN)MemToData(int64_t, LOC, LEN)

#define StringToInt32(s) MemToInt32(&s[0],s.size())
#define StringToUInt32(s) MemToUInt32(&s[0],s.size())
#define StringToUInt64(s) MemToUInt64(&s[0],s.size())

#define DeleteAndNull(s)if(s)delete s;s=0

#define MEM_CMP_START(VECT, STR)\
	[&]()->bool{\
		const char*const rS = STR;\
		const size_t rS_Size = _strlen_(rS);\
		if(rS_Size > VECT.size())return 0;\
\
		for(size_t ii=0; ii < rS_Size;ii++)\
			if(rS[ii] != VECT[ii])return 0;\
\
		return 1;\
	}()
#define MEM_CMP_OFF(VECT, STR, OFF)\
	[&]()->bool{\
		const char*const rS = STR;\
		const size_t rS_Size = _strlen_(rS);\
		if(rS_Size + OFF > VECT.size())return 0;\
\
		for(size_t ii=0; ii < rS_Size;ii++)\
			if(rS[ii] != VECT[OFF + ii])return 0;\
\
		return 1;\
	}()

#define LOAD_FILE(FILENAME)													\
	[&](){																	\
		std::ifstream file(std::string(FILENAME), std::ios::binary | std::ios::ate);		\
		if (!file.is_open())												\
			return std::vector<byte>();										\
																			\
		const size_t pos = file.tellg();									\
		if(!pos)return std::vector<byte>();									\
		std::vector<byte> rVec(pos + 1);									\
																			\
		file.seekg(0, std::ios::beg);										\
		file.read((char*)&rVec[0], pos);									\
		file.close();														\
		rVec[rVec.size()-1] = 0;											\
																			\
		return rVec;														\
	}()

#define VEC(s) std::vector<s>

const std::string BOT_NAME = "ruri";
const std::string FAKEUSER_NAME = []{const byte a[] = { 226,128,140,226,128,141,0 }; return std::string((char*)a); }();

#include <time.h>

#include <mutex>
#include <shared_mutex>

#include "SQL.h"
#define BANCHO_THREAD_COUNT 4
_SQLCon SQL_BanchoThread[BANCHO_THREAD_COUNT];

#include "BCrypt/BCrypt.hpp"

#include <time.h>
#include <random>


std::string GET_WEB(const std::string &&HostName, const std::string &Page) {

	SOCKET Socket_WEB = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (!Socket_WEB)
		return "";
	
	struct hostent *hp = gethostbyname(HostName.c_str());

	if (!hp)
		return "";


	SOCKADDR_IN SockAddr_WEB;
	SockAddr_WEB.sin_family = AF_INET;
	SockAddr_WEB.sin_port = htons(80);
	SockAddr_WEB.sin_addr.s_addr = *(unsigned long*)hp->h_addr;
		
	if (connect(Socket_WEB, (SOCKADDR*)(&SockAddr_WEB), sizeof(SockAddr_WEB))){
		closesocket(Socket_WEB);
		return "";
	}

	const std::string pData = "GET /" + Page + " HTTP/1.1\r\nHost: " + HostName + "\r\nConnection: close\r\n\r\n";

	if (send(Socket_WEB, (char*)&pData[0], pData.size(), 0) == SOCKET_ERROR){
		closesocket(Socket_WEB); return "";
	}
	
	int tSize = 0; std::string Return_WEB(MAX_PACKET_LENGTH, '\0'); \
		while (1) {
			const int rByte = recv(Socket_WEB, &Return_WEB[tSize], MAX_PACKET_LENGTH, 0);
			if (rByte == 0)
				break;
			if (rByte < 0)
				return "";

			Return_WEB.resize(Return_WEB.size() + rByte);
			tSize += rByte;
		}

	closesocket(Socket_WEB);
	Return_WEB.resize(tSize);

	return Return_WEB;
}

int CharHexToDecimal(const char c) {

	if (c >= '0' && c <= '9')return c - '0';

	if (c >= 'A' && c <= 'F')return 10 + (c - 'A');

	if (c >= 'a' && c <= 'f')return 10 + (c - 'a');

	return 0;
}

std::string GET_WEB_CHUNKED(const std::string &&HostName, const std::string &Page){

	const std::string rp = GET_WEB(_M(HostName), Page);

	if (rp.size() == 0)
		return "";

	std::string p; p.reserve(rp.size());
	DWORD Start = rp.find("\r\n\r\n");
	if (Start == std::string::npos)
		return "";

	for (DWORD i = Start + 4; i < rp.size(); i++){
		Start = i;
		while (*(USHORT*)&rp[i] != *(USHORT*)"\r\n")i++;
		DWORD ChunkSize = 0;
		for (DWORD z = Start; z < i; z++){
			ChunkSize = ChunkSize << 4;
			ChunkSize += CharHexToDecimal(rp[z]);
		}

		if (ChunkSize == 0)break;

		i += 2;

		if (ChunkSize + i > rp.size())
			return "";

		p.resize(p.size() + ChunkSize); memcpy(&p[p.size() - ChunkSize], &rp[i], ChunkSize);
		i += ChunkSize + 1;
	}

	return p;
}



#define WeakStringToInt(s)\
	[&](){\
		int Return = 0;\
		for (DWORD i = 0; i < s.size(); i++)\
			 Return += (s[i] ^ i) << (((i << 4) % 32));\
		return Return;\
	}()

constexpr int _WeakStringToInt_(const char* c,DWORD O = 0, int CurrentValue = 0) noexcept{	
	return (c[O]) ? _WeakStringToInt_(c,O+1, CurrentValue + ((c[O] ^ O) << (((O << 4) % 32)))) : CurrentValue;
}


struct _Timer{

	const char*const Name;
	DWORD Count;
	std::chrono::steady_clock::time_point sTime;
	
	_Timer(const char*const Name) :Name(Name) { Count = 0; };

	void Start(){
		sTime = std::chrono::steady_clock::now();
	}
	void Stop(const DWORD Num = 0){


		const unsigned long long TTime = std::chrono::duration_cast<std::chrono::nanoseconds> (std::chrono::steady_clock::now() - sTime).count();
		printf(KYEL "%s%i> " KRESET "%fms\n",Name, (!Num) ? Count : Num, double(double(TTime) / 1000000.0));
		if(!Num)Count++;
		Start();
	}

};

std::vector<std::string> UsernameCache;

std::shared_mutex UsernameCacheLock;

void UpdateUsernameCache(_SQLCon *SQL){

	UsernameCacheLock.lock();

	sql::ResultSet* res(SQL->ExecuteQuery("SELECT id,username FROM users WHERE id >= " + std::to_string(UsernameCache.size() + 1000) + " ORDER BY id DESC"));
	DWORD Count = 0;
	if (res && res->next()){
		Count = 1;

		const DWORD HighestID = res->getUInt(1);
		if (HighestID >= 1000) {

			UsernameCache.resize(HighestID - 999);
			UsernameCache[HighestID-1000] = res->getString(2);

			while (res->next()) {
				const DWORD ID = res->getUInt(1);
				if (ID < 1000)break;
				Count++;
				UsernameCache[ID - 1000] = res->getString(2);
			}
		}
	}
	DeleteAndNull(res);
	
	UsernameCacheLock.unlock();

	printf("Updated %i usernames in the cache\n", Count);
}
//This will return [clan]username if clans are enabled.
std::string GetUsernameFromCache(const DWORD UID){

	if (UID < 1000)return "";

	std::string Res = "";

	UsernameCacheLock.lock_shared();
	if ((UID-1000) < UsernameCache.size()) {
		Res = UsernameCache[UID - 1000];
	}
	UsernameCacheLock.unlock_shared();

	return Res;
}
void UsernameCacheUpdateName(const DWORD UID, const std::string &s, _SQLCon *SQL){

	if (UID < 1000)
		return;

	UsernameCacheLock.lock_shared();

	if (UID - 1000 >= UsernameCache.size()){
		UsernameCacheLock.unlock_shared();
		return UpdateUsernameCache(SQL);
	}
	UsernameCache[UID - 1000] = s;

	UsernameCacheLock.unlock_shared();
}

std::string BEATMAP_PATH;
std::string REPLAY_PATH;
std::string osu_API_KEY;
std::string osu_API_BEATMAP;

struct _RankList {
	DWORD ID;
	DWORD PP;
	_RankList() {
		ID = 0;
		PP = 0;
	}
	_RankList(DWORD I, DWORD P) {
		ID = I;
		PP = P;
	}
}; std::vector<_RankList> RankList[8];
DWORD RankListVersion[] = { 1,1,1,1,1,1,1,1 };
std::shared_mutex RankUpdate[8];

void ReSortAllRank() {

	for (DWORD i = 0; i < 8; i++){

		RankUpdate[i].lock();
		RankListVersion[i]++;

		std::sort(RankList[i].begin(), RankList[i].end(),
			[](const _RankList& A, const _RankList &B){
				return A.PP > B.PP;
			});

		RankUpdate[i].unlock();

	}

}

struct _SQLQue{
	std::mutex Lock;
	std::vector<std::string> Commands;

	void AddQue(const std::string &s){

		MUTEX_LOCK(Lock);

		Commands.push_back(s);
	}

}; _SQLQue SQLExecQue;


DWORD GetRank(const DWORD UserID, const DWORD GameMode){//Could use the cached pp to tell around where its supposed to be?

	if (UserID < 1000 || GameMode >= 8 || RankList[GameMode].size() == 0)
		return 0;

	DWORD Rank = 0;
	
	RankUpdate[GameMode].lock_shared();	

	for (DWORD i = 0; i < RankList[GameMode].size(); i++){
		if (RankList[GameMode][i].ID == UserID){
			Rank = i + 1;
			break;
		}
	}

	RankUpdate[GameMode].unlock_shared();

	return Rank;
}

void UpdateRank(const DWORD UserID, const DWORD GameMode, const DWORD PP){

	if (!PP || UserID < 1000 || GameMode >= 8)return;

	RankUpdate[GameMode].lock();
	
	std::vector<_RankList> &cRankList = RankList[GameMode];


	enum { Nothing, Forward, Backward, NoUpdate };

	byte Direction = 0;
	DWORD OrigPos = 0;

	const _RankList n = { UserID,PP };

	for (DWORD i = 0; i < cRankList.size(); i++) {
		if (cRankList[i].ID == UserID) {
			Direction = (cRankList[i].PP > PP) ? Backward : Forward;
			if (cRankList[i].PP == PP)
				Direction = NoUpdate;
			OrigPos = i;
			break;
		}
	}

	if (Direction == Forward || Direction == Backward){

		DWORD NewPos = 0;
		if (Direction == Forward){
			if (OrigPos){
				for (DWORD i = OrigPos - 1; i > 0; i--)
					if (cRankList[i].PP > PP){
						NewPos = i + 1;
						break;
					}
				if (NewPos != OrigPos){
					memcpy(&cRankList[NewPos + 1], &cRankList[NewPos],(OrigPos - NewPos) * sizeof(_RankList));
					cRankList[NewPos] = n;
					RankListVersion[GameMode]++;
				}else cRankList[OrigPos] = n;

			}else cRankList[0] = n;//Rank one improving themself requires no extra calculations.

		}else if(Direction == Backward){
			if (PP){
				for (DWORD i = OrigPos; i < cRankList.size(); i++)
					if (cRankList[i].PP < PP) {
						NewPos = i - 1;
						break;
					}
			}else NewPos = cRankList.size() - 1;

			if (!NewPos)
				NewPos = cRankList.size() - 1;

			if (NewPos != OrigPos){
				memcpy(&cRankList[OrigPos], &cRankList[OrigPos + 1], (NewPos - OrigPos) * sizeof(_RankList));
				cRankList[NewPos] = n;
				RankListVersion[GameMode]++;
			}else cRankList[OrigPos] = n;

			for (DWORD i = cRankList.size(); i > 0; i--){//Pop off 0 pp players
				if (cRankList[i - 1].PP)break;
				cRankList.pop_back();
			}

		}
	}else if (Direction == Nothing && PP){//User is not currently in the rank cache.
		cRankList.push_back(n);
		std::sort(cRankList.begin(), cRankList.end(), [](const _RankList &i, const _RankList &j) {return (i.PP > j.PP); });//I am lazy.
		RankListVersion[GameMode]++;
	}
	RankUpdate[GameMode].unlock();
	printf("Updated ranks gm:%i\n",GameMode);
}


namespace BR {
	std::random_device randomDeviceInit;	
	std::mt19937 mersenneTwister = std::mt19937(randomDeviceInit());

	int GetRand(int min = INT_MIN, int max = INT_MAX) {
		return std::uniform_int_distribution<int>{min, max}(mersenneTwister);
	}
	uint64_t GetRand64(uint64_t min = 0, uint64_t max = uint64_t(-1)) {
		return std::uniform_int_distribution<uint64_t>{min, max}(mersenneTwister);
	}
};


__forceinline void LogError(int i){
	printf(KRED "ERROR CODE: %i\n" KRESET, i);
}
__forceinline void LogError(const char * t, const char* f = 0){
	if(f)return (void)printf(KMAG "%s> " KRED "ERROR: %s\n" KRESET,f, t);
	printf(KRED "ERROR: %s\n" KRESET, t);
}

__forceinline void LogMessage(const char* t, const char* f = 0) {
	if (f)return (void)printf(KMAG "%s> " KRESET "%s\n" KRESET, f, t);
	printf(KMAG "Log: %s\n" KRESET, t);
}
__forceinline void LogMessage(std::string t) {
	printf(KMAG "Log: %s\n" KRESET, t.c_str());
}


void ReplaceAll(std::string &str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
}

__forceinline void AddInt(std::vector<byte> &v, const int Value) {
	v.resize(v.size() + 4);
	*(int*)&v[v.size() - 4] = Value;
}
__forceinline void AddLong(std::vector<byte> &v, const long long Value) {
	v.resize(v.size() + 8);
	*(long long*)&v[v.size() - 8] = Value;
}
__forceinline void AddByte(std::vector<byte> &v, const byte Value) {
	v.push_back(Value);
}
__forceinline void AddShort(std::vector<byte> &v, const short Value) {
	v.resize(v.size() + 2);
	*(short*)&v[v.size() - 2] = Value;
}

#define AddVector(v,VALUE, TYPE)\
	[&](const VEC(TYPE)& Value)->void{\
		if(Value.size() == 0)return;\
		v.resize(v.size() + Value.size());\
		memcpy(&v[v.size() - Value.size()], &Value[0], Value.size());\
	}(std::move(VALUE))

__forceinline void AddMem(std::vector<byte> &v, const void* Value, const DWORD Size) {
	if (Size == 0)return;
	v.resize(v.size() + Size);
	memcpy(&v[v.size() - Size], Value, Size);
}
__forceinline void AddString(std::vector<byte> &v, const std::string &Value) {

	const DWORD Size = Value.size();
	
	if (Size == 0) {
		v.push_back(0);
		return;
	}
	int val = Size;
	v.push_back(0x0b);

		do {
			byte b = val & 0x7f;
			val >>= 7;

			if (val != 0)
				b |= 0x80;  // mark this byte to show that more bytes will follow

			v.push_back(b);
		} while (val != 0);

		v.resize(v.size() + Size);
		memcpy(&v[v.size() - Size], &Value[0], Size);
}
__forceinline void AddString(std::vector<byte> &v, const char* Value, const DWORD Size){

	if (Size == 0) {
		v.push_back(0);
		return;
	}
	int val = Size;
	v.push_back(0x0b);

	do {
		byte b = val & 0x7f;
		val >>= 7;

		if (val != 0)
			b |= 0x80;  // mark this byte to show that more bytes will follow

		v.push_back(b);
	} while (val != 0);

	v.resize(v.size() + Size);
	memcpy(&v[v.size() - Size], &Value[0], Size);
}

struct _BanchoPacket {
	short Type;
	byte Compression;
	std::vector<byte> Data;

	std::vector<byte> GetBytes() const{
		const DWORD DataSize = Data.size();
		std::vector<byte> Bytes(7 + DataSize);

		byte* D = &Bytes[0];
		
		*(USHORT*)(D) = Type;
		*(byte*)(D + 2) = Compression;
		*(DWORD*)(D + 3) = DataSize;

		if (DataSize)
			memcpy(D + 7, &Data[0], DataSize);

		return Bytes;
	}
	const size_t GetSize()const {
		return 7 + Data.size();
	}
	void GetBytes(std::vector<byte> &Bytes) const{

		Bytes.reserve(Bytes.size() + 7 + Data.size());
		byte D[7];
		
		*(USHORT*)D = Type;
		D[2] = Compression;
		*(DWORD*)(D + 3) = Data.size();
		AddMem(Bytes, D, 7);
		AddVector(Bytes, Data, byte);
	}
	void GetBytesRaw(byte* &D) const{
		
		const DWORD DataSize = Data.size();
		*(USHORT*)(D) = Type;
		*(byte*)(D + 2) = Compression;
		*(DWORD*)(D + 3) = DataSize;

		if (DataSize)
			memcpy(D + 7, &Data[0], DataSize);

		D += 7 + DataSize;
	}

	_BanchoPacket() {
		Type = 0;
		Compression = 0;
	}
	_BanchoPacket(const short ID) {
		Type = ID;
		Compression = 0;
	}
	_BanchoPacket(const short ID, const std::vector<byte> &v): Data(v){
		Type = ID;
		Compression = 0;
	}
	_BanchoPacket(const short ID, const DWORD vSize) {
		Type = ID;
		Compression = 0;
		Data.resize(vSize);
	}
};
const _BanchoPacket erPacket(NULL_PACKET);

struct _DelayedBanchoPacket{
	int Time;
	_BanchoPacket b;

	_DelayedBanchoPacket() {
		Time = 0;
	}
	_DelayedBanchoPacket(const int t, const _BanchoPacket a) {
		Time = t;
		b = a;
	}

};

struct _UserStats {

private:
	DWORD RankVersion;
	DWORD GameRank;
public:

	unsigned long long tScore;
	unsigned long long rScore;
	int pp;
	float Acc;
	int PlayCount;

	DWORD getRank(const DWORD GameMode, const DWORD UID){
		if (GameMode >= 8)
			return 0;

		const DWORD cVersion = RankListVersion[GameMode];

		if (cVersion != RankVersion){
			RankVersion = cVersion;
			GameRank = GetRank(UID, GameMode);
		}

		return GameRank;
	}

	_UserStats() {
		tScore = 0;
		rScore = 0;
		pp = 0;
		Acc = 0;
		PlayCount = 0;
		GameRank = 0;
		RankVersion = 0;
	}
	void reset(){
		RankVersion = 0;
	}
};

#define EXPLODE(TYPE,DATA,LEN,DELMNT)[](const char*const d,const size_t Size)->VEC(TYPE){\
	VEC(TYPE) Output;\
	if(!d || !Size)\
		return Output;\
	const char* Start = d;\
	for(size_t i = 0; i< Size;i++){\
		if(d[i] == DELMNT){\
			Output.push_back(TYPE(Start,d + i));\
			Start = d + i + 1;\
		}\
	}\
	if(Start != d + Size)\
		Output.push_back(TYPE(Start,d + Size));\
	return Output;\
	}((const char*const)DATA,LEN)

#define EXPLODE_MULTI(TYPE,DATA,LEN,DELMNT)[](const char*const d,const size_t Size)->VEC(TYPE){\
	VEC(TYPE) Output;\
	if(!d || !Size)\
		return Output;\
	const char* Deli = DELMNT;\
	const size_t DeliSize = _strlen_(Deli);\
	const char* Start = d;\
	for(size_t i = 0; i< Size - (DeliSize - 1);i++){\
		for(size_t z = 0; z < DeliSize; z++){\
			if(d[i + z] != Deli[z])break;\
			if(z != DeliSize - 1)continue;\
			Output.push_back(TYPE(Start,d + i));\
			i += DeliSize - 1;\
			Start = d + i + 1;\
		}\
	}\
	if(Start != d + Size)\
		Output.push_back(TYPE(Start,d + Size));\
	return Output;\
	}((const char*const)DATA,LEN)


#define EXPLODE_VEC(TYPE, VECT,DELMNT)EXPLODE(TYPE,&VECT[0],VECT.size(),DELMNT)

#define _READINT32(s) [](const char* sP){					\
				if(!sP)return 0;							\
				const bool Negative = (*sP == '-');			\
				if(Negative)sP++;							\
															\
				int r = 0;									\
															\
				while(*sP >= '0' && *sP <= '9'){			\
					r = (r * 10) + (*sP - '0');				\
					sP++;									\
				}											\
				return (Negative) ? -r : r;					\
			}(s)

#define MD5CMP(x,y) (memcmp(x,y,32) == 0)

__forceinline std::string MenuClickButton(const std::string Command, const std::string Desc) {
	return "[osump://0/" + Command + "|" + FAKEUSER_NAME + " " + Desc + "]";
}


__forceinline void AddStringToVector(std::vector<byte> &v, const std::string &s){
	if (s.size() == 0)return;
	v.resize(v.size() + s.size());
	memcpy(&v[v.size() - s.size()], &s[0], s.size());
}

#include "Connection.h"

std::vector<_HttpHeader> Empty_Headers;
std::vector<byte> Empty_Byte;

bool UpdateUserStatsFromDB(_SQLCon *SQL,const DWORD UserID, DWORD GameMode, _UserStats &stats){

	if (GameMode >= 8)return 0;
	const DWORD RawGameMode = GameMode;
	const std::string ScoreTableName = (GameMode >= 4) ? "scores_relax" : "scores";
	const std::string StatsTableName = (GameMode >= 4) ? "rx_stats" : "users_stats";
	
	const static std::string AccColName[] = {"avg_accuracy_std","avg_accuracy_taiko","avg_accuracy_ctb","avg_accuracy_mania"};
	const static std::string ppColName[] = { "pp_std","pp_taiko","pp_ctb","pp_mania" };

	GameMode = GameMode % 4;

	sql::ResultSet *res = SQL->ExecuteQuery("SELECT accuracy,pp FROM " + ScoreTableName + " WHERE userid = " + std::to_string(UserID) + " AND play_mode = " + std::to_string(GameMode) + " AND completed = 3 AND pp > 0 ORDER BY pp DESC LIMIT 100");
	DWORD Count = 0;
	double TotalAcc = 0.;
	double TotalPP = 0.;

	while (res && res->next()){
		if(Count < 50)
			TotalAcc += res->getDouble(1);
		TotalPP += res->getDouble(2) * std::pow(0.95,double(Count));
		Count++;
	}
	DeleteAndNull(res);

	const double ACC = (!Count) ? 0.f : (TotalAcc / double((Count > 50) ? 50 : Count));
	
	const float acc = (!Count) ? 0.f : ACC / 100.f;
	const int pp = (int)round(TotalPP);

	if (acc != stats.Acc || pp != stats.pp){

		if (pp != stats.pp)
			UpdateRank(UserID, RawGameMode, pp);

		stats.pp = pp;
		stats.Acc = acc;

		SQLExecQue.AddQue("UPDATE " + StatsTableName + " SET " + AccColName[GameMode] + " = " + std::to_string(ACC) + ", "
			+ ppColName[GameMode] + " = " + std::to_string(TotalPP)
			+ " WHERE id = " + std::to_string(UserID) + " LIMIT 1");
	}

	return 1;
}

enum MenuStates {
	Menu_None,
	Menu_ChooseScore

};

struct _Menu {
	DWORD State;
	int PreviousMap;
	int ChangePage;
	int LastPage;
	int aux1;
	std::string saux1;
	bool BanchoLoaded;
	bool ForceReDraw;

	_Menu() {
		State = 0;
		BanchoLoaded = 0;
		PreviousMap = 0;
		aux1 = 0;
		LastPage = 0;
		ChangePage = 0;
		ForceReDraw = 0;
	}
};

#include "Achievement.h"

#define MAX_CHAN_COUNT 32


void DisconnectUser(size_t Pointer);

struct _User{

	uint64_t choToken;
	DWORD UserID;
	DWORD privileges;
	int silence_end;
	std::string Username;
	std::string Username_Safe;
	char Password[32];//Could be half the size but who cares
	char ActionMD5[32];
	DWORD actionMods;
	int BeatmapID;
	byte timeOffset;
	byte country;
	byte GameMode;
	byte actionID;
	float lat;
	float lon;

	std::mutex StatsAdd;

	_UserStats Stats[8];//4 normal modes + 4 more relax ones

	std::string ActionText;
	int LastPacketTime;
	_User* CurrentlySpectating;
	
	int LoginTime;
	bool SendToken;
	bool inLobby;
	bool HyperMode;
	byte comMatchPage;
	std::mutex SpecLock;
	std::vector<_User*> Spectators;
	//std::mutex MultiLock;
	USHORT CurrentMatchID;
	
	int LastSentBeatmap;
	//_Menu Menu;
	DWORD Friends[256];

	DWORD Blocked[32];

	bool FriendsOnlyChat;

	bool AddBlock(const DWORD UID){
		if (UID < 1000)return 0;

		for (byte i = 0; i < 32; i++) {
			if (!Blocked[i] || Blocked[i] == UID) {
				Blocked[i] = UID;
				return 1;
			}
		}

		return 0;
	}

	_Achievement Ach;//TODO: thread this.

	std::vector<_BanchoPacket> Que;
	std::vector<_DelayedBanchoPacket> dQue;
	size_t ActiveChannels[MAX_CHAN_COUNT];//There is no way to resolve the actual size without restructuring xdxdxd

	void AddChannel(const size_t C){
		for (DWORD i = 0; i < MAX_CHAN_COUNT; i++){
			if (!ActiveChannels[i]) {
				ActiveChannels[i] = C;
				return;
			}
		}
	}
	void RemoveChannel(const size_t C) {
		for (DWORD i = 0; i < MAX_CHAN_COUNT; i++) {
			if (ActiveChannels[i] == C) {
				ActiveChannels[i] = 0;
				return;
			}
		}
	}


	std::mutex qLock;
	std::string c1Check;
	
	std::mutex RefLock;
	DWORD ref;
	void addRef() {
		RefLock.lock();
		ref++;
		RefLock.unlock();
	}

	DWORD GetStatsOffset()const{

		if (GameMode > 3)return 3;

		return (actionMods & Mods::Relax) ? GameMode + 4 : GameMode;
	}

	void SendToSpecs(const _BanchoPacket &b) {

		if (!Spectators.size())
			return;

		SpecLock.lock();

		for (_User*const Spec : Spectators)
			if (Spec)
				Spec->addQue(b);

		SpecLock.unlock();
	}
	bool isFriend(const DWORD ID) const{

		if (UserID == ID)
			return 1;//Always friends with your self :)

		for (DWORD i = 0; i < 256; i++)
			if (Friends[i] == ID)
				return 1;

		return 0;
	}
	bool isBlocked(const DWORD ID) const{
		if (UserID < 1000 || ID == UserID)
			return 0;

		for (DWORD i = 0; i < 32; i++)
			if (Blocked[i] == ID)
				return !isFriend(ID);

		return 0;
	}

	bool isSilenced()const{
		return silence_end ? (time(0) <= silence_end) : 0;
	}
void reset() {
		DisconnectUser(size_t(this));
		choToken = 0;
		UserID = 0;
		SendToken = 0;
		privileges = 0;
		Username.clear();
		Username_Safe.clear();
		ZeroMemory(Password, 32);
		ZeroMemory(ActionMD5, 32);
		actionMods = 0;
		BeatmapID = 0;
		timeOffset = 0;
		country = 0;
		GameMode = 0;
		lat = 0.f;
		lon = 0.f;
		ActionText.clear();
		LastPacketTime = 0;
		LoginTime = 0;
		CurrentlySpectating = 0;
		CurrentMatchID = 0;
		inLobby = 0;
		Spectators.clear();
		Que.clear();
		comMatchPage = 0;
		HyperMode = 0;
		LastSentBeatmap = 0;
		FriendsOnlyChat = 0;
		ZeroMemory(&Friends[0], 256 * sizeof(Friends[0]));
		ZeroMemory(&Blocked[0], 32 * sizeof(Blocked[0]));
		c1Check.clear();
		silence_end = 0;
	}
	_User(){
		reset();
		Spectators.reserve(16);
		Que.reserve(512);
		ref = 0;
	}
	

	void addQue(const _BanchoPacket &b) {
		if (b.Type == NULL_PACKET || !choToken)return;

		qLock.lock();
		if(choToken)Que.push_back(b);
		qLock.unlock();
	}
	void addQue(const VEC(_BanchoPacket) &b){
		if (choToken && b.size()) {
			qLock.lock();
			for (const auto& p : b){
				if (p.Type == NULL_PACKET)
					continue;
				Que.push_back(p);
			}

			qLock.unlock();
		}
	}

	void addQueDelay(const _DelayedBanchoPacket &b) {

		if (b.b.Type == NULL_PACKET || b.Time == 0 || !choToken)return;
		
		qLock.lock();
		if(choToken)dQue.push_back(b);
		qLock.unlock();
	}

	void addQueNonLocking(const _BanchoPacket &b){
		if (b.Type == NULL_PACKET || !choToken)return;
		Que.push_back(b);
	}
	void addQueDelayNonLocking(const _DelayedBanchoPacket &b) {

		if (b.b.Type == NULL_PACKET || b.Time == 0 || !choToken)return;
		dQue.push_back(b);
	}

	void doQue(_Con s){

		std::vector<byte> SendBytes;

		if (Que.size() == 0 && dQue.size() == 0)
			goto FEEDALIVE;

		qLock.lock();

		if (Que.size()){
					
			SendBytes.resize([&](){
				size_t S = 0;
				for (const auto& q : Que)
					S += q.GetSize();
				return S;
			}());

			byte* cPos = (byte*)&SendBytes[0];

			for (const auto& q : Que)
				q.GetBytesRaw(cPos);

			Que.clear();
		}

		if (dQue.size() != 0){

			std::sort(dQue.begin(), dQue.end(), [](const _DelayedBanchoPacket i, const _DelayedBanchoPacket j) { return (i.Time < j.Time); });

			const int cTime = clock_ms();
			bool NotEnd = 0;
			for (size_t i = dQue.size() - 1; i < dQue.size(); i--){
				if (dQue[i].Time == 1){//means do the next bancho frame.
					dQue[i].Time = 0;
					NotEnd = 1;
					continue;
				}
				if (dQue[i].Time == 2) {
					dQue[i].Time = 1;
					NotEnd = 1;
					continue;
				}
				if(dQue[i].Time <= cTime){
					dQue[i].b.GetBytes(SendBytes);

					if(!NotEnd)dQue.pop_back();
					else{
						dQue[i] = dQue[dQue.size() - 1];
						dQue.pop_back();//Dont really care about it being slightly off. The next sort will correct this.
					}

				}else break;
			}
		}
		qLock.unlock();

		if (SendBytes.size())
			s.SendData(ConstructResponse(200, (!SendToken) ? Empty_Headers : std::vector<_HttpHeader>{ _HttpHeader("cho-token", std::to_string(choToken).c_str()) }, SendBytes));
		else{
		FEEDALIVE:
			s.SendData(ConstructResponse(200, Empty_Headers, SendBytes));
		}

	}

}; std::array<_User, MAX_USER_COUNT> Users;

void DisconnectUser(_User *u);

void DisconnectUser(size_t Pointer){
	return (Pointer) ? DisconnectUser((_User*)Pointer) : void();
}

void debug_LogOutUser(_User *p);


struct _UserRef {
	_User* User;

	_UserRef(){User = 0;}
	_UserRef(_User* U, bool AlreadyDoneRef): User(U){
		if (!User || AlreadyDoneRef)return;
		User->RefLock.lock();
		User->ref++;
		User->RefLock.unlock();
	}
	~_UserRef() {
		if (!User)
			return;
		User->RefLock.lock();
		User->ref--;
		User->RefLock.unlock();
	}

	_User* operator->() {
		return User;
	}

	const bool operator!() {
		return !(User);
	}

};

#define UserDoubleCheck(s) if(!(s))continue;MUTEX_LOCK(User.RefLock);if(unlikely(!(s)))continue;User.ref++;


_User* GetPlayerSlot_Safe(const std::string &UserName){

	if (!UserName.size())return 0;


	for (auto& User : Users){

		UserDoubleCheck(User.Username_Safe == UserName)

		return &User;
	}

	//User has not logged in before. Opt for a free slot instead

	for (auto& User : Users){

		UserDoubleCheck(!User.ref)
		User.reset();

		return &User;
	}

	return 0;
}



_User* GetUserFromID(DWORD ID) {

	if (int(ID) < 1000)return 0;
	
	for (auto& User : Users) {
		UserDoubleCheck(User.UserID == ID)
		return &User;
	}
	return 0;
}

_User* GetUserFromToken(const uint64_t Token) {

	if (!Token)return 0;
	
	for (auto& User : Users) {
		UserDoubleCheck(User.choToken == Token)
		return &User;
	}

	return 0;
}
_User* GetUserFromName(const std::string &Name, const bool Force = 0){

	if (Name.size() == 0)return 0;

	for (auto& User : Users){
		UserDoubleCheck((User.choToken || Force) && Name == User.Username)
		return &User;
	}

	return 0;
}
_User* GetUserFromNameSafe(const std::string &Name, const bool Force = 0) {

	if (Name.size() == 0)return 0;

	for (auto& User : Users){

		UserDoubleCheck((User.choToken || Force) && Name == User.Username_Safe)

		return &User;
	}

	return 0;
}

DWORD GetIDFromName(const std::string &Name) {

	if (Name.size() == 0)return 0;

	for (auto& User : Users) {

		if (User.Username != Name)
			continue;

		return User.UserID;
	}

	return 0;
}


#define GetUserType(a)[](byte x)->byte{ \
			if (x & Privileges::AdminDev)return UserType::Peppy; \
			if (x & Privileges::AdminBanUsers)return UserType::Friend; \
			if (x & (Privileges::AdminChatMod | Privileges::AdminManageBeatmaps | Privileges::AdminQAT))return UserType::BAT; \
			if (x & (Privileges::Premium | Privileges::UserDonor))return UserType::Supporter; \
			return UserType::Normal; \
		}(a)


namespace bPacket {

	__forceinline _BanchoPacket Message(const std::string &senderName, const std::string &targetname, const std::string &message, const int senderId) {

		_BanchoPacket b(OPac::server_sendMessage);

		AddString(b.Data, senderName);
		AddString(b.Data, message);
		AddString(b.Data, targetname);
		AddInt(b.Data, senderId);

		return b;
	}
	__forceinline _BanchoPacket BotMessage(const std::string &Target, const std::string &message, const std::string &Name = BOT_NAME, const DWORD ID = 999) {

		_BanchoPacket b(OPac::server_sendMessage);

		b.Data.reserve(10 + Name.size() + message.size() + Target.size());

		AddString(b.Data, Name);
		AddString(b.Data, message);
		AddString(b.Data, Target);
		AddInt(b.Data, ID);

		return b;
	}
}

#include "Channel.h"


const _BanchoPacket BOT_STATS = [] {
	_BanchoPacket b(OPac::server_userStats);
	AddInt(b.Data, 999);
	b.Data.push_back(0);//actionID
	AddString(b.Data, "");//actiontext
	AddString(b.Data, "");//md5
	AddInt(b.Data, 0);//mods
	b.Data.push_back(0);//gamemode
	AddInt(b.Data, 0);//beatmapid
	AddLong(b.Data, 0);//rankedscore
	AddInt(b.Data, 0);//acc
	AddInt(b.Data, 0);//playcount
	AddLong(b.Data, 0);//total score
	AddInt(b.Data, 0);//gamerank
	AddShort(b.Data, 0);//pp
	return b;
}();

namespace bPacket {

	__forceinline _BanchoPacket Notification(const std::string &Mes) {

		_BanchoPacket b(OPac::server_notification);

		AddString(b.Data, Mes);

		return b;
	}
	__forceinline _BanchoPacket ChannelInfo(const _Channel* c) {

		_BanchoPacket b(OPac::server_channelInfo);

		AddString(b.Data, c->ChannelName);
		AddString(b.Data, c->ChannelDesc);
		AddShort(b.Data, c->ChannelCount);

		return b;
	}
	__forceinline _BanchoPacket ChannelInfo(const std::string Name, const std::string Desc, USHORT Count) {

		_BanchoPacket b(OPac::server_channelInfo);

		AddString(b.Data, Name);
		AddString(b.Data, Desc);
		AddShort(b.Data, Count);

		return b;
	}

	#define bPacket4Byte(ID, VALUE)[&]()->const _BanchoPacket{_BanchoPacket b(ID,{0,0,0,0});*(DWORD*)&b.Data[0] = VALUE;return b;}()

	__forceinline _BanchoPacket RawData(short ID, const byte* Value, const DWORD Size) {

		_BanchoPacket b(ID);

		b.Data.resize(Size);

		memcpy(&b.Data[0], Value, Size);

		return b;
	}

	__forceinline _BanchoPacket GenericString(short ID, const std::string &Value) {

		_BanchoPacket b(ID);

		AddString(b.Data, Value);

		return b;
	}

	__forceinline _BanchoPacket GenericInt32List(short ID, const std::vector<int> &Value, const bool BigHeader) {

		_BanchoPacket b(ID);

		if (BigHeader)
			AddInt(b.Data, Value.size());
		else
			AddShort(b.Data, Value.size());

		for (DWORD i = 0; i<Value.size(); i++)
			AddInt(b.Data, Value[i]);

		return b;
	}
	__forceinline _BanchoPacket GenericDWORDList(short ID, const std::vector<DWORD> &Value, const bool BigHeader){

		_BanchoPacket b(ID);

		if (BigHeader)
			AddInt(b.Data, Value.size());
		else
			AddShort(b.Data, Value.size());

		for (DWORD i = 0; i<Value.size(); i++)
			AddInt(b.Data, Value[i]);

		return b;
	}


	__forceinline _BanchoPacket UserPanel(const DWORD UserID, const DWORD AskerID) {

		if (UserID < 1000){
			_BanchoPacket b(OPac::server_userPanel);
			AddInt(b.Data, UserID);

			switch (UserID){
			case 999:
				AddString(b.Data, BOT_NAME);
				break;
			case 998:
				AddString(b.Data, FAKEUSER_NAME);
				break;
			default:
				AddString(b.Data, "Not Set");
				break;
			}

			b.Data.push_back(0);//timezone
			b.Data.push_back(BOT_LOCATION);//country
			b.Data.push_back(UserType::Peppy);//userank
			AddInt(b.Data, 0);//long
			AddInt(b.Data, 0);//lat
			AddInt(b.Data, 0);//gamerank
			return b;
		}

		_UserRef tP(GetUserFromID(UserID),1);

		if (!tP || !tP->UserID || (UserID != AskerID && !(tP->privileges & UserPublic)))return erPacket;

		_BanchoPacket b(OPac::server_userPanel);

		AddInt(b.Data, UserID);
		AddString(b.Data, tP->Username);
		b.Data.push_back(24 + tP->timeOffset);
		b.Data.push_back(tP->country);
		b.Data.push_back((UserID != AskerID) ? GetUserType(tP->privileges) : UserType::Supporter);
		AddInt(b.Data, *(int*)&tP->lon);
		AddInt(b.Data, *(int*)&tP->lat);
		const DWORD sOff = tP->GetStatsOffset();
		AddInt(b.Data, tP->Stats[sOff].getRank(sOff,tP->UserID));

		return b;
	}
	__forceinline _BanchoPacket UserPanel(_User *tP) {

		_BanchoPacket b(OPac::server_userPanel);

		AddInt(b.Data, tP->UserID);
		AddString(b.Data, tP->Username);
		b.Data.push_back(24 + tP->timeOffset);
		b.Data.push_back(tP->country);
		b.Data.push_back(GetUserType(tP->privileges));
		AddInt(b.Data, *(int*)&tP->lon);
		AddInt(b.Data, *(int*)&tP->lat);
		const DWORD sOff = tP->GetStatsOffset();
		AddInt(b.Data, tP->Stats[sOff].getRank(sOff,tP->UserID));

		return b;
	}

#define USER_STATS(UID, AID)\
	[](const DWORD UserID, const DWORD AskerID)->const _BanchoPacket{\
		if (UserID == 999)return BOT_STATS;\
		if(UserID < 999){\
			_BanchoPacket b = BOT_STATS;\
			*(DWORD*)&b.Data[0] = UserID;\
			return b;\
		}\
		_UserRef tP(GetUserFromID(UserID),1);\
		if (!tP || !tP->choToken || (!(tP->privileges & UserPublic) && UserID != AskerID))\
			return bPacket4Byte(OPac::server_userLogout, UserID);\
		const DWORD Off = tP->GetStatsOffset();\
\
		_BanchoPacket b(OPac::server_userStats);\
		b.Data.reserve(128);\
		AddInt(b.Data, UserID);\
		b.Data.push_back(tP->actionID);\
\
		AddString(b.Data, tP->ActionText);\
		if (tP->ActionMD5[0] == 0)AddString(b.Data, "");\
		else AddString(b.Data, std::string(tP->ActionMD5, 32));\
\
		AddInt(b.Data, tP->actionMods);\
		b.Data.push_back(tP->GameMode);\
		AddInt(b.Data, tP->BeatmapID);\
		AddLong(b.Data, tP->Stats[Off].rScore);\
		AddInt(b.Data, *(int*)&tP->Stats[Off].Acc);\
		AddInt(b.Data, (tP->Stats[Off].pp > USHORT(-1)) ? (tP->Stats[Off].pp) : tP->Stats[Off].PlayCount);\
		AddLong(b.Data, tP->Stats[Off].tScore);\
		AddInt(b.Data, tP->Stats[Off].getRank(Off, tP->UserID));\
		AddShort(b.Data, USHORT(tP->Stats[Off].pp));\
\
		return b;\
	}(UID,AID)

	/*
	_BanchoPacket UserStats(const DWORD UserID, const DWORD AskerID) {

		if (UserID < 1000){//Hard Coded bot stats

			if (UserID == 999)
				return BOT_STATS;

			_BanchoPacket b = BOT_STATS;\
			*(DWORD*)&b.Data[0] = UserID;\
			return b;\
		}

		_UserRef tP = GetUserFromID(UserID);

		if (!tP || !tP->choToken || (!(tP->privileges & UserPublic) && UserID != AskerID))
			return bPacket4Byte(OPac::server_userLogout,UserID);

		_BanchoPacket b(OPac::server_userStats, 128);

		const DWORD Off = tP->GetStatsOffset();

		AddInt(b.Data, UserID);
		b.Data.push_back(tP->actionID);

		AddString(b.Data, tP->ActionText);
		if (tP->ActionMD5[0] == 0)AddString(b.Data, "");
		else AddString(b.Data, std::string(tP->ActionMD5, 32));

		AddInt(b.Data, tP->actionMods);
		b.Data.push_back(tP->GameMode);
		AddInt(b.Data, tP->BeatmapID);
		AddLong(b.Data, tP->Stats[Off].rScore);
		AddInt(b.Data, *(int*)&tP->Stats[Off].Acc);
		AddInt(b.Data, (tP->Stats[Off].pp > USHORT(-1)) ? (tP->Stats[Off].pp) : tP->Stats[Off].PlayCount);
		AddLong(b.Data, tP->Stats[Off].tScore);
		AddInt(b.Data, tP->Stats[Off].getRank(Off,tP->UserID));
		AddShort(b.Data, USHORT(tP->Stats[Off].pp));

		return b;
	}*/

	__forceinline _BanchoPacket UserStats(_User *tP) {

		if (!tP || !tP->choToken || !(tP->privileges & UserPublic))
			return bPacket4Byte(OPac::server_userLogout, tP->UserID);

		const DWORD Off = tP->GetStatsOffset();

		_BanchoPacket b(OPac::server_userStats);
		b.Data.reserve(128);

		AddInt(b.Data, tP->UserID);
		b.Data.push_back(tP->actionID);
		AddString(b.Data, tP->ActionText);
		if (tP->ActionMD5[0] == 0)AddString(b.Data, "");
		else AddString(b.Data, tP->ActionMD5, 32);
		AddInt(b.Data, tP->actionMods);
		b.Data.push_back(tP->GameMode);
		AddInt(b.Data, tP->BeatmapID);
		AddLong(b.Data, tP->Stats[Off].rScore);
		AddInt(b.Data, *(int*)&tP->Stats[Off].Acc);
		AddInt(b.Data, (tP->Stats[Off].pp > USHORT(-1)) ? (tP->Stats[Off].pp) : tP->Stats[Off].PlayCount);
		AddLong(b.Data, tP->Stats[Off].tScore);
		AddInt(b.Data, tP->Stats[Off].getRank(Off, tP->UserID));
		AddShort(b.Data, USHORT(tP->Stats[Off].pp));

		return b;
	}


}


void debug_SendOnlineToAll(_User *p){

	if (!(p->privileges & UserPublic))
		return;//Do not even care about restricted users for now.

	const _BanchoPacket Panel = bPacket::UserPanel(p->UserID, 0);
	const _BanchoPacket Stats = USER_STATS(p->UserID, 0);


	for (auto& User : Users) {
		if (!User.choToken || &User == p)
			continue;

		User.qLock.lock();

		User.addQueNonLocking(Panel);
		User.addQueNonLocking(Stats);

		User.qLock.unlock();

	}
}

void Event_client_stopSpectating(_User *u){
	
	u->addQue(bPacket::GenericString(OPac::server_channelKicked, "#spectator"));

	_User *const SpecTarget = u->CurrentlySpectating;
	
	if (!SpecTarget)return;

	u->CurrentlySpectating = 0;

	bool AllEmptySpecs = 1;

	_BanchoPacket b = bPacket4Byte(OPac::server_fellowSpectatorLeft, u->UserID);

	{
		SpecTarget->SpecLock.lock();

		for (_User*& Spec : SpecTarget->Spectators){

			if (Spec == u){
				Spec = 0;
				break;
			}
		}
		for (_User*const Spec : SpecTarget->Spectators) {
			if (!Spec)continue;

			Spec->addQue(b);

			AllEmptySpecs = 0;
		}

		if (AllEmptySpecs)
			SpecTarget->Spectators.clear();

		SpecTarget->SpecLock.unlock();
	}
	b.Type = OPac::server_spectatorLeft;
	SpecTarget->addQue(b);

	if (AllEmptySpecs)
		SpecTarget->addQue(bPacket::GenericString(OPac::server_channelKicked,"#spectator"));
}

void Event_client_cantSpectate(_User *tP) {

	_User *SpecHost = tP->CurrentlySpectating;

	if (!SpecHost)
		return;

	const _BanchoPacket b = bPacket4Byte(OPac::server_spectatorCantSpectate, tP->UserID);
	SpecHost->SendToSpecs(b);
	SpecHost->addQue(std::move(b));
}

DWORD COUNT_REQUESTS = 0;
DWORD COUNT_MULTIPLAYER = 0;

void RenderHTMLPage(_Con s, const _HttpRes &&res){

	std::vector<byte> Body;

	AddStringToVector(Body, "<HTML><img src=\"https://cdn.discordapp.com/attachments/385279293007200258/567292020104888320/unknown.png\">"
		"<br>" + std::to_string(COUNT_REQUESTS) + " connections handled."
		"<br>"+ std::to_string(COUNT_MULTIPLAYER) + " currently active multiplayer games.</HTML>");

	s.SendData(ConstructResponse(405, {_HttpHeader("Content-Type", "text/html; charset=utf-8")}, Body));
}

uint64_t GenerateChoToken(){
	/*
	for (DWORD i = 0; i < MAX_USER_COUNT; i++)
		if (Token == User[i].choToken)goto RETRY;*///One in 18 quintillion lol... I think I will take my bets that this will never collide.

	return BR::GetRand64();
}
__forceinline std::string ReadUleb(size_t &O, const size_t Max) {

	if(O >= Max)return "";

	if (*(byte*)O != 0) {
		O++;
		if (O >= Max)return "";
		byte tB = *(byte*)O; O++;
		int sLength = tB & 0x7F;
		for (int i = 1; tB & 0x80; ++i){
			if (O >= Max)return "";
			tB = *(byte*)O; O++;
			sLength |= (tB & 0x7F) << 7 * i;
		}

		if (size_t(O) + sLength > Max)return "";

		const char* S = (char*)O;
		O += sLength;

		return std::string(S,sLength);

	}else O++;

	return "";
}

__forceinline void SkipUleb(size_t &O, const size_t Max) {

	if (O >= Max)return;

	if (*(byte*)O != 0) {
		O++;
		if (O >= Max)return;
		byte tB = *(byte*)O; O++;
		int sLength = tB & 0x7F;
		for (int i = 1; tB & 0x80; ++i) {
			if (O >= Max)return;
			tB = *(byte*)O; O++;
			sLength |= (tB & 0x7F) << 7 * i;
		}

		if (size_t(O) + sLength > Max)
			return;

		O += sLength;

	}
	else O++;
}


void Event_client_channelJoin(_User *tP,const byte* const Packet, const DWORD Size){

	if (Size <= 2)
		return;

	size_t O = (size_t)&Packet[0];

	const std::string ChannelName = ReadUleb(O,O + Size);


	_Channel *c = GetChannelByName(ChannelName);

	/*if(!c && tP->CurrentlySpectating && ChannelName != "#spectator") {
		tP->addQue(bPacket::GenericString(OPac::server_channelJoinSuccess, ChannelName.c_str()));
		return;
	}*/
	
	if (!c) {
		tP->addQue(bPacket::GenericString(OPac::server_channelKicked, ChannelName.c_str()));
		return;
	}

	c->JoinChannel(tP);

	tP->addQue(bPacket::GenericString(OPac::server_channelJoinSuccess, ChannelName.c_str()));

}
void Event_client_channelPart(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size <= 2)return;

	size_t O = (size_t)&Packet[0];

	const std::string ChannelName = ReadUleb(O,O + Size);

	_Channel *c = GetChannelByName(ChannelName);

	if (!c)return;

	c->PartChannel(tP);
}

void Event_client_userStatsRequest(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size <= 2)return;

	const USHORT Count = al_min(*(USHORT*)&Packet[0],64);

	if ((Count << 2) + 2 > Size)return;

	tP->qLock.lock();

	for (DWORD i = 0; i < Count; i++) {

		const DWORD UID = *(DWORD*)&Packet[2 + (i << 2)];

		tP->addQueNonLocking(USER_STATS(UID, tP->UserID));
	}
	tP->qLock.unlock();

}
void Event_client_changeAction(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size < 12)return;

	size_t O = (size_t)&Packet[0];
	const size_t End = O + Size;

	const byte n_actionID = *(byte*)O; O++;
	const std::string n_ActionText = ReadUleb(O, End);
	const std::string n_CheckSum = REMOVEQUOTES(ReadUleb(O, End));
	if (O + 4 > End)return;
	const DWORD n_Mods = *(DWORD*)O; O += 4;
	if (O + 1 > End)return;
	const byte n_GameMode = *(byte*)O; O++;
	if (O + 4 > End)return;
	const int n_BeatmapID = *(int*)O;

	tP->actionID = n_actionID;
	tP->ActionText = n_ActionText;

	if (n_CheckSum.size() == 32)
		memcpy(tP->ActionMD5, &n_CheckSum[0], 32);

	if(n_actionID != bStatus::sAfk)//Stop relax flickering.
		tP->actionMods = n_Mods;
	tP->GameMode = n_GameMode;
	if(n_BeatmapID)tP->BeatmapID = n_BeatmapID;

	tP->addQue(bPacket::UserStats(tP));

}

#include <fstream>

__forceinline bool FileExistCheck(const std::string &filename) {
	std::ifstream ifs(filename, std::ios::binary | std::ios::ate);
	if (ifs.is_open()) {
		ifs.close();

		return 1;
	}
	return 0;
}




__forceinline bool WriteAllBytes(const std::string &filename, const void* data, const DWORD Size);
__forceinline bool WriteAllBytes(const std::string &filename, const std::string &res);
bool DownloadMapFromOsu(const int ID) {

	if (ID < 0 || ID > 6000000)
		return 0;

	const std::string bFile = GET_WEB_CHUNKED("old.ppy.sh", std::string("osu/" + std::to_string(ID)));

	if (bFile.size() == 0 || bFile.find("[HitObjects]") == std::string::npos)return 0;

	//ReplaceAll(bFile, "\r\n", "\n");//Could save diskspace

	WriteAllBytes(BEATMAP_PATH + std::to_string(ID) + ".osu", (void*)&bFile[0], bFile.size());

	return 1;
}

#include "oppai.h"
#include "pp/pp_base.h"

bool OppaiCheckMapDownload(ezpp_t ez, const DWORD BID) {

	const std::string MapPath = BEATMAP_PATH + std::to_string(BID) + ".osu";

	if (!FileExistCheck(MapPath) && !DownloadMapFromOsu(BID)) {
		printf(KRED "Failed to download %i.osu\n" KRESET, BID);
		WriteAllBytes(MapPath, " ");//Stop it from trying it over and over again.
		return 0;
	}

	int res = ezpp(ez, (char*)MapPath.c_str());

	if (res < 0) {
		printf(KMAG "oppai> " KRED "Failed with errorcode %i\n" KRESET, res);
		return 0;
	}

	return 1;
}

#include "Match.h"


__forceinline bool WriteAllBytes(const std::string &filename, const std::string &res) {

	std::ofstream ifs;
	ifs.open(filename);

	if (!ifs.is_open())return 0;


	ifs.write((char*)&res[0], res.size());
	ifs.close();

	return 1;
}
__forceinline bool WriteAllBytes(const std::string &filename, const void* data, const DWORD Size){

	std::ofstream ifs;
	ifs.open(filename,std::ofstream::binary);

	if (!ifs.is_open())return 0;
	
	ifs.write((char*)data, Size);
	ifs.close();

	return 1;
}

int getSetID_fHash(const std::string &H, _SQLCon* c){//Could combine getbeatmapid and getsetid into one

	if (H.size() != 32)
		return 0;

	if (c){
		sql::ResultSet* res = c->ExecuteQuery("SELECT beatmapset_id FROM beatmaps WHERE beatmap_md5 = '" + H + "' LIMIT 1");

		if (res && res->next()) {
			const int ID = res->getInt(1);
			delete res;
			return ID;
		}

		if (res)
			delete res;
	}

	const std::string BeatmapData = GET_WEB_CHUNKED("old.ppy.sh", osu_API_BEATMAP + "h=" + H);

	if (BeatmapData.size() <= 25)return 0;

	DWORD Off = BeatmapData.find("\"beatmapset_id\"");

	if (Off == std::string::npos)return 0;

	Off += 17;

	std::string t;//TODO: Dont.

	while (BeatmapData[Off] != '"') {
		t.push_back(BeatmapData[Off]);
		Off++;
	}

	//TODO add to database
	return StringToInt32(t);
}


int getBeatmapID_fHash(const std::string &H, _SQLCon* c) {

	if (H.size() != 32)return 0;


	if (c){

		sql::ResultSet* res = c->ExecuteQuery("SELECT beatmap_id FROM beatmaps WHERE beatmap_md5 = '" + H + "' LIMIT 1");

		if (res && res->next()){
			const int ID = res->getInt(1);
			delete res;
			return ID;
		}
		if (res)
			delete res;

	}
	const std::string &BeatmapData = GET_WEB_CHUNKED("old.ppy.sh", osu_API_BEATMAP + "h=" + H);

	if (BeatmapData.size() <= 25)return 0;

	DWORD Off = BeatmapData.find("\"beatmap_id\"");

	if (Off == std::string::npos)return 0;

	Off += 14;

	std::string t;

	while (BeatmapData[Off] != '"') {
		t.push_back(BeatmapData[Off]);
		Off++;
	}

	//TODO add to database

	return StringToInt32(t);
}

#define AddDeci(s,o) if (*(byte*)(s + o) == 0) { *(USHORT*)(s + o - 1) = *(USHORT*)(s + o - 2); *(byte*)(s + o - 2) = '.'; return s;}

std::string RoundTo2(const float Input) {

	char s[16];
	*(uint64_t*)(s) = 0;
	*(uint64_t*)(s + 8) = 0;

	snprintf(s, 16, "%d", int(Input * 100.f));

	return std::string([&]{
		if (s[0] == '0')return s;
		AddDeci(s, 2)
		AddDeci(s, 3)
		AddDeci(s, 4)
		AddDeci(s, 5)
		AddDeci(s, 6)
		AddDeci(s, 7)
		AddDeci(s, 8)
		AddDeci(s, 9)
		AddDeci(s, 10)
		AddDeci(s, 11)
		AddDeci(s, 12)
		AddDeci(s, 13)
		AddDeci(s, 14)
		return s;
	}());
}


float ezpp_NewAcc(ezpp_t ez, const float Acc) {
	ezpp_set_accuracy_percent(ez, Acc);
	calc(ez);
	return ezpp_pp(ez);
}



#include "Aria.h"
#include "Commands.h"

void BotMessaged(_User *tP, const std::string&& Message){
	
	if (Message.size() == 0)return;

	if (Message[0] == '!'){

		if (!MEM_CMP_START(Message, "!with") && !MEM_CMP_START(Message, "!acc")) {

			DWORD Unused;

			const std::string Res = ProcessCommand(tP, std::move(Message), Unused);

			if (Res.size())tP->addQue(bPacket::BotMessage(tP->Username, std::move(Res)));

			return;
		}
	}

	const auto BotMessage = EXPLODE_VEC(std::string, Message, ' ');
	
	if (BotMessage.size() < 2)
		return;

	int mapID = 0;
	int Mods = 0;
	float Acc = 0.f;
	int Combo = 0;

	if (BotMessage.size() >= 5) {

		if (BotMessage[0] == "\x1""ACTION"){

			const DWORD BeatmapOffset = (BotMessage[2] == "listening") ? 4:3;

			const DWORD mSize = BotMessage[BeatmapOffset].size();

			if(BotMessage[BeatmapOffset].find("/s/") != std::string::npos || mSize < 5)//mSize check is just to make it safe.
				return tP->addQue(bPacket::BotMessage(tP->Username, "This appears to be a Beatmapset - Which is not currently supported sorry!"));

			char* Temp = new char[mSize]();

			size_t pos = BotMessage[BeatmapOffset].find_last_of('/');

			if (pos != std::string::npos && pos != mSize - 1)
				memcpy(Temp, &BotMessage[BeatmapOffset][pos + 1], mSize - (pos + 1));

			Temp[(mSize > 0) ? mSize - 1 : 0] = 0;//Just incase there is some mallice.

			mapID = MemToInt32(Temp,strlen(Temp));
			delete[] Temp;
		}

		if (mapID){

			#define MODREAD(s) if(MEM_CMP_OFF(BotMessage[i],#s,1)){ Mods |= s;continue; }

			for (DWORD i = BotMessage.size() - 1; i > 5; i--){

				if (BotMessage[i].size() <= 1)continue;

				MODREAD(DoubleTime);
				MODREAD(Nightcore);
				MODREAD(Hidden);
				MODREAD(HardRock);
				MODREAD(Flashlight);
				MODREAD(SpunOut);
				MODREAD(Easy);
				MODREAD(NoFail);
				MODREAD(HalfTime);
				MODREAD(Relax);

			}

			if (Mods & Nightcore)
				Mods |= DoubleTime;


			#undef MODREAD
		}

	}

	if (!mapID){
		if (BotMessage.size() >= 2){

			if (BotMessage[0] == "!acc")
				return tP->addQue(bPacket::BotMessage(tP->Username, "This is now in !with. Here are some examples of the usage.\n!with HDDT 95\n!with 98.5 HD HR"));

			if (BotMessage[0] == "!with"){

				Mods = 0;
				std::string AllMods;
				for (DWORD i = 1; i < BotMessage.size(); i++){
					AllMods += BotMessage[i];
					if (Acc == 0.f || Combo == 0){
						byte Com = 0;
						std::string tNum;

						for (const char C : BotMessage[i]){
							if ((C >= '0' && C <= '9'))
								tNum.push_back(C);
							else if (C == '.' && tNum.size() != 0 && Com != 2){
								Com = 2;
								tNum.push_back(C);
							}else if ((C == 'x' || C == 'X') && Com != 2)
								Com = 1;
						}

						if (tNum.size()){
							if (Com == 1)Combo = std::stoi(tNum);
							else Acc = std::stof(tNum);
						}
					}
				}

				for (char& C :  AllMods)
					if (C >= 'A' && C <= 'Z')
						C += 'a' - 'A';

				if (AllMods.find("hd") != std::string::npos)
					Mods += Hidden;
				if (AllMods.find("dt") != std::string::npos || BotMessage[1].find("nc") != std::string::npos)
					Mods += DoubleTime;
				if (AllMods.find("fl") != std::string::npos)
					Mods += Flashlight;
				if (AllMods.find("ez") != std::string::npos)
					Mods += Easy;
				if (AllMods.find("ht") != std::string::npos)
					Mods += HalfTime;
				if (AllMods.find("rx") != std::string::npos)
					Mods += Relax;
				if (AllMods.find("so") != std::string::npos)
					Mods += SpunOut;
				if (AllMods.find("hr") != std::string::npos)
					Mods += HardRock;

				mapID = tP->LastSentBeatmap;

				if (!mapID)return;

				goto WITHMODS;
			}
		}
		 return;
	}

WITHMODS:

	/*
	_RawBeatmap s;


	std::chrono::steady_clock::time_point sTime = std::chrono::steady_clock::now();
	
	pp_GetRawMapData(mapID, s);

	const unsigned long long TTime = std::chrono::duration_cast<std::chrono::nanoseconds> (std::chrono::steady_clock::now() - sTime).count();
	printf("Time: %f\n%i\n", double(double(TTime) * .000001),s.Notes.size());
	*/
	
	ezpp_t ez = ezpp_new();

	if (!ez)return;

	tP->addQue(bPacket::BotMessage(tP->Username, [&]()->std::string{
		ezpp_set_mods(ez, Mods);
		ezpp_set_accuracy_percent(ez, (Acc == 0.f) ? 95.f : Acc);

		if (Combo)ezpp_set_combo(ez, Combo);

		if (!OppaiCheckMapDownload(ez, mapID))
			return "Sorry. I failed to get that map.";

		tP->LastSentBeatmap = mapID;

		const float PP = ezpp_pp(ez);

		if (Acc != 0.f || Combo != 0)
			return RoundTo2(PP) + " pp";

		const float PPValues[3] = { ezpp_NewAcc(ez,98.f),ezpp_NewAcc(ez,99.f),ezpp_NewAcc(ez,100.f) };

		return "95%: " + RoundTo2(PP) + " pp\n98%: "
			+ RoundTo2(PPValues[0]) + " pp\n99%: " + RoundTo2(PPValues[1]) + " pp\n100%: "
			+ RoundTo2(PPValues[2]) + " pp";
	}()));

	ezpp_free(ez);
}

void Event_client_sendPrivateMessage(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size < 7 || tP->isSilenced() || !(tP->privileges & Privileges::UserPublic))
		return;

	size_t O = (size_t)&Packet[0];
	const size_t End = O + Size;

	SkipUleb(O, End);//Skip sender. It is useless

	const std::string Message = ReadUleb(O, End);
	const std::string Target = ReadUleb(O, End);

	if (O + 4 > End)return;
	const int ID = *(int*)O;

	if (Message.size() == 0)return;

	if (Target == BOT_NAME)
		return BotMessaged(tP,std::move(Message));
	_UserRef u(GetUserFromName(Target),1);

	if (unlikely(!u))
		return tP->addQue(bPacket4Byte(OPac::server_userLogout, ID));
	
	if (u->isBlocked(tP->UserID))
		return;

	if(u->FriendsOnlyChat && !u->isFriend(tP->UserID))
		tP->addQue([&] {//hmm yes im peppy this is a great system!!1m!1! I AM GEN I US PEPPPYYY
		auto b = bPacket::Message(tP->Username, u->Username, "", tP->UserID);
		b.Type = OPac::server_userPMBlocked;
		return b;
		}());
	else
		u->addQue(bPacket::Message(tP->Username, std::move(Target), std::move(Message), tP->UserID));
}

void Event_client_sendPublicMessage(_User *tP, const byte* const Packet, const DWORD Size) {

	if (Size < 7 || tP->isSilenced())return;

	size_t O = (size_t)&Packet[0];
	const size_t End = O + Size;

	SkipUleb(O, End);//Skip sender. It is useless

	const std::string Message = [&]{
		std::string Why_can_MSVC_compile_and_work_fine_with_no_locals_but_GCC_eats_massive_dog_shit__Thanks_GCC = ReadUleb(O, End);
		return TRIMSTRING(Why_can_MSVC_compile_and_work_fine_with_no_locals_but_GCC_eats_massive_dog_shit__Thanks_GCC);
	}();

	const std::string Target = ReadUleb(O, End);

	//if (O + 4 > End)return;
	//const int ID = *(int*)O;

	if (Message.size() == 0 || Target == "#highlight" || Target == "#userlog")
		return;

	_Channel *c = 0;
	
	if (Target == "#multiplayer"){
		const USHORT MultiID = tP->CurrentMatchID;
		if (MultiID){
			_Match *const m = getMatchFromID(MultiID);
			if (m){
				DWORD notVisible = 0;
				const std::string s = ProcessCommandMultiPlayer(tP, Message, notVisible, m);

				if (s.size() == 0){
					m->Lock.lock();
					m->sendUpdate(bPacket::Message(tP->Username, std::move(Target), std::move(Message), tP->UserID), tP);
					m->Lock.unlock();
				}else{

					if(notVisible)
						tP->addQue(bPacket::BotMessage("#multiplayer", s));
					else{
						m->Lock.lock();
						m->sendUpdate(bPacket::BotMessage("#multiplayer", s), 0);
						m->Lock.unlock();
					}
				}
			}
		}
		return;
	}else if ((tP->CurrentlySpectating || tP->Spectators.size()) && Target == "#spectator"){

		_User *SpecHost = (tP->Spectators.size()) ? tP : tP->CurrentlySpectating;

		if (SpecHost){

			const _BanchoPacket b = bPacket::Message(tP->Username, Target, Message, tP->UserID);

			SpecHost->SpecLock.lock();

			for (_User *const s : SpecHost->Spectators)
				if (s && s != tP)
					s->addQue(b);

			SpecHost->SpecLock.unlock();

			if (SpecHost != tP)
				SpecHost->addQue(b);
		}

		return;
	}else c = GetChannelByName(Target);

	if (!c){
		printf("Failed to find channel with the name %s\n",Target.c_str());
		tP->addQue(bPacket::GenericString(OPac::server_channelKicked, std::move(Target)));
		return;
	}

	if (Message[0] == '!'){

		DWORD notVisible = 0;
		const std::string Res = ProcessCommand(tP, std::move(Message), notVisible);

		if (!(tP->privileges & Privileges::UserPublic))
			notVisible = 1;

		if (Res.size()){
			if (notVisible)
				tP->addQue(bPacket::BotMessage(c->ChannelName, std::move(Res)));
			else
				c->Bot_SendMessage(std::move(Res));
		}

		return;
	}

	if (tP->privileges & Privileges::UserPublic)
		c->SendPublicMessage(tP, bPacket::Message(tP->Username, std::move(Target), std::move(Message), tP->UserID));
}

void Event_client_startSpectating(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size < 4)return;

	const DWORD ID = *(DWORD*)&Packet[0];

	if (ID < 1000)	
		return tP->addQue(bPacket::Notification("What are you doing spectating bots?"));
	

	_UserRef SpecTarget(GetUserFromID(ID),1);

	if (!SpecTarget || tP == SpecTarget.User){
		tP->addQue(bPacket::Notification("Failed to find user."));
		return;
	}

	bool Add = (tP->CurrentlySpectating != SpecTarget.User);

	tP->CurrentlySpectating = SpecTarget.User;

	tP->addQue(bPacket::GenericString(OPac::server_channelJoinSuccess,"#spectator"));

	const _BanchoPacket b = bPacket4Byte(OPac::server_fellowSpectatorJoined, tP->UserID);
	
	SpecTarget->SpecLock.lock();

	if(SpecTarget->Spectators.size() == 0)
		SpecTarget->addQue(bPacket::GenericString(OPac::server_channelJoinSuccess, "#spectator"));

	for (auto& fSpec : SpecTarget->Spectators){

		if (!fSpec) {
			if(Add)fSpec = tP;
			Add = 0;
			continue;
		}

		if (fSpec != tP){
			fSpec->addQue(b);
			tP->addQue(bPacket4Byte(OPac::server_fellowSpectatorJoined, fSpec->UserID));
		}else Add = 0;

	}

	if (Add)
		SpecTarget->Spectators.push_back(tP);
	
	SpecTarget->SpecLock.unlock();

	SpecTarget->qLock.lock();

	SpecTarget->addQueNonLocking(bPacket::UserPanel(tP));
	//SpecTarget->addQueNonLocking(bPacket::UserStats(tP));
	SpecTarget->addQueNonLocking(bPacket4Byte(OPac::server_spectatorJoined, tP->UserID));

	SpecTarget->qLock.unlock();

}


struct _ReplayFrame {
	int time;
	float x, y;
	byte ButtonState;
	byte bt;
};

void Event_client_spectateFrames(_User *tP, const byte* const Packet, const DWORD Size){

	if (tP->Spectators.size() == 0)return;

	const _BanchoPacket b = bPacket::RawData(OPac::server_spectateFrames, Packet, Size);
	const _BanchoPacket u = bPacket::UserStats(tP);

	tP->SpecLock.lock();
	for (_User *s :  tP->Spectators){

		if (!s)continue;

		s->qLock.lock();

		s->addQueNonLocking(u);
		s->addQueNonLocking(b);

		s->qLock.unlock();
	}
	tP->SpecLock.unlock();
}

__forceinline void ReadMatchData(_Match *m, const byte* const Packet,const DWORD Size, bool Safe = 0){

	size_t O = (size_t)&Packet[0];
	const size_t End = O + Size;

	/*m->MatchId = *(USHORT*)O; O += 2;*/
	/*m->inProgress = *(byte*)O; O++;*/

	O += 3;

	if (O + 1 > End)return;
	m->Settings.MatchType = *(byte*)O; O++;
	if (O + 4 > End)return;
	m->Settings.Mods = *(DWORD*)O; O += 4;
	m->Settings.Name = ReadUleb(O,End);
	if (!Safe){
		m->Settings.Password = ReadUleb(O,End);
		ReplaceAll(m->Settings.Password," ","_");
	}
	else ReadUleb(O,End);
	m->Settings.BeatmapName = ReadUleb(O,End);
	if (O + 4 > End)return;
	m->Settings.BeatmapID = *(DWORD*)O; O += 4;
	m->Settings.BeatmapChecksum = ReadUleb(O,End);

	byte tSlotStatus[NORMALMATCH_MAX_COUNT];
	byte tSlotTeam[NORMALMATCH_MAX_COUNT];
	if (O + NORMALMATCH_MAX_COUNT > End)return;
	if (!Safe)memcpy(tSlotStatus, (void*)O, NORMALMATCH_MAX_COUNT); O += NORMALMATCH_MAX_COUNT;
	if (O + NORMALMATCH_MAX_COUNT > End)return;
	if (!Safe)memcpy(tSlotTeam, (void*)O, NORMALMATCH_MAX_COUNT); O += NORMALMATCH_MAX_COUNT;
	if (!Safe)m->HostID = *(DWORD*)O; O += 4;
	
	if (!Safe){
		for (DWORD i = 0; i < NORMALMATCH_MAX_COUNT; i++) {
			m->Slot[i].SlotStatus = tSlotStatus[i];
			m->Slot[i].SlotTeam = tSlotTeam[i];
		}
	}

	for (DWORD i = 0; i < NORMALMATCH_MAX_COUNT; i++)
		if (m->Slot[i].SlotStatus & SlotStatus::HasPlayer)
			O += 4;
	
	if (O + 4 > End)return;

	m->Settings.PlayMode = *(byte*)O; O++;
	m->Settings.ScoringType = *(byte*)O; O++;
	m->Settings.TeamType = *(byte*)O; O++;
	m->Settings.FreeMod = *(byte*)O; O++;

	if (m->Settings.FreeMod){
		if (O + (NORMALMATCH_MAX_COUNT * 4) > End)return;
		int tCurrentMods[NORMALMATCH_MAX_COUNT];
		memcpy(tCurrentMods, (void*)O, NORMALMATCH_MAX_COUNT * 4);

		for (DWORD i = 0; i < NORMALMATCH_MAX_COUNT; i++)
			m->Slot[i].CurrentMods = tCurrentMods[i];		

		O += NORMALMATCH_MAX_COUNT * 4;
	}
	if (O + 4 > End)return;
	m->Seed = *(DWORD*)O;
}

void Event_client_createMatch(_User *tP, const byte* const Packet, const DWORD Size){

	if (tP->CurrentMatchID || !(tP->privileges & UserPublic))//already in a match? Might want to kick them from the old one.
		return tP->addQue(_BanchoPacket(OPac::server_matchJoinFail));


	_Match *const m = getEmptyMatch();

	if(unlikely(!m))
		return tP->addQue(_BanchoPacket(OPac::server_matchJoinFail));

	tP->inLobby = 0;

	ReadMatchData(m, Packet,Size);

	m->HostID = tP->UserID;
	m->inProgress = 0;
	m->PlayersLoading = 0;
	m->Settings.Mods = 0;
	m->PlayerCount = 1;
	m->Slot[0].SlotStatus = SlotStatus::NotReady;
	m->Slot[0].User = tP;
	tP->CurrentMatchID = m->MatchId;
	m->Tournament = 0;


	tP->qLock.lock();
	tP->addQueNonLocking(bPacket::GenericString(OPac::server_channelJoinSuccess,"#multiplayer"));
	tP->addQueNonLocking(bPacket::bMatch(OPac::server_matchJoinSuccess,m,1));
	tP->qLock.unlock();
}

__forceinline void SendMatchList(_User *tP, const bool New) {

	if(!tP->inLobby)return;
	
	for (DWORD i = 0; i < MAX_MULTI_COUNT; i++){

		if (Match[i].PlayerCount && !Match[i].Tournament)
			if (Match[i].LobbyCache.Type == 0) {//TODO might want to improve this. Could cause pipeline issues.
				Match[i].Lock.lock();
				tP->addQue(bPacket::bMatch((New) ? OPac::server_newMatch : OPac::server_updateMatch, &Match[i], 0));
				Match[i].Lock.unlock();
			} else tP->addQue(Match[i].LobbyCache);
	}
}

void Event_client_partMatch(_User *tP){
	if (!tP->CurrentMatchID)return;
	_Match *m = getMatchFromID(tP->CurrentMatchID);
	if (!m)return;
	m->Lock.lock();
	m->removeUser(tP, 0);
	m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));
	m->Lock.unlock();
}

void Event_client_matchChangeSlot(_User *const tP, const byte* const Packet, const DWORD Size) {
	
	if (!tP->CurrentMatchID || Size < 4)return;

	DWORD NewSlot = *(DWORD*)&Packet[0];

	if (NewSlot >= 16)
		NewSlot = 15;

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;
	
	m->Lock.lock();

	DWORD OldSlot = 16;

	for (DWORD i = 0; i < 16; i++) {

		if (m->Slot[i].User == tP) {
			OldSlot = i;
			break;
		}
	}
	
	if (OldSlot != 16 && OldSlot != NewSlot && !(m->Slot[NewSlot].SlotStatus & SlotStatus::Locked) && !(m->Slot[OldSlot].SlotStatus & SlotStatus::Ready) && !m->Slot[NewSlot].User){
		m->Slot[NewSlot] = m->Slot[OldSlot];
		m->Slot[OldSlot] = _Slot();
		m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));
	}

	m->Lock.unlock();

}

void Event_client_joinLobby(_User *tP){

	_Match *const m = getMatchFromID(tP->CurrentMatchID);

	if (m){
		m->Lock.lock();
		m->removeUser(tP, 0);
		m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));//tell the other people that they left.
		m->Lock.unlock();
	}

	tP->inLobby = 1;
}

void Event_client_matchChangeSettings(_User *tP, const byte* const Packet, const DWORD Size){

	if (!tP->CurrentMatchID)return;

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	if (m->HostID != tP->UserID){//Non host trying to change settings
		m->Lock.unlock();
		return;
	}

	const byte PreviousFree = m->Settings.FreeMod;
	const int PreviousBeatmapID = m->Settings.BeatmapID;
	const int PreviousMods = m->Settings.Mods;

	const byte pMatchType = m->Settings.MatchType;
	const byte pScoringType = m->Settings.ScoringType;
	const byte pTeamType = m->Settings.TeamType;

	ReadMatchData(m, Packet,Size, 1);

	const bool unReadyUsers = (PreviousMods != m->Settings.Mods || pMatchType != m->Settings.MatchType || pScoringType != m->Settings.ScoringType ||
						pTeamType != m->Settings.TeamType || PreviousFree != m->Settings.FreeMod || PreviousBeatmapID != m->Settings.BeatmapID);

	if (PreviousFree != m->Settings.FreeMod){

		const DWORD TimeMods = m->Settings.Mods & TimeAltering;
		const DWORD NonTimeMods = m->Settings.Mods - TimeMods;

		if (m->Settings.FreeMod){
			for (DWORD i = 0; i < 16; i++){
				if (m->Slot[i].User)m->Slot[i].CurrentMods = NonTimeMods;
				else m->Slot[i].CurrentMods = 0;
			}
			m->Settings.Mods = TimeMods;
		}
		else {
			for (DWORD i = 0; i < 16; i++) {
				if (m->Slot[i].User == tP)
					m->Settings.Mods = m->Slot[i].CurrentMods + TimeMods;
				
				m->Slot[i].CurrentMods = 0;
			}
		}
	}

	if (PreviousBeatmapID != m->Settings.BeatmapID) {

		if (m->Settings.BeatmapID != -1){

			m->sendUpdate(bPacket::BotMessage("#multiplayer",
				"\nDirect is still being worked on\n(Akatsuki)[https://akatsuki.pw/d/" + std::to_string(m->Settings.BeatmapID) + "]   (Bloodcat)[https://bloodcat.com/osu?q=" + std::to_string(m->Settings.BeatmapID) + "]\n"
				,FAKEUSER_NAME));
		}
	}

	if (unReadyUsers){
		m->ClearPlaying();
		m->UnreadyUsers();
	}

	m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));

	m->Lock.unlock();
}

void Event_client_matchLock(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size != 4)return;

	const DWORD SlotID = *(DWORD*)&Packet[0];

	if (SlotID >= 16)return;

	if (!tP->CurrentMatchID)return;
	
	_Match *m = getMatchFromID(tP->CurrentMatchID);
	if (!m)return;

	m->Lock.lock();

	if (m->HostID != tP->UserID){//Non host trying to change settings
		m->Lock.unlock();
		return;
	}

	if (m->Slot[SlotID].SlotStatus & SlotStatus::HasPlayer) {
		if(m->Slot[SlotID].User != tP)
			m->removeUser(m->Slot[SlotID].User, 1);
	}else m->Slot[SlotID].SlotStatus = (m->Slot[SlotID].SlotStatus & SlotStatus::Open) ? SlotStatus::Locked : SlotStatus::Open;

	m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));

	m->Lock.unlock();
}

void Event_client_matchChangeMods(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size != 4)return;

	if (!tP->CurrentMatchID)return;

	_Match *m = getMatchFromID(tP->CurrentMatchID);
	if (!m)return;

	DWORD Mods = *(DWORD*)&Packet[0];

	m->Lock.lock();

	const bool isHost = (m->HostID == tP->UserID);

	if (!m->Settings.FreeMod) {

		if (!isHost){
			m->Lock.unlock();
			return;
		}

		m->Settings.Mods = Mods;
	}else{

		int SlotID = -1;

		for (int i = 0; i < NORMALMATCH_MAX_COUNT; i++){
			if (m->Slot[i].User == tP) {
				SlotID = i;
				break;
			}
		}

		if (SlotID != -1){

			if(isHost)
				m->Settings.Mods = Mods & TimeAltering;

			Mods -= Mods & TimeAltering;
			m->Slot[SlotID].CurrentMods = Mods;
		}
	}

	m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));
	m->Lock.unlock();
}

void Event_client_joinMatch(_User *tP, const byte* const Packet, const DWORD Size) {


	if(!(tP->privileges & UserPublic))
		return tP->addQue(_BanchoPacket(OPac::server_matchJoinFail));

	size_t O = (size_t)&Packet[0];
	const size_t End = O + Size;
	
	if (O + 4 > End)return;

	const USHORT MatchID = USHORT(*(DWORD*)O); O += 4;
	const std::string Password = ReadUleb(O,End);

	/*if (!MatchID){//Clickable menu hack

		if (Password.size() == 0 || !tP->Menu.State)
			return tP->addQue(_BanchoPacket(OPac::server_matchJoinFail));;
		
		auto menuCommands = Explode(Password, '|');

		bool Auth = 0;


		for (DWORD i = 0; i < menuCommands.size(); i++) {

			if(menuCommands[i] == "next")
				tP->Menu.ChangePage = 1;
			else if (menuCommands[i] == "back") {
				tP->Menu.ChangePage = -1;
			}
			else if (menuCommands[i] == "exit") {
				tP->Menu.State = 0;
				tP->Menu.ChangePage = 0;
			}
			else if (StringCompareStart(menuCommands[i], "iaux1=")) {
				auto s = Explode(menuCommands[i], '=');
				if (s.size() == 2)tP->Menu.aux1 = Safe_atoi(s[1].c_str());
			}
			else if (StringCompareStart(menuCommands[i], "saux1=")) {
				auto s = Explode(menuCommands[i], '=');
				if (s.size() == 2)tP->Menu.saux1 = s[1];
			}

		}
		tP->Menu.ForceReDraw = 1;

		return tP->addQue(_BanchoPacket(OPac::server_matchJoinFail));;
	}*/
	
	_Match* m = getMatchFromID(tP->CurrentMatchID);
	
	if (m) {
		m->Lock.lock();
		m->removeUser(tP, 0);
		m->Lock.unlock();
	}

	m = getMatchFromID(MatchID);

	bool Failed = 1;

	if (m){

		m->Lock.lock();

		if (m->Settings.Password.size() == 0 || m->Settings.Password == Password && m->PlayerCount){//Dont let players join empty matchs.

			for (DWORD i = 0; i < 16; i++){

				if (m->Slot[i].SlotStatus == SlotStatus::Open && !m->Slot[i].User){

					m->Slot[i].User = tP;
					m->Slot[i].SlotStatus = SlotStatus::NotReady;
					m->Slot[i].CurrentMods = 0;
					m->Slot[i].Completed = 0;
					m->Slot[i].Failed = 0;
					m->Slot[i].Loaded = 0;
					m->Slot[i].Skipped = 0;

					tP->qLock.lock();

					tP->CurrentMatchID = m->MatchId;

					tP->addQueNonLocking(bPacket::GenericString(OPac::server_channelJoinSuccess, "#multiplayer"));
					tP->addQueNonLocking(bPacket::bMatch(OPac::server_matchJoinSuccess, m, 1));

					tP->qLock.unlock();

					m->PlayerCount++;

					m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1),tP);
					Failed = 0;
					break;
				}
			}
		}	
		m->Lock.unlock();
	}
	else tP->addQueNonLocking(bPacket4Byte(OPac::server_disposeMatch, MatchID));// could be a disbanded match - send this to clear it out.
	
	if (Failed)
		tP->addQue(_BanchoPacket(OPac::server_matchJoinFail));
	else tP->inLobby = 0;
}

void Event_client_matchChangeTeam(_User *tP) {

	if (!tP->CurrentMatchID)return;
	
	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	for (DWORD i = 0; i < 16; i++) {

		if (m->Slot[i].User == tP) {
			m->Slot[i].SlotTeam = !m->Slot[i].SlotTeam;
			break;
		}
	}

	m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));

	m->Lock.unlock();
}

void Event_client_matchNoBeatmap(_User *tP) {

	if (!tP->CurrentMatchID)return;

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	for (DWORD i = 0; i < 16; i++){
		if (m->Slot[i].User == tP){
			m->Slot[i].SlotStatus = SlotStatus::NoMap;
			m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));
			break;
		}
	}

	m->Lock.unlock();
}

void Event_client_matchHasBeatmap(_User *tP){

	if (!tP->CurrentMatchID)return;

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	for (DWORD i = 0; i < 16; i++){
		if (m->Slot[i].User == tP){
			if (m->Slot[i].SlotStatus = SlotStatus::NoMap) {
				m->Slot[i].SlotStatus = SlotStatus::NotReady;
				m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));
			}break;
		}
	}

	

	m->Lock.unlock();
}

void Event_client_matchTransferHost(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size != 4)return;

	const DWORD SlotID = *(DWORD*)&Packet[0];

	if (SlotID >= 16)return;

	if (!tP->CurrentMatchID)return;

	_Match *m = getMatchFromID(tP->CurrentMatchID);
	if (!m)return;

	m->Lock.lock();

	if (m->HostID != tP->UserID || !m->Slot[SlotID].User|| !m->Slot[SlotID].User->choToken) {//Non host trying to set the host..
		m->Lock.unlock();
		return;
	}

	m->HostID = m->Slot[SlotID].User->UserID;

	m->Slot[SlotID].User->addQue(_BanchoPacket(OPac::server_matchTransferHost));

	m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));

	m->Lock.unlock();
}

void Event_client_matchReady(_User *tP) {

	if (!tP->CurrentMatchID)return;//not in a match currently

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	for (DWORD i = 0; i < 16; i++) {

		if (m->Slot[i].User == tP) {

			m->Slot[i].SlotStatus = SlotStatus::Ready;

			break;
		}
	}

	m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));

	m->Lock.unlock();
}

void Event_client_matchNotReady(_User *tP){

	if (!tP->CurrentMatchID)return;//not in a match currently

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	for (DWORD i = 0; i < 16; i++) {

		if (m->Slot[i].User == tP) {

			m->Slot[i].SlotStatus = SlotStatus::NotReady;

			break;
		}
	}

	m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));

	m->Lock.unlock();
}

void Event_client_matchStart(_User *tP) {

	if (!tP->CurrentMatchID)return;//not in a match currently

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	if (m->HostID != tP->UserID || m->Settings.BeatmapID == -1) {
		m->Lock.unlock();
		return;
	}
	
	m->ClearPlaying();

	for (DWORD i = 0; i < 16; i++){

		if (m->Slot[i].SlotStatus == SlotStatus::Ready || m->Slot[i].SlotStatus == SlotStatus::NotReady) {
			m->Slot[i].SlotStatus = SlotStatus::Playing;
			m->Slot[i].Loaded = 0;
			m->Slot[i].Failed = 0;
			m->Slot[i].Skipped = 0;
			m->Slot[i].Completed = 0;
		}
	}

	m->sendUpdate(bPacket::bMatch(OPac::server_matchStart, m, 1));

	m->Lock.unlock();
}

void Event_client_matchLoadComplete(_User *tP) {

	if (!tP->CurrentMatchID)return;//not in a match currently

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	for (DWORD i = 0; i < 16; i++){

		if (m->Slot[i].User == tP){

			m->Slot[i].Loaded = 1;
			break;
		}
	}

	bool AllLoaded = 1;

	for (DWORD i = 0; i < 16; i++) {
		if (m->Slot[i].SlotStatus == SlotStatus::Playing && m->Slot[i].Loaded == 0){
			AllLoaded = 0;
			break;
		}
	}

	if (AllLoaded)
		m->sendUpdates({ _BanchoPacket(OPac::server_matchAllPlayersLoaded),bPacket::bMatch(OPac::server_updateMatch, m, 1) });

	m->Lock.unlock();
}

void Event_client_matchScoreUpdate(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size < 10)return;
	if (!tP->CurrentMatchID)return;//not in a match currently

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	_BanchoPacket b(OPac::server_matchScoreUpdate);
	AddMem(b.Data, Packet, Size);

	m->Lock.lock();

	byte Slot = 0;

	for (byte i = 0; i < 16; i++){
		if (m->Slot[i].User == tP){
			Slot = i;
			break;
		}
	}
	
	b.Data[4] = Slot;

	m->sendUpdate(b);

	m->Lock.unlock();
}

void Event_client_matchComplete(_User *tP) {

	if (!tP->CurrentMatchID)return;//not in a match currently

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	for (DWORD i = 0; i < 16; i++){
		if (m->Slot[i].User == tP){
			m->Slot[i].Completed = 1;
		}
	}

	bool AllFinished = 1;

	for (DWORD i = 0; i < 16; i++) {
		if (m->Slot[i].SlotStatus == SlotStatus::Playing && m->Slot[i].Loaded == 0){
			AllFinished = 0;
			break;
		}
	}

	if (AllFinished){

		m->ClearPlaying();

		m->sendUpdates({
			_BanchoPacket(OPac::server_matchComplete),
			bPacket::bMatch(OPac::server_updateMatch, m, 1)
		});
	}

	m->Lock.unlock();
}

void Event_client_matchFailed(_User *tP) {

	if (!tP->CurrentMatchID)return;//not in a match currently

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;

	m->Lock.lock();

	for (DWORD i = 0; i < 16; i++){
		if (m->Slot[i].User == tP){
			m->sendUpdate(bPacket4Byte(OPac::server_matchPlayerFailed,i));
			break;
		}
	}	

	m->Lock.unlock();
}

void Event_client_matchSkipRequest(_User* tP) {
	const USHORT MID = tP->CurrentMatchID;
	if (!MID)return;//not in a match currently

	_Match *m = getMatchFromID(MID);
	if (!m)return;

	m->Lock.lock();

	for (DWORD i = 0; i < 16; i++){
		if (m->Slot[i].User == tP){
			m->Slot[i].Skipped = 1;
			m->sendUpdate(bPacket4Byte(OPac::server_matchPlayerSkipped, i));
			break;
		}
	}

	bool AllPlayersSkipped = 1;

	for (DWORD i = 0; i < 16; i++){
		if (m->Slot[i].SlotStatus == SlotStatus::Playing && !m->Slot[i].Skipped) {
			AllPlayersSkipped = 0;
			break;
		}
	}

	if(AllPlayersSkipped)
		m->sendUpdate(_BanchoPacket(OPac::server_matchSkip));

	m->Lock.unlock();
}

void Event_client_invite(_User *tP, const byte* const Packet, const DWORD Size){

	if (Size != 4)
		return;

	_Match *m = getMatchFromID(tP->CurrentMatchID);

	if (!m)return;//not in a match currently

	const DWORD TID = *(DWORD*)&Packet[0];

	if (TID < 1000)
		return tP->addQue(bPacket::BotMessage("#multiplayer", "Why would a bot want to join your match? You dirty shaved monkey."));;

	_UserRef Target(GetUserFromID(TID),1);

	if (!Target)
		return tP->addQue(bPacket::BotMessage("#multiplayer", "Could not find player."));
	

	tP->addQue(bPacket::BotMessage("#multiplayer", "Invited " + Target->Username + " to your match."));


	if (Target->isBlocked(tP->UserID))
		return;

	_BanchoPacket b = bPacket::Message(tP->Username, Target->Username,"I have invited you to the multiplayer lobby \"[osump://" + std::to_string(m->MatchId) + "/" + m->Settings.Password +" " + m->Settings.Name + "]\".",tP->UserID);
	//Users could fuck with the client [] url construction but its not dangerous in anyway so who cares.

	b.Type = OPac::server_invite;

	Target->addQue(b);
}

void Event_client_friendAdd(_User *tP, const byte* const Packet, const DWORD Size) {

	if (Size != 4)return;

	const DWORD ID = *(DWORD*)Packet;

	enum { ListFull, Added, AlreadyIn };

	char Status = ListFull;

	for (USHORT i = 0; i < 256; i++){
		if (tP->Friends[i] == ID){
			Status = AlreadyIn;
			break;
		}
		if (!tP->Friends[i]){
			Status = Added;
			tP->Friends[i] = ID;
			break;
		}
	}
	if (Status == ListFull)
		tP->addQue(bPacket::Notification("You may only have a maximum of 256 friends."));
	else if (Status == Added)
		SQLExecQue.AddQue("INSERT INTO users_relationships (user1, user2) VALUES (" + std::to_string(tP->UserID) + ", " + std::to_string(ID) + ")");

}

void Event_client_friendRemove(_User *tP, const byte* const Packet, const DWORD Size) {

	if (Size != 4)return;

	const DWORD ID = *(DWORD*)Packet;

	enum { NotRemoved, Removed};

	char Status = NotRemoved;

	for (USHORT i = 0; i < 256; i++) {
		if (tP->Friends[i] == ID){
			tP->Friends[i] = 0;
			Status = Removed;
			break;
		}
	}
	
	if (Status == Removed)
		SQLExecQue.AddQue("DELETE FROM users_relationships WHERE user1 = " + std::to_string(tP->UserID) + " AND user2 = " + std::to_string(ID));
	
}



__forceinline void debug_LogOutUser(_User *tP){

	const DWORD UID = tP->UserID;

	DisconnectUser(tP);

	if (!UID)return;

	const _BanchoPacket b = bPacket4Byte(OPac::server_userLogout, UID);


	for (auto& User : Users)
		if (User.choToken)
			User.addQue(b);
}

/*
void IngameMenu(_User* u, _Con s){

	if (!u->Menu.State || !u->choToken)return;

	std::string Res;

	if (u->Menu.State == MenuStates::Menu_ChooseScore) {


		if (u->Menu.aux1) {
			const int ID = u->Menu.aux1;
			std::string bMD5 = u->Menu.saux1;
			u->Menu.aux1 = 0;
			u->Menu.saux1.clear();

			PrepareSQLString(bMD5);

			SQL_BanchoThread[s.ID].ExecuteUPDATE("UPDATE scores SET completed = 2 WHERE userid = " + std::to_string(u->UserID) + " AND beatmap_md5 = '" + bMD5 + "' AND completed = 3 LIMIT 1");//TODO see if i can just slap a ; and do two in one
			SQL_BanchoThread[s.ID].ExecuteUPDATE("UPDATE scores SET completed = 3 WHERE id = " + std::to_string(ID) + " AND userid = " + std::to_string(u->UserID) + " LIMIT 1");

		}

		DWORD BID = u->BeatmapID;

		if (BID && (u->Menu.ForceReDraw || BID != u->Menu.PreviousMap)) {
			//TODO add relax
			const std::string bMD5 = std::string(u->ActionMD5, 32);

			sql::ResultSet *res = SQL_BanchoThread[s.ID].ExecuteQuery("SELECT id,score,max_combo,mods,accuracy,pp,completed FROM scores WHERE userid = "
				+ std::to_string(u->UserID) + " AND beatmap_md5 = '" + bMD5 + "' AND completed = 2 ORDER BY pp DESC");

			DWORD Count = 0;
			Res += "This will also affect your total pp.\n";

			while (res && res->next()) {
				if (Count > 8)break;
				
				Res += MenuClickButton("iaux1=" + res->getString(1) + "|saux1=" + bMD5, "[Set as Top]");

				Res += "   Score: " + res->getString(2) + " | Acc: " + RoundTo2(res->getDouble(5)) + " | pp: " + RoundTo2(res->getDouble(6)) + "\n";

				Count++;
			}
			delete res;
			u->Menu.PreviousMap = BID;

			if (Count == 0)
				Res += "You do not appear to have any scores on this map\n";

			Res += MenuClickButton("exit", "Exit Menu");
		}
	}
	if (u->Menu.ForceReDraw)Res += " ";
	u->Menu.ForceReDraw = 0;
	if (Res.size()){
		if (!u->Menu.BanchoLoaded) {
			u->Menu.BanchoLoaded = 1;
			u->addQueNonLocking(bPacket::UserPanel(998, 0));
			u->addQueNonLocking(bPacket::UserStats(998, 0));
		}else u->addQue(bPacket::GenericInt32(94, 998));

		u->addQueDelay(_DelayedBanchoPacket(1, bPacket::BotMessage(u->Username, Res,FAKEUSER_NAME, 998)));
	}

}*/

void Event_client_requestStatusUpdate(_User *const tP){
	tP->addQue(bPacket::UserStats(tP));
}

void DoBanchoPacket(_Con s,const uint64_t choToken,const std::vector<byte> &PacketBundle){

	_UserRef tP(GetUserFromToken(choToken),1);

	if (!tP){//No user online with that token

		s.SendData(ConstructResponse(200, Empty_Headers, bPacket4Byte(OPac::server_restart,1).GetBytes()));
		//printf("Request relogin\n");
		return;
	}

	tP->LastPacketTime = clock_ms();

	DWORD In = 0;

	while (In <= PacketBundle.size() - 7){

		const USHORT PacketID = *(USHORT*)&PacketBundle[In];
		const DWORD PacketSize = *(DWORD*)&PacketBundle[In + 3];

		In += 7;

		if (In + PacketSize > PacketBundle.size()) {
			printf("%s> Out of range packet %i|%i|%llu\n", tP->Username.c_str(), PacketID, (In + PacketSize), PacketBundle.size());
			//tP->doQue(s);
			return;
		}

		const byte* const Packet = (byte*)&PacketBundle[In];
		In += PacketSize;

		switch (PacketID){
			
		case 68://Client asking if certain beatmaps are ranked.
		case 79://Client asking for stats updates. ruri does all this automatically so its useless :)
		case OPac::client_pong:
			break;

		case OPac::client_requestStatusUpdate:
			Event_client_requestStatusUpdate(tP.User);
			break;

		case OPac::client_changeAction:
			Event_client_changeAction(tP.User, Packet, PacketSize);
			break;

		case OPac::client_userStatsRequest:
			Event_client_userStatsRequest(tP.User, Packet, PacketSize);
			break;

		case OPac::client_channelJoin:
			Event_client_channelJoin(tP.User, Packet, PacketSize);
			break;

		case OPac::client_channelPart:
			Event_client_channelPart(tP.User, Packet, PacketSize);
			break;

		case OPac::client_sendPublicMessage:
			Event_client_sendPublicMessage(tP.User, Packet, PacketSize);
			break;

		case OPac::client_sendPrivateMessage:
			Event_client_sendPrivateMessage(tP.User, Packet, PacketSize);
			break;

		case OPac::client_logout:
			if (tP->LoginTime + 5000 > tP.User->LastPacketTime)break;
			debug_LogOutUser(tP.User);
			break;

		case OPac::client_startSpectating:
			Event_client_startSpectating(tP.User, Packet, PacketSize);
			break;

		case OPac::client_stopSpectating:
			Event_client_stopSpectating(tP.User);
			break;
		case OPac::client_cantSpectate:
			Event_client_cantSpectate(tP.User);
			break;

		case OPac::client_spectateFrames:
			Event_client_spectateFrames(tP.User,Packet,PacketSize);
			break;

		case OPac::client_createMatch:
			Event_client_createMatch(tP.User, Packet, PacketSize);
			break;

		case OPac::client_partMatch:
			Event_client_partMatch(tP.User);
			break;

		case OPac::client_matchChangeSlot:
			Event_client_matchChangeSlot(tP.User,Packet, PacketSize);
			break;

		case OPac::client_joinLobby:
			Event_client_joinLobby(tP.User);
			break;

		case OPac::client_partLobby:
			tP->inLobby = 0;
			break;

		case OPac::client_matchChangeSettings:
			Event_client_matchChangeSettings(tP.User,Packet, PacketSize);
			break;

		case OPac::client_matchLock:
			Event_client_matchLock(tP.User, Packet, PacketSize);
			break;

		case OPac::client_matchChangeMods:
			Event_client_matchChangeMods(tP.User, Packet, PacketSize);
			break;

		case OPac::client_joinMatch:
			Event_client_joinMatch(tP.User, Packet, PacketSize);
			break;

		case client_matchChangeTeam:
			Event_client_matchChangeTeam(tP.User);
			break;

		case client_matchNoBeatmap:
			Event_client_matchNoBeatmap(tP.User);
			break;

		case client_matchHasBeatmap:
			Event_client_matchHasBeatmap(tP.User);
			break;

		case client_matchTransferHost:
			Event_client_matchTransferHost(tP.User, Packet, PacketSize);
			break;
		
		case client_matchReady:
			Event_client_matchReady(tP.User);
			break;

		case client_matchNotReady:
			Event_client_matchNotReady(tP.User);
			break;

		case client_matchStart:
			Event_client_matchStart(tP.User);
			break;

		case client_matchLoadComplete:
			Event_client_matchLoadComplete(tP.User);
			break;

		case client_matchScoreUpdate:
			Event_client_matchScoreUpdate(tP.User, Packet, PacketSize);
			break;

		case client_matchComplete:
			Event_client_matchComplete(tP.User);
			break;

		case client_matchFailed:
			Event_client_matchFailed(tP.User);
			break;

		case client_matchSkipRequest:
			Event_client_matchSkipRequest(tP.User);
			break;

		case client_invite:
			Event_client_invite(tP.User, Packet, PacketSize);
			break;
		case client_friendAdd:
			Event_client_friendAdd(tP.User, Packet, PacketSize);
		case client_friendRemove:
			Event_client_friendRemove(tP.User, Packet, PacketSize);
			break;


		default:
			printf("PacketID:%i | Length:%i\n", PacketID, PacketSize);
			break;
		}

		//const unsigned long long TTime = std::chrono::duration_cast<std::chrono::nanoseconds> (std::chrono::steady_clock::now() - sTime).count();

		//if(PacketID == 0 || PacketID == 4 || PacketID == 85)
			//printf("P%i: %fms\n", PacketID, double(double(TTime) / 1000000.0));
		
	}

	SendMatchList(tP.User, 0);//Sends multiplayer data if they are in the lobby.
	//IngameMenu(tP,s);//Handles all the cool new clickable menus

	tP->LastPacketTime = clock_ms();
	
	tP->doQue(s);

}

const std::vector<byte> PingPacket = _BanchoPacket(OPac::server_ping).GetBytes();

const char* countryCodes[] = {
	"--","AP","EU","AD","AE","AF","AG","AI","AL","AM","AN","AO","AQ","AR",
	"AS","AT","AU","AW","AZ","BA","BB","BD","BE","BF","BG","BH","BI","BJ",
	"BM","BN","BO","BR","BS","BT","BV","BW","BY","BZ","CA","CC","CD","CF",
	"CG","CH","CI","CK","CL","CM","CN","CO","CR","CU","CV","CX","CY","CZ",
	"DE","DJ","DK","DM","DO","DZ","EC","EE","EG","EH","ER","ES","ET","FI",
	"FJ","FK","FM","FO","FR","FX","GA","GB","GD","GE","GF","GH","GI","GL",
	"GM","GN","GP","GQ","GR","GS","GT","GU","GW","GY","HK","HM","HN","HR",
	"HT","HU","ID","IE","IL","IN","IO","IQ","IR","IS","IT","JM","JO","JP",
	"KE","KG","KH","KI","KM","KN","KP","KR","KW","KY","KZ","LA","LB","LC",
	"LI","LK","LR","LS","LT","LU","LV","LY","MA","MC","MD","MG","MH","MK",
	"ML","MM","MN","MO","MP","MQ","MR","MS","MT","MU","MV","MW","MX","MY",
	"MZ","NA","NC","NE","NF","NG","NI","NL","NO","NP","NR","NU","NZ","OM",
	"PA","PE","PF","PG","PH","PK","PL","PM","PN","PR","PS","PT","PW","PY",
	"QA","RE","RO","RU","RW","SA","SB","SC","SD","SE","SG","SH","SI","SJ",
	"SK","SL","SM","SN","SO","SR","ST","SV","SY","SZ","TC","TD","TF","TG",
	"TH","TJ","TK","TM","TN","TO","TL","TR","TT","TV","TW","TZ","UA","UG",
	"UM","US","UY","UZ","VA","VC","VE","VG","VI","VN","VU","WF","WS","YE",
	"YT","RS","ZA","ZM","ME","ZW","A1","A2","O1","AX","GG","IM","JE","BL",
	"MF" };

__forceinline byte getCountryNum(const char *isoCode){
	if (isoCode[0] == 0 || isoCode[0] == '0')return 0;

	for (byte i = 0; i < 253; i++){
		if (isoCode[0] == countryCodes[i][0] && isoCode[1] == countryCodes[i][1])
			return i;
	}	
	return 0;
}

const std::vector<byte> PACKET_INCORRECTLOGIN = []{return _BanchoPacket(OPac::server_userID, {0xff,0xff,0xff,0xff}).GetBytes();}();
const std::vector<byte> PACKET_SERVERFULL = [] {
	std::vector<byte> packet = _BanchoPacket(OPac::server_userID, { 0xff,0xff,0xff,0xff }).GetBytes();
	AddVector(packet, bPacket::Notification("Server is currenly full").GetBytes(),byte);
	return packet;
}();
const std::vector<byte> PACKET_CLIENTOUTOFDATE = [] {
	std::vector<byte> packet = _BanchoPacket(OPac::server_userID, { 0xff,0xff,0xff,0xff }).GetBytes();
	AddVector(packet, bPacket::Notification("Your client is out of date!\nPlease update it.").GetBytes(),byte);
	return packet;
}();

void BanchoIncorrectLogin(_Con s){
	s.SendData(ConstructResponse(200, { _HttpHeader("cho-token", "0") }, PACKET_INCORRECTLOGIN));
}
void BanchoServerFull(_Con s) {
	LogError("Server Full");
	s.SendData(ConstructResponse(200, { _HttpHeader("cho-token", "0") }, PACKET_SERVERFULL));
}

void HandleBanchoPacket(_Con s, const _HttpRes &&res,const uint64_t choToken) {

	if (res.Body.size() <= 1){
		printf("Empty packet! (%s)\n",(char*)&res.Host[0]);
		return;
	}

	if (!choToken){//No token sent - Assume its the login request which only ever comes in once

		std::chrono::steady_clock::time_point sTime = std::chrono::steady_clock::now();

		const auto LoginData = EXPLODE_VEC(std::string,res.Body, '\n');

		if (LoginData.size() != 3)
			return BanchoIncorrectLogin(s);

		std::string Username = USERNAMESQL(_M(LoginData[0]));

		const std::string cPassword = REMOVEQUOTES(LoginData[1]);

		const auto ClientData = EXPLODE_VEC(std::string,LoginData[2],'|');

		if (ClientData.size() != 5 || Username.size() > MAX_USERNAME_LENGTH || cPassword.size() != 32)
			return BanchoIncorrectLogin(s);

		const std::string Username_Safe = Username;

		const bool VersionFailed = [&]{

			const std::string &ClientVersion = ClientData[0];

			const size_t Start = (size_t)&ClientVersion[0];
			const size_t End = (size_t)&ClientVersion[ClientVersion.size()] - 4;

			for (size_t i = Start; i < End; i++)
				if (*(USHORT*)i == *(USHORT*)"20" && MemToInt32(i, 4) >= 2019)
					return 0;
		
			return 1;
		}();

		if(VersionFailed)
			return (void)s.SendData(ConstructResponse(200, { _HttpHeader("cho-token", "0") }, PACKET_CLIENTOUTOFDATE));

		int UserID = 0;
		int Priv = 0;
		int SilenceEnd = 0;
		bool NewLogin = 0;
		_UserRef u(GetUserFromNameSafe(Username_Safe, 1),1);

		if (u.User && MD5CMP(u->Password, &cPassword[0])){
			UserID = u->UserID;
			Priv = u->privileges;//TODO make this able to be updated.
			SilenceEnd = u->silence_end;
		}else u.User = 0;

		if(!u){
			NewLogin = 1;
			_SQLCon *const con = &SQL_BanchoThread[s.ID];

			sql::ResultSet *res = con->ExecuteQuery("SELECT id, password_md5, username, privileges,silence_end FROM users WHERE username_safe = '" + Username_Safe + "' LIMIT 1");

			if (!res || !res->next()){
				DeleteAndNull(res);
				return BanchoIncorrectLogin(s);
			}

			UserID = res->getInt(1);

			if (bcrypt_checkpw(cPassword.c_str(), res->getString(2).c_str())){
				DeleteAndNull(res);
				return BanchoIncorrectLogin(s);//Might want to add a brute force lock out
			}
			if (!u) {

				u = _UserRef(GetPlayerSlot_Safe(Username_Safe),1);
				if (!u) {
					DeleteAndNull(res);
					return BanchoServerFull(s);
				}

			}

			Username = res->getString(3);//get the database captialization for consistencies sake
			Priv = res->getInt(4);
			SilenceEnd = res->getInt(5);

			DeleteAndNull(res);

			if (Username != GetUsernameFromCache(UserID))
				UsernameCacheUpdateName(UserID, Username, &SQL_BanchoThread[s.ID]);

			const std::string TableName[] = {"users_stats","rx_stats"};

			for(byte z = 0; z < 2; z++){

				res = con->ExecuteQuery("SELECT ranked_score_std, playcount_std, total_score_std, avg_accuracy_std,pp_std,"
					"ranked_score_taiko, playcount_taiko, total_score_taiko, avg_accuracy_taiko, pp_taiko,"
					"ranked_score_ctb, playcount_ctb, total_score_ctb, avg_accuracy_ctb, pp_ctb,"
					"ranked_score_mania, playcount_mania, total_score_mania, avg_accuracy_mania, pp_mania FROM " + TableName[z] + " WHERE id = " + std::to_string(UserID) + " LIMIT 1");

				if (res && res->next()){

					DWORD Offset = 0;

					for (byte i = 0; i < 4; i++){

						const DWORD Slot = i + (z * 4);

						u->Stats[Slot].rScore = res->getInt64(++Offset);
						u->Stats[Slot].PlayCount = res->getInt(++Offset);
						u->Stats[Slot].tScore = res->getInt64(++Offset);
						u->Stats[Slot].Acc = res->getDouble(++Offset) * 0.01f;
						u->Stats[Slot].pp = res->getInt(++Offset);

					}
				}
				DeleteAndNull(res);
			}

			res = con->ExecuteQuery("SELECT user2 FROM users_relationships WHERE user1 = " + std::to_string(UserID) + " LIMIT 256");
			DWORD fCount = 0;
			while (res && res->next()){
				u->Friends[fCount] = res->getInt(1);
				fCount++;
			}

			DeleteAndNull(res);

			//Todo HWID
		}

		//chan_DevLog.Bot_SendMessage(Username + " Logged in.");

		{
			if (!u){

				u = _UserRef(GetPlayerSlot_Safe(Username_Safe), 1);

				if (!u)
					return BanchoServerFull(s);
			}

			DisconnectUser(u.User);

			u->privileges = Priv;

			u->c1Check = [&]()->std::string{
				const auto cHash = EXPLODE_VEC(std::string, ClientData[3], ':');

				if (cHash.size() < 5)return "";

				return cHash[3] + "|" + cHash[4];
			}();

			u->FriendsOnlyChat = (ClientData[4] == "1");

			u->timeOffset = MemToInt32(&ClientData[1][0], ClientData[1].size());

			

			u->country = 0;// getCountryNum(res.GetHeaderValue("CF-IPCountry")); the nature of private servers disallow this.. i guess bancho could use this :(
						   // Best course of action would to resolve it from cloudflare on registration, not verification.

			u->LoginTime = clock_ms();
			u->LastPacketTime = u->LoginTime;
			u->UserID = UserID;
			u->silence_end = SilenceEnd;

			if(NewLogin)
				u->Username = Username;

			u->Username_Safe = Username_Safe;
			memcpy(u->Password, &cPassword[0], 32);

			u->choToken = GenerateChoToken();

			u->qLock.lock();

			u->addQueNonLocking(bPacket::Notification("Welcome to ruri.\nBuild: " __DATE__ " " __TIME__));

			const int SilenceDelta = (SilenceEnd && SilenceEnd > time(0)) ? SilenceEnd - time(0) : 0;

			if (!SilenceDelta)u->silence_end = 0;

			u->addQueNonLocking(bPacket4Byte(OPac::server_silenceEnd, SilenceDelta));

			u->addQueNonLocking(bPacket4Byte(OPac::server_userID, UserID));
			u->addQueNonLocking(bPacket4Byte(OPac::server_protocolVersion, CHO_VERSION));
			u->addQueNonLocking(bPacket4Byte(OPac::server_supporterGMT, Supporter));
			u->addQueNonLocking(bPacket::UserPanel(u.User));
			u->addQueNonLocking(bPacket::UserStats(u.User));
			
			u->addQueNonLocking(bPacket4Byte(OPac::server_channelInfoEnd, 0));//Sending this after loading the channels fucks with the desired order. So it is here instead.

			const int IRC_LEVEL = GetMaxPerm(u->privileges);
			
			for (DWORD i = 0; i < ChannelListSize(); i++){

				if (ChannelList[i]->ViewLevel > IRC_LEVEL)
					continue;

				u->addQueNonLocking(bPacket::ChannelInfo(ChannelList[i]));
				
				if (ChannelList[i]->AutoJoin){
					u->addQueNonLocking(bPacket::GenericString(OPac::server_channelJoinSuccess, ChannelList[i]->ChannelName));
					ChannelList[i]->JoinChannel(u.User);
				}
			}

			u->addQueNonLocking(bPacket::GenericString(OPac::server_channelKicked, "#osu"));

			std::vector<DWORD> FriendsList;
			FriendsList.reserve(256);
			FriendsList.push_back(999);//Bot is always their friend.
			FriendsList.push_back(UserID);//Shows self in the friend ranking.

			for (DWORD i = 0; i < 256; i++) {
				if (u->Friends[i])
					FriendsList.push_back(u->Friends[i]);
				else break;
			}

			u->addQueNonLocking(bPacket::GenericDWORDList(OPac::server_friendsList, FriendsList, 0));

			u->addQueNonLocking(bPacket::UserPanel(999, 0));
			u->addQueNonLocking(USER_STATS(999, 0));
			
			for (const auto& gUser : Users) {
				if (!gUser.choToken || &gUser == u.User || u->isBlocked(gUser.UserID))
					continue;
				u->addQueNonLocking(bPacket::UserPanel(gUser.UserID, UserID));
				u->addQueNonLocking(USER_STATS(gUser.UserID, UserID));
			}

			u->SendToken = 1;
			u->qLock.unlock();

			const unsigned long long TTime = std::chrono::duration_cast<std::chrono::nanoseconds> (std::chrono::steady_clock::now() - sTime).count();
			printf("LoginTime: %fms\n", double(double(TTime) / 1000000.0));
			;
			u->doQue(s);

			debug_SendOnlineToAll(u.User);
		}

		return;
	}
	else DoBanchoPacket(s,choToken,res.Body);

}


void DisconnectUser(_User *u){

	if (!u || !u->UserID || !u->choToken)return;

	for (DWORD i = 0; i < MAX_CHAN_COUNT; i++) {

		_Channel*const C = (_Channel*)u->ActiveChannels[i];

		if (!C)continue;

		C->PartChannel(u);
	}

	u->choToken = 0;
	u->inLobby = 0;

	if (u->CurrentMatchID){

		_Match *m = getMatchFromID(u->CurrentMatchID);

		if (m) {
			m->Lock.lock();
			m->removeUser(u, 0);
			m->sendUpdate(bPacket::bMatch(OPac::server_updateMatch, m, 1));
			m->Lock.unlock();
		}
		u->CurrentMatchID = 0;
	}

	Event_client_stopSpectating(u);

	for (byte i = 0; i < 8; i++)
		u->Stats[i].reset();

	u->Spectators.clear();

	u->qLock.lock();
	u->Que.clear();
	u->dQue.clear();
	u->qLock.unlock();
}

void HandlePacket(_Con s){

	 _HttpRes res;

	if (!s.RecvData(res)){
		LogMessage(KRED "Connection lost");
		return s.Dis();
	}
	
	std::string UserAgent = res.GetHeaderValue("User-Agent");

	if(UserAgent.size() == 0)
		UserAgent = res.GetHeaderValue("user-agent");

	const uint64_t choToken = StringToUInt64(res.GetHeaderValue("osu-token"));
	
	if (!UserAgent.size()){
		LogMessage("No user agent set.");
		s.SendData(ConstructResponse(200, Empty_Headers,bPacket::Notification("If there is anything that seems wrong make sure to contact rumoi.").GetBytes()));
		s.Dis();
		return;
	}
	if (UserAgent != "osu!" && !choToken){//If it is not found
		RenderHTMLPage(s,_M(res));
		LogMessage("HTML page served");
		return s.Dis();
	}

	HandleBanchoPacket(s, _M(res), choToken);

	return s.Dis();
}

//Used to logout dropped users and other house keeping
void LazyThread(){
	printf("LazyThread running.\n");

	_SQLCon lThreadSQL;
	lThreadSQL.Connect();

	while (1){

		Sleep(500);

		const int cTime = clock_ms();
		
		for (auto& User : Users){
			if(User.choToken && User.LastPacketTime + PING_TIMEOUT_OSU < cTime)
				debug_LogOutUser(&User);
		}

		Sleep(500);

		DWORD ActiveLobbies = 0;

		for (DWORD i = 0; i < MAX_MULTI_COUNT; i++)
			if (Match[i].PlayerCount)
				ActiveLobbies++;

		COUNT_MULTIPLAYER = ActiveLobbies;

		if (SQLExecQue.Commands.size()){

			SQLExecQue.Lock.lock();
			{
				for (std::string& Command : SQLExecQue.Commands)
					lThreadSQL.ExecuteUPDATE(std::move(Command), 1);

				SQLExecQue.Commands.clear();
			}
			SQLExecQue.Lock.unlock();

		}


	}
}


const std::string PPColNames[] = { "pp_std","pp_taiko","pp_ctb","pp_mania" };
const std::string UserTableNames[] = { "users_stats","rx_stats" };

void DoFillRank(DWORD I, bool TableName){

	RankList[I].reserve(USHORT(-1));

	sql::ResultSet *res = SQL_BanchoThread[I].ExecuteQuery("SELECT id, " + PPColNames[I] + " FROM " + UserTableNames[TableName] + " WHERE " + PPColNames[I] + " > 0 ORDER BY " + PPColNames[I] + " DESC");

	DWORD cOffset = 0;

	if (TableName)
		I += 4;
	while (res && res->next()) {
		RankList[I].push_back({res->getUInt(1), res->getUInt(2)});
		cOffset++;
	}
	if (res)delete res;
}


void FillRankCache(){

		printf("Filling rank cache (std)\n");
		{			
			std::array<std::thread, 4> threads = { std::thread(DoFillRank,0,0),std::thread(DoFillRank,1,0),std::thread(DoFillRank,2,0),std::thread(DoFillRank,3,0) };
			for (auto& t : threads)
				t.join();
		}

		printf("Filling rank cache (relax)\n");

		{
			std::array<std::thread, 4> threads = { std::thread(DoFillRank,0,1),std::thread(DoFillRank,1,1),std::thread(DoFillRank,2,1),std::thread(DoFillRank,3,1) };
			for (auto& t : threads)
				t.join();
		}

		printf("Completed both.\n");
}


std::mutex BanchoWorkLock[BANCHO_THREAD_COUNT];
std::vector<_Con> BanchoConnectionQue[BANCHO_THREAD_COUNT];
void BanchoWork(const DWORD ID){
	while(1){

		size_t Count = 0;
		_Con* Req = 0;

		Count = BanchoConnectionQue[ID].size();

		if (Count){
			BanchoWorkLock[ID].lock();

			Count = BanchoConnectionQue[ID].size();

			Req = new _Con[Count];

			if(Req)memcpy(&Req[0], &BanchoConnectionQue[ID][0], Count * sizeof(_Con));

			BanchoConnectionQue[ID].clear();

			BanchoWorkLock[ID].unlock();
		}
		for (DWORD i = 0; i < Count; i++)
			HandlePacket(Req[i]);

		if(Req)delete[] Req;

		Sleep(1);//It being 0 literally hogs an entire core so.. No?
	}
}



void receiveConnections(){

	printf("Starting BanchoThreads\n");

	{
		for (DWORD i = 0; i < BANCHO_THREAD_COUNT; i++){
			BanchoConnectionQue[i].reserve(64);
			printf("BanchoThread%i: %i\n", i, int(SQL_BanchoThread[i].Connect()));
			std::thread a(BanchoWork, i);
			a.detach();
		}
	}


	FillRankCache();

	{
		std::thread a(Aria_Main);
		a.detach();
	}

	while(!ARIALOADED)
		Sleep(100);

	UpdateUsernameCache(&SQL_BanchoThread[0]);
	
	{
		std::thread a(LazyThread);
		a.detach();
	}
#ifndef LINUX
	SOCKET listening = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listening == INVALID_SOCKET)
	{
		printf("Failed to load listening socket.\n");
		return;
	}
	sockaddr_in hint;
	ZeroMemory(&hint.sin_addr, sizeof(hint.sin_addr));
	hint.sin_family = AF_INET;
	hint.sin_port = htons(RURIPORT);

	::bind(listening, (sockaddr*)&hint, sizeof(hint));
	::listen(listening, SOMAXCONN);

	sockaddr_in client;

	DWORD Time = 2000;
	DWORD MPL = MAX_PACKET_LENGTH;

	setsockopt(listening, SOL_SOCKET, SO_RCVTIMEO, (char*)&Time, 4);
	setsockopt(listening, SOL_SOCKET, SO_SNDTIMEO, (char*)&Time, 4);
	setsockopt(listening, SOL_SOCKET, SO_RCVBUF, (char*)&MPL, 4);
#else

	struct sockaddr_un serveraddr;

	SOCKET listening = socket(AF_UNIX, SOCK_STREAM, 0);

	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sun_family = AF_UNIX;
	strcpy(serveraddr.sun_path, RURI_UNIX_SOCKET);

	unlink(RURI_UNIX_SOCKET);

	if (bind(listening, (struct sockaddr *)&serveraddr, SUN_LEN(&serveraddr)) < 0) {
		perror("bind() failed");
		return;
	}
	if (listen(listening, SOMAXCONN) < 0){
		perror("listen() failed");
		return;
	}
	chmod(RURI_UNIX_SOCKET, S_IRWXU | S_IRWXG | S_IRWXO);
	
#endif

	std::printf(KGRN "Listening to socket\n" KRESET);

	DWORD ID = 0;

	while(1){
#ifndef LINUX
		int clientSize = sizeof(client);
		ZeroMemory(&client, clientSize);

		SOCKET s = accept(listening, (sockaddr*)&client, &clientSize);
#else
		SOCKET s = accept(listening, 0, 0);
#endif
		if (s == INVALID_SOCKET)continue;
		
		COUNT_REQUESTS++;

		BanchoWorkLock[ID].lock();

		BanchoConnectionQue[ID].push_back(_Con(s,ID));

		BanchoWorkLock[ID].unlock();

		ID++;
		if (ID >= BANCHO_THREAD_COUNT)ID = 0;

	}
}



std::string ExtractConfigValue(const std::vector<byte> &Input){

	DWORD Start = 0;
	DWORD End = 0;

	for (DWORD i = 0; i < Input.size(); i++){
		if (!Start){
			if (Input[i] == '"')
				Start = i+1;
		}
		else if (Input[i] == '"') {
			End = i;
			break;
		}
	}


	if (!Start || !End)
		return "";

	return std::string(Input.begin() + Start, Input.begin() + End);
}

int main(){

	const std::vector<byte> ConfigBytes = LOAD_FILE("config.ini");

	if (!ConfigBytes.size()){
		printf("\nconfig.ini missing.\n");
		return 0;
	}
	
	auto Config = EXPLODE_VEC(VEC(byte),ConfigBytes, '\n');

	for (DWORD i = 0; i < Config.size(); i++){
		if (SafeStartCMP(Config[i], "osu_API_Key"))
			osu_API_KEY = ExtractConfigValue(Config[i]);
		else if (SafeStartCMP(Config[i], "SQL_Password"))
			SQL_Password = ExtractConfigValue(Config[i]);
		else if (SafeStartCMP(Config[i], "SQL_Username"))
			SQL_Username = ExtractConfigValue(Config[i]);
		else if (SafeStartCMP(Config[i], "SQL_Schema"))
			SQL_Schema = ExtractConfigValue(Config[i]);
		else if (SafeStartCMP(Config[i], "BeatmapPath"))
			BEATMAP_PATH = ExtractConfigValue(Config[i]);
		else if (SafeStartCMP(Config[i], "ReplayPath"))
			REPLAY_PATH = ExtractConfigValue(Config[i]);
	}
	
	if (BANCHO_THREAD_COUNT < 4 || ARIA_THREAD_COUNT < 4){
		printf("BANCHO_THREAD_COUNT or ARIA_THREAD_COUNT can not be below 4\n");
		return 0;
	}

	if (osu_API_KEY.size() == 0)
		printf("No api key was given. Some features will not work.\n");
	else osu_API_BEATMAP = "api/get_beatmaps?k=" + osu_API_KEY + "&";

	if (WSAStartup(MAKEWORD(2, 2), &wsData)) {
		printf("Failed to load WSA.\n");
		return 0;
	}

	receiveConnections();
	
	return 1;
}