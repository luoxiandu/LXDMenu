//Hooking.cpp
#pragma once
#include "stdafx.h"
#include <stdlib.h>
using namespace Memory;

ScriptThread* (*GetActiveThread)() = nullptr;
HMODULE _hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;

std::vector<LPVOID>		Hooking::m_hooks;
uint64_t* Hooking::m_frameCount;
MemoryPool* Hooking::m_entityPool;
fpIsDLCPresent			Hooking::is_DLC_present;
fpSetName			    Hooking::SetName;
fpTriggerScriptEvent	Hooking::trigger_script_event;
fpSetLobbyWeather	    Hooking::set_lobby_weather;
fpGetEventData	        Hooking::get_event_data;
fpIncrementStatHook	    Hooking::increment_stat_hook;
fpCreateAmbientPickup	Hooking::create_ambient_pickup;
fpAddOwnedExplosion     Hooking::add_owned_explosion;
fpGetPlayerPed          Hooking::get_player_ped;
fpSetLobbyTime          Hooking::set_lobby_time;
fpGetPlayerAddress		Hooking::GetPlayerAddress;
fpStatSetInt            Hooking::stat_set_int;
GetEventData            Hooking::get_script_event_data;
fpSendMessage2           Hooking::send_message2;
fpAddTextCompSubstrPlayerName Hooking::add_text_comp_substr_playername;
fpEndTextCmdDisplayText       Hooking::end_text_cmd_display_text;
fpBeginTextCmdDisplayText     Hooking::begin_text_cmd_display_text;
fpNetworkIsSessionStarted	  Hooking::network_is_session_started;
static eGameState* m_gameState;
static uint64_t												m_worldPtr;
static BlipList* m_blipList;
static Hooking::NativeRegistrationNew** m_registrationTable;
static std::unordered_map<uint64_t, Hooking::NativeHandler>	m_handlerCache;
static std::vector<LPVOID>									m_hookedNative;
static __int64** m_globalPtr;

const int EVENT_COUNT = 82;
static std::vector<void*> EventPtr;
static char EventRestore[EVENT_COUNT] = {};
fpGetLabelText Hooking::GetLabelText = nullptr;
class Ini
{
private:
	std::string inifile;
public:
	Ini(std::string file)
	{
		this->inifile = file;
	}

	void WriteString(std::string string, std::string app, std::string key)
	{
		WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), this->inifile.c_str());
	}
	std::string GetString(std::string app, std::string key)
	{
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, this->inifile.c_str());
		return (std::string)buf;
	}

	void WriteInt(int value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	int GetInt(std::string app, std::string key)
	{
		return std::stoi(GetString(app, key));
	}

	void WriteFloat(float value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	float GetFloat(std::string app, std::string key)
	{
		return std::stof(GetString(app, key));
	}
};

/* Start Hooking */
void Hooking::Start(HMODULE hmoduleDLL)
{
	_hmoduleDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	FindPatterns();
	if (!InitializeHooks()) Cleanup();
}
BOOL Hooking::InitializeHooks()
{
	BOOL returnVal = TRUE;

	/*Ini *settingsIni = new Ini(".\Dura\Auth.ini");
	string licensekey = settingsIni->GetString("Login", "Licensekey");
	if (!is_user_authed(licensekey))
	{
		Log::Fatal("License Key/HWID not correct, please contact a Dura Developer.");
		exit(0);
	}*/

	if (!iHook.Initialize()) {
		Log::Error("Failed to initialize InputHook.");
		returnVal = FALSE;
	}

	if (MH_Initialize() != MH_OK) {
		Log::Error("MinHook failed to initialize.");
		returnVal = FALSE;
	}

	if (!HookNatives()) {
		Log::Error("Failed to initialize NativeHooks.");
		returnVal = FALSE;
	}

	return returnVal;
}

template <typename T>
bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = Hooking::GetNativeHandler(hash);
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			m_hookedNative.push_back((LPVOID)originalFunction);
			DEBUGMSG("Hooked Native 0x%#p", hash);
			return true;
		}
	}

	return false;
}


uint64_t CMetaData::m_begin = 0;
uint64_t CMetaData::m_end = 0;
DWORD CMetaData::m_size = 0;

BlipList* Hooking::GetBlipList()
{
	return m_blipList;
}

uint64_t CMetaData::begin()
{
	return m_begin;
}
uint64_t CMetaData::end()
{
	return m_end;
}
DWORD CMetaData::size()
{
	return m_size;
}

void CMetaData::init()
{
	if (m_begin && m_size)
		return;

	m_begin = (uint64_t)GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER* headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS* headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	return;
}



fpIsDLCPresent	OG_IS_DLC_PRESENT = nullptr;
BOOL __cdecl HK_IS_DLC_PRESENT(Hash dlcHash)
{
	static uint64_t	last = 0;
	uint64_t		cur = *Hooking::m_frameCount;
	if (last != cur)
	{
		last = cur;
		Hooking::onTickInit();
	}
	else
		return OG_IS_DLC_PRESENT();
}


Hooking::NativeHandler ORIG_WAIT = NULL;
void* __cdecl MY_WAIT(NativeContext* cxt)
{
	static int lastThread = 0;
	int threadId = SCRIPT::GET_ID_OF_THIS_THREAD();
	if (!lastThread)
	{
		char* name = SCRIPT::_GET_NAME_OF_THREAD(threadId);
		if (strcmp(name, "main_persistent") == 0)
		{
			lastThread = threadId;
			Log::Msg("Hooked Script NAME: %s ID: %i", name, threadId);
		}
	}
	if (threadId == lastThread) Hooking::onTickInit();
	ORIG_WAIT(cxt);
	return cxt;
}

Hooking::NativeHandler  ORIG_NETWORK_SESSION_KICK_PLAYER = NULL;
void* __cdecl MY_NETWORK_SESSION_KICK_PLAYER(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_SESSION_KICK_PLAYER(cxt);
	}
	return nullptr;
}


Hooking::NativeHandler  ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE = NULL;
void* __cdecl MY_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler  ORIG_ATTACH_ENTITY_TO_ENTITY = NULL;
void* __cdecl MY_ATTACH_ENTITY_TO_ENTITY(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_ATTACH_ENTITY_TO_ENTITY(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS_IMMEDIATELY = NULL;
void* __cdecl MY_CLEAR_PED_TASKS_IMMEDIATELY(NativeContext* cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS_IMMEDIATELY(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS = NULL;
void* __cdecl MY_CLEAR_PED_TASKS(NativeContext* cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_SECONDARY_TASK = NULL;
void* __cdecl MY_CLEAR_PED_SECONDARY_TASK(NativeContext* cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_SECONDARY_TASK(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLONE_PED = NULL;
void* __cdecl MY_CLONE_PED(NativeContext* cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLONE_PED(cxt);
	}
	return nullptr;
}


fpGetLabelText ogGetLabelText = nullptr;
const char* hkGetLabelText(void* this_, const char* label)
{
	// 右下角加载部分
	if (std::strcmp(label, "HUD_MPREENTER") == 0)
	{
		return "24K Menu正在和您一起寻找新的战局";
	}
	if (std::strcmp(label, "HUD_JOINING") == 0)
	{
		return "24K Menu正在和您一起进入在线模式";
	}
	if (std::strcmp(label, "HUD_QUITTING") == 0)
	{
		return "24K Menu正在和您一起返回故事模式";
	}
	if (std::strcmp(label, "PM_QUIT_MP") == 0)
	{
		return "和24K Menu一起返回故事模式";
	}
	if (std::strcmp(label, "HUD_TRANSP") == 0)
	{
		return "24K Menu正在帮您搞交易";
	}
	if (std::strcmp(label, "MPATM_PEND") == 0)
	{
		return "24K Menu正在帮您搞交易";
	}
	if (std::strcmp(label, "0xCB2C3C6B") == 0)
	{
		return "24K Menu正在帮您搞交易";
	}
	if (std::strcmp(label, "LOADING_MPLAYER_L") == 0)
	{
		return "24K Menu正在和您一起加载线上模式";
	}
	if (std::strcmp(label, "LOADING_SPLAYER_L") == 0)
	{
		return "24K Menu正在和您一起加载故事模式";
	}
	// 线下进线上的主菜单部分
	if (std::strcmp(label, "PM_ENTER_MP") == 0)
	{
		return "和24K Menu一起进入在线模式";
	}
	if (std::strcmp(label, "PM_INF_PGOT") == 0)
	{
		return "和24K Menu一起进入在线模式";
	}
	if (std::strcmp(label, "PM_INF_PGOB") == 0)
	{
		return "直入主题，进入GTA在线模式，并用24K Menu提供的强大功能获取无穷乐趣。";
	}
	// 在线模式的详情选择界面
	if (std::strcmp(label, "PM_GO") == 0)
	{
		return "加入公开战局";
	}
	if (std::strcmp(label, "PM_INF_PGOT0") == 0)
	{
		return "和24K Menu一起加入公开战局";
	}
	if (std::strcmp(label, "PM_INF_PGOB0") == 0)
	{
		return "直接进入公开战局，与未曾谋面的犯罪精英激情厮杀。";
	}
	if (std::strcmp(label, "PM_NCREW_FM") == 0)
	{
		return "加入帮会战局";
	}
	if (std::strcmp(label, "PM_INF_PGOT1") == 0)
	{
		return "和24K Menu一起加入帮会战局";
	}
	if (std::strcmp(label, "PM_INF_PGOB1") == 0)
	{
		return "寻找公开的帮会战局，并告诉他们谁才是老大。";
	}
	if (std::strcmp(label, "PM_CREW_FM") == 0)
	{
		return "加入非公开帮会战局";
	}
	if (std::strcmp(label, "PM_INF_PGOT2") == 0)
	{
		return "和24K Menu一起加入非公开帮会战局";
	}
	if (std::strcmp(label, "PM_INF_PGOB2") == 0)
	{
		return "和您自己帮会的同志们一起游乐，开黑，核平洛圣都。";
	}
	if (std::strcmp(label, "PM_FRIEND_FM") == 0)
	{
		return "加入非公开好友战局";
	}
	if (std::strcmp(label, "PM_INF_PGOT3") == 0)
	{
		return "和24K Menu一起加入非公开好友战局";
	}
	if (std::strcmp(label, "PM_INF_PGOB3") == 0)
	{
		return "你的朋友或许正在自闭，你现在就可以去拯救他！";
	}
	if (std::strcmp(label, "PM_SOLO_FM") == 0)
	{
		return "创建单人战局";
	}
	if (std::strcmp(label, "PM_INF_PGOT4") == 0)
	{
		return "和24K Menu一起创建单人战局";
	}
	if (std::strcmp(label, "PM_INF_PGOB4") == 0)
	{
		return "这是官方的自闭战局，很多功能不能用的。如果您想单人拉货请想办法卡单人~r~公开~w~战局。";
	}
	if (std::strcmp(label, "PM_INVO_FM") == 0)
	{
		return "创建凭邀请加入的战局";
	}
	if (std::strcmp(label, "PM_INF_PGOT5") == 0)
	{
		return "和24K Menu一起创建凭邀请加入的战局";
	}
	if (std::strcmp(label, "PM_INF_PGOB5") == 0)
	{
		return "开房!噢!耶！";
	}
	// 在线模式的菜单界面
	if (std::strcmp(label, "PM_GOTO_STORE") == 0)
	{
		return "和24K Menu一起去在线商店";
	}
	if (std::strcmp(label, "PM_FIND_SESS") == 0)
	{
		return "和24K Menu一起寻找新战局";
	}
	if (std::strcmp(label, "PM_EXIT_GAME") == 0)
	{
		return "和24K Menu一起退出游戏";
	}
	if (*(unsigned int*)label == 0xB3182F72)  // 不起作用,不知道这种数的标签怎么hook
	{
		return "24K Menu恭喜你又激活了一个全新的账号！请时刻注意辅助的更新，降低封号风险。有关辅助的更多内容请访问我们的官网：~HUD_COLOUR_SOCIAL_CLUB~https://24kmenu.com~n~哦对了，R星提醒你不要作弊（滑稽）";
	}

	return ogGetLabelText(this_, label);
}

bool Hooking::HookNatives()
{
	MH_STATUS status = MH_CreateHook(Hooking::is_DLC_present, HK_IS_DLC_PRESENT, (void**)& OG_IS_DLC_PRESENT);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_DLC_present) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(Hooking::is_DLC_present);

	MH_STATUS statuslol = MH_CreateHook(Hooking::GetLabelText, hkGetLabelText, (void**)& ogGetLabelText);
	if (status != MH_OK || MH_EnableHook(Hooking::GetLabelText) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(Hooking::GetLabelText);

	// Not know what is it.
	/*auto KekCheck = Memory::pattern("80 3D ? ? ? ? ? 0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 08 48 39 0D ? ? ? ? 0F 85").count(1).get(0).get<std::uint8_t>(0);
	KekCheck[0] = 0xC3;
	std::memset(KekCheck + 1, 0x90, 7);
	FlushInstructionCache(GetCurrentProcess(), KekCheck, 8);*/


	return true;
}

void __stdcall ScriptFunction(LPVOID lpParameter)
{
	try
	{
		ScriptMain();

	}
	catch (...)
	{
		// GBK 文本：外挂线程初始化失败，请检查外挂文件完整性。（是不是漏放了外挂资源文件等）
		Log::Fatal("\xCD\xE2\xB9\xD2\xCF\xDF\xB3\xCC\xB3\xF5\xCA\xBC\xBB\xAF\xCA\xA7\xB0\xDC\xA3\xAC\xC7\xEB\xBC\xEC\xB2\xE9\xCD\xE2\xB9\xD2\xCE\xC4\xBC\xFE\xCD\xEA\xD5\xFB\xD0\xD4\xA1\xA3\xA3\xA8\xCA\xC7\xB2\xBB\xCA\xC7\xC2\xA9\xB7\xC5\xC1\xCB\xCD\xE2\xB9\xD2\xD7\xCA\xD4\xB4\xCE\xC4\xBC\xFE\xB5\xC8\xA3\xA9");
	}
}

void Hooking::onTickInit()
{
	if (mainFiber == nullptr)
		mainFiber = ConvertThreadToFiber(nullptr);

	if (timeGetTime() < wakeAt)
		return;

	static HANDLE scriptFiber;
	if (scriptFiber)
		SwitchToFiber(scriptFiber);
	else
		scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);
}

void Hooking::FailPatterns(const char* name)
{
	char buf[4096];
	sprintf_s(buf, "finding %s", name);
	Log::Error(buf);
	Cleanup();
}

/*
//CPatternResult
*/

CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

/*
//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern& CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern& CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}

/*
//CPattern Private
*/
bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE* btMask, char* szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE* ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE* btMask, char* szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char* pStart = nullptr;
	char* pEnd = nullptr;
	char* res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}

		mbi = {};
	}
	return (uint64_t)res;
}

void	failPat(const char* name)
{
	// Bypass %s 失败！游戏可能已经更新，请等待版本升级。
	Log::Fatal("\x42\x79\x70\x61\x73\x73\x20\x25\x73\x20\xCA\xA7\xB0\xDC\xA3\xA1\xD3\xCE\xCF\xB7\xBF\xC9\xC4\xDC\xD2\xD1\xBE\xAD\xB8\xFC\xD0\xC2\xA3\xAC\xC7\xEB\xB5\xC8\xB4\xFD\xB0\xE6\xB1\xBE\xC9\xFD\xBC\xB6\xA1\xA3", name);
	exit(0);
}

template <typename T>
void	setPat
(
	const char* name,
	char* pat,
	char* mask,
	T** out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T* ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	while (true)
	{
		if (ptr == nullptr)
			failPat(name);

		if (deref <= 0)
			break;
		ptr = *(T * *)ptr;
		--deref;
	}

	*out = ptr;
	return;
}

template <typename T>
void	setFn
(
	const char* name,
	char* pat,
	char* mask,
	T* out,
	int			skip = 0
)
{
	char* ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr)
		failPat(name);

	*out = (T)ptr;
	return;
}

int Steam_Judge;

void Hooking::FindPatterns()
{
	HANDLE steam = GetModuleHandleA("steam_api64.dll");


	if (steam)
	{
		Log::Msg("Steam Users");
		Steam_Judge = 1;
	}
	else {
		Log::Msg("Not Steam Platform Users!");
		Steam_Judge = 0;
	}

	auto p_activeThread = pattern("E8 ? ? ? ? 48 8B 88 10 01 00 00");
	

	Log::Msg("Found 'p_activeThread' pattern.");

	auto p_blipList = pattern("4C 8D 05 ? ? ? ? 0F B7 C1");


	Log::Msg("Found 'p_blipList' pattern.");

	auto p_fixVector3Result = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");


	Log::Msg("Found 'p_fixVector3Result' pattern.");

	auto p_gameLegals = pattern("72 1F E8 ? ? ? ? 8B 0D");


	Log::Msg("Found 'p_gameLegals' pattern.");

	auto p_gameLogos = pattern("70 6C 61 74 66 6F 72 6D 3A");


	Log::Msg("Found 'p_gameLogos' pattern.");

	auto p_gameState = pattern("83 3D ? ? ? ? ? 8A D9 74 0A");

	Log::Msg("Found 'p_gameState' pattern.");

	auto p_nativeTable = pattern("76 32 48 8B 53 40 48 8D 0D");

	Log::Msg("Found 'p_nativeTable' pattern.");

	auto p_worldPtr = pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");


	Log::Msg("Found 'p_worldPtr' pattern.");

	auto p_globalPtr = pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11");


	Log::Msg("Found 'p_globalPtr' pattern.");

	auto p_eventHook = pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03");


	Log::Msg("Found 'p_eventHook' pattern.");

	auto p_incrementStatEventVTable = Memory::pattern("48 8D 05 ? ? ? ? 48 89 03 48 8B C3 48 83 C4 ? 5B C3 CC 48 8B C4").count(1);
	Log::Msg("Found 'p_incrementStatEventVTable' pattern.");
	ReportProtectionHook::m_incrementStatEventVTable = reinterpret_cast<uintptr_t*>(reinterpret_cast<char*>(p_incrementStatEventVTable.get(0).get<char>(0)) + *reinterpret_cast<int*>(p_incrementStatEventVTable.get(0).get<int>(3)) + 7);
	ReportProtectionHook::f_incrementStatEventHandler = *reinterpret_cast<bool(**)(char*, char*, float)>(&ReportProtectionHook::m_incrementStatEventVTable[7]);
	*reinterpret_cast<bool(**)(char*, char*, float)>(&ReportProtectionHook::m_incrementStatEventVTable[7]) = &ReportProtectionHook::hookedIncrementStatEventHandler;


	setFn<fpTriggerScriptEvent>("trigger_script_event", "\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF0\x41\x8B\xF9", "xxxxxxxxxxxxxxxxxxxxxxxx????xxxxxx", &Hooking::trigger_script_event);


	Log::Msg("Found 'trigger_script_event' signature.");

	setFn<fpSetLobbyWeather>("set_lobby_weather",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xE9",
		"xxxx?xxxx?xxxx?xxxxxxxx",
		&Hooking::set_lobby_weather);


	Log::Msg("Found 'set_lobby_weather' signature.");

	setFn<fpGetEventData>("get_event_data",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00\x41\x8B\xD9\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x14\x4C\x8B\x10\x44\x8B\xC3\x48\x8B\xD7\x41\xC1\xE0\x03\x48\x8B\xC8\x41\xFF\x52\x30\x48\x8B\x5C\x24\x00",
		"xxxx?xxxxxxxxxxx????xxxx????xxxxxxxxxxxxxxxxxxxxxxxxxxxxx?",
		&Hooking::get_event_data);

	Log::Msg("Found 'get_event_data' signature.");

	setPat<uint64_t>("frame count",
		"\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF",
		"xx????xxx",
		&Hooking::m_frameCount,
		true,
		2);

	//entity pool
	setPat<MemoryPool>("entity pool",
		"\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08",
		"xxx????xxxxxxx",
		&Hooking::m_entityPool,
		true,
		3);


	Log::Msg("Found 'frame_count' signature.");

	setFn<fpIsDLCPresent>("is_DLC_present",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x81\xF9\x00\x00\x00\x00",
		"xxxx?xxxxxxx????",
		&Hooking::is_DLC_present);

	Log::Msg("Found 'is_DLC_present' signature.");

	setFn<GetEventData>("get_script_event_data",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00",
		"xxxx?xxxxxxxxxxx????",
		&Hooking::get_script_event_data);


	Log::Msg("Found 'get_script_event_data' signature.");

	// Outdated!
	/*setFn<fpSetName>("SetName",
		"\x48\x8B\x05\x00\x00\x00\x00\xC3\x8A\xD1",
		"xxx????xxx",
		&Hooking::SetName);*/

	setFn<fpIncrementStatHook>("increment_stat_hook",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x55\x57\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x60\x8B\x79\x30",
		"xxxx?xxxx?xxxxxxxxxxxxxxxxxx",
		&Hooking::increment_stat_hook);


	Log::Msg("Found 'increment_stat_hook' signature.");


	setFn<fpAddOwnedExplosion>("add_owned_explosion",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\x68\xB9\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x41\x8B\xD8\x48\x8B\xF2\x0F\x28\xF3\x8B\xF9\xE8\x00\x00\x00\x00\x45\x33\xF6\x48\x8B\xC8\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\xF3\x0F\x10\x06\xF3\x0F\x10\x4E\x00\xF3\x0F\x10\x56\x00\x8B\x05\x00\x00\x00\x00\x44\x21\x75\xCF\x44\x21\x75\xD3\x44\x89\x75\xF7\x66\x83\x4D\x00\x00\x83\xCE\xFF\xF3\x0F\x11\x45\x00\xF3\x0F\x10\x45\x00\xF3\x0F\x11\x4D\x00\x48\x8D\x55\xA7\xF3\x0F\x11\x45\x00\xF3\x0F\x11\x55\x00\x89\x5C\x24\x30\x4C\x89\x75\x9F\x4C\x89\x75\xAF\x44\x89\x75\xB7\x48\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x66\xC7\x45\x00\x00\x00\x44\x88\x75\xCD\xC7\x45\x00\x00\x00\x00\x00\x4C\x89\x75\xDF\x44\x89\x75\xE7\x89\x75\xEB\x44\x89\x75\xEF\x89\x45\xF3\x66\x89\x75\xF7\x4C\x89\x75\xFF\xC6\x45\x07\xFF\x44\x89\x75\x09\x66\x44\x89\x75\x00\x44\x88\x75\x0F\x48\x89\x4D\xA7\xE8\x00\x00\x00\x00\x44\x38\x35\x00\x00\x00\x00\xF3\x0F\x10\x45\x00\xF3\x0F\x11\x75\x00\xF3\x0F\x11\x45\x00\x8A\x45\x6F\x88\x45\xCB\x8A\x45\x77\x88\x45\xCC\x0F\x85\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x8B\x48\x08\xE8\x00\x00\x00\x00\x3B\xF8\x40\x0F\x94\xC7\xE8\x00\x00\x00\x00\x84\xC0\x74\x14\x44\x38\x35\x00\x00\x00\x00\x74\x0B\xE8\x00\x00\x00\x00\x84\xC0\xB0\x01\x74\x03",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxx????xxxxxxxxxxx????xxxxxxxx?xxxx?xx????xxxxxxxxxxxxxxx??xxxxxxx?xxxx?xxxx?xxxxxxxx?xxxx?xxxxxxxxxxxxxxxxxxx?????xx?????xx?????xxx???xxxxxx?????xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx?xxxxxxxxx????xxx????xxxx?xxxx?xxxx?xxxxxxxxxxxxxx????xxx????xxxxx????xxxxxxx????xxxxxxx????xxx????xxxxxx",
		&Hooking::add_owned_explosion);


	Log::Msg("Found 'add_owned_explosion' signature.");
	setFn<fpCreateAmbientPickup>("create_ambient_pickup",
		"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x48\x89\x78\x20\x55\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x68\xC1\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF9\x41\x8B\xF0\x4C\x8B\xEA\xE8\x00\x00\x00\x00\x0F\xB7\x0D\x00\x00\x00\x00\x33\xFF\x44\x8B\xC7\x44\x8B\xD7\x44\x8B\xE0\x85\xC9\x7E\x1C\x48\x8B\x1D\x00\x00\x00\x00",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxx????xxx????xxxxxxxxxxxxxxxxxx????",
		&Hooking::create_ambient_pickup);


	Log::Msg("Found 'create_ambient_pickup' signature.");


	setFn<fpGetPlayerPed>("get_player_ped",
		"\x48\x83\xEC\x28\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1C\x8A\x88\x00\x00\x00\x00\xF6\xC1\x01\x75\x05\xF6\xC1\x02\x75\x0C",
		"xxxxxxx????xxxxxxx????xxxxxxxxxx",
		&Hooking::get_player_ped);

	Log::Msg("Found 'get_player_ped' signature.");

	// Outdated!
	/*setFn<fpSetLobbyTime>("set_lobby_time",
		"\x80\x3D\x00\x00\x00\x00\x00\x75\x37\x8B\x05\x00\x00\x00\x00\xC6",
		"xx?????xxxx????x",
		&Hooking::set_lobby_time);*/

	setFn<fpSendMessage2>("send_message2",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x48\x8B\xF9\x48\x8D\x4C\x24\x00\x48\x8B\xDA\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\xD3\xE8\x00\x00\x00\x00\x84\xC0\x74\x14\x48\x8B\x0D\x00\x00\x00\x00\x4C\x8D\x44\x24\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x32\xC0\x48\x8B\x5C\x24\x00",
		"xxxx?xxxxxxxxxxxx?xxxx????xxxx?xx????xxxx????xxxxxxx????xxxx?xxxx????xxxxxx?",
		&Hooking::send_message2);



	Log::Msg("Found 'send_message2' signature.");


	setFn<fpGetPlayerAddress>("GetPlayerAddress",
		"\x40\x53\x48\x83\xEC\x20\x33\xDB\x38\x1D\x00\x00\x00\x00\x74\x1C",
		"xxxxxxxxxx????xx",
		&Hooking::GetPlayerAddress);


	Log::Msg("Found 'GetPlayerAddress' signature.");

	//add_text_comp_substr_playername
	setFn<fpAddTextCompSubstrPlayerName>("AddTextCompSubstrPlayerName",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x05\x00\x00\x00\x00\x4C\x8B\xD1",
		"xxxx?xxxx?xxxx?xxxxxxx????xxx",
		&Hooking::add_text_comp_substr_playername);


	Log::Msg("Found 'AddTextCompSubstrPlayerName' signature.");

	//end_text_cmd_display_text
	setFn<fpEndTextCmdDisplayText>("EndTextCmdDisplayText",
		"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x0F\x29\x7C\x24\x00\x41\x8B\xD8",
		"xxxxxxxxxx?xxxx?xxx",
		&Hooking::end_text_cmd_display_text);


	Log::Msg("Found 'EndTextCmdDisplayText' signature.");

	//begin_text_cmd_display_text
	setFn<fpBeginTextCmdDisplayText>("BeginTextCmdDisplayText",
		"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0",
		"xxxxx????x????xxxxx",
		&Hooking::begin_text_cmd_display_text);

	Log::Msg("Found 'BeginTextCmdDisplayText' signature.");
	
	// Outdated!
	/*setFn<fpStatSetInt>("stat_set_int",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x89\x54\x24\x10\x55\x57\x41\x57",
		"xxxx?xxxx?xxxxxxxx",
		&Hooking::stat_set_int);*/

	// Outdated!
	/*setFn<fpNetworkIsSessionStarted>("network_is_session_started",
		"\x48\x8B\x0D\x00\x00\x00\x00\x33\xC0\x48\x85\xC9\x74\x0E\x83\xB9\x00\x00\x00\x00\x00\x75\x05",
		"xxx????xxxxxxxxx?????xx",
		&Hooking::network_is_session_started);*/
	Hooking::GetLabelText = static_cast<fpGetLabelText>(Memory::pattern("48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8").count(1).get(0).get<void>(0));

	char* c_location = nullptr;
	void* v_location = nullptr;


	Sleep(5000);
	// Get game state
	c_location = p_gameState.count(1).get(0).get<char>(2);
	c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);

	// Get vector3 result fixer function
	v_location = p_fixVector3Result.count(1).get(0).get<void>(0);
	if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);

	// Get native registration table
	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration table") : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);

	// Get world pointer
	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer") : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;

	// Get blip list
	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List") : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);


	// Old and detected
	// CPattern pattern_modelCheck("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50", "xxxxx????xxx");
	// auto p_modelCheck = pattern_modelCheck.find(0).get(0).get<char>(0);
	// p_modelCheck == nullptr ? Log::Msg("Found 'modelCheck2' pattern.") : Memory::nop(p_modelCheck, 24);

	// Bypass is player model allowed to spawn checks
	// CPattern pattern_modelSpawn("\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48", "xxxxxxxxxxx");
	// auto p_modelSpawn = pattern_modelSpawn.find(0).get(0).get<char>(8);
	// p_modelSpawn == nullptr ? Log::Error("Loaded .ini vehicle spawner.") : Memory::nop(p_modelSpawn, 2);

	// Get active script thread
	c_location = p_activeThread.count(1).get(0).get<char>(1);
	c_location == nullptr ? FailPatterns("Active Script Thread") : GetActiveThread = reinterpret_cast<decltype(GetActiveThread)>(c_location + *(int32_t*)c_location + 4);

	// Get world pointer
	c_location = p_globalPtr.count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	c_location == nullptr ? FailPatterns("globalTable") : patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);
	m_globalPtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);

	// Get event hook
	if ((c_location = p_eventHook.count(1).get(0).get<char>(0)))
	{
		int i = 0, j = 0, matches = 0, found = 0;
		char* pattern = "\x4C\x8D\x05";
		while (found != EVENT_COUNT)
		{
			if (c_location[i] == pattern[j])
			{
				if (++matches == 3)
				{
					EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
					found++;
					j = matches = 0;
				}
				j++;
			}
			else
			{
				matches = j = 0;
			}
			i++;
		}
	}

	DEBUGMSG("Initializing natives");
	CrossMapping::initNativeMap();

	// Check if game is ready
	Log::Msg("Waiting for your game to load...");
	while (*m_gameState != GameStatePlaying) {
		Sleep(200);
	}
	Log::Msg("Hooking enabled.");
}

static Hooking::NativeHandler _Handler(uint64_t origHash)
{
	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0)
	{
		return nullptr;
	}

	Hooking::NativeRegistrationNew* table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->getNextRegistration())
	{
		for (uint32_t i = 0; i < table->getNumEntries(); i++)
		{
			if (newHash == table->getHash(i))
			{
				return table->handlers[i];
			}
		}
	}
	return nullptr;
}

Hooking::NativeHandler Hooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}

	return handler;
}

eGameState Hooking::GetGameState()
{
	return *m_gameState;
}

uint64_t Hooking::getWorldPtr()
{
	return m_worldPtr;
}
void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}


extern Auth authserver;
DWORD WINAPI CleanupThread(LPVOID lpParam)
{
	while(!authserver.logout());
	for (int i = 0; i < Hooking::m_hooks.size(); i++)
		MH_QueueDisableHook(Hooking::m_hooks[i]);
	MH_ApplyQueued();
	MH_Uninitialize();
	iHook.Remove();
	FreeLibraryAndExitThread(_hmoduleDLL, 0);
}
void Hooking::Cleanup()
{
	Log::Msg("Unhooking...");
	CreateThread(nullptr, THREAD_ALL_ACCESS, CleanupThread, nullptr, NULL, nullptr);
}
void Hooking::defuseEvent(RockstarEvent event, bool toggle)
{
	static const unsigned char retn = 0xC3;
	char* p = (char*)EventPtr[event];
	if (toggle)
	{
		if (EventRestore[event] == 0)
			EventRestore[event] = p[0];
		*p = retn;
	}
	else
	{
		if (EventRestore[event] != 0)
			* p = EventRestore[event];
	}
}

__int64** Hooking::getGlobalPtr()
{
	return m_globalPtr;
}

__int64* Hooking::getGlobalPatern(int index)
{
	return &m_globalPtr[index >> 0x12 & 0x3F][index & 0x3FFFF];
}

char* Hooking::handle_to_ptr(int handle)
{
	uintptr_t ptr = get_address_of_item_in_pool(m_entityPool, handle);
	if (ptr == 0)
		return nullptr;
	return *reinterpret_cast<char * *>(ptr + 8);
}

uintptr_t Hooking::get_address_of_item_in_pool(MemoryPool* pool, int handle)
{
	if (pool == nullptr)
		return 0;

	int index = handle >> 8;
	int flag = pool->BoolAdr[index];

	if (flag & 0x80 || flag != (handle & 0xFF))
		return 0;

	return pool->ListAddr + index * pool->ItemSize;
}