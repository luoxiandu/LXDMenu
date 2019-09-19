#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_ERRORS
#define _USE_WIHTTP_INTERFACE
#include "Auth/sdtsm/SM2.h"
#include "Auth/sdtsm/SM3.h"

#include "Auth.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <atlutil.h>
#include <sstream>
#include <iomanip>
#include <locale>
#include <codecvt>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>

std::string menu_version = "1.0.9";

const char* client_private_key_hexstr = "977EDC91A8BB5825B1D7FAED03B2CF8D87758AFF3A116259EBD25CDAA0FC4612";
const char* server_public_key_hexstr = "66F16DF14487954D7FF05DA7543B1181134E12D378AD1EE0EC73DC779127B29DB9433AFA50FE33FAD09FF0DD044B91D8D6DC848978F871474E10460A1C1387E5";
const char* client_public_key_hexstr = "1A29FE06888C6AB8968321171518387052DB33D4C6348ABBEA4D01010A89824C08EAB62D79FDF573044054EE3BC9694E0F782AF6FF290CB07D2A7B3D6C80A0E1";

/**
int main()
{
	Auth a;
	cout << (a.login(std::string("qzhsjz"), std::string("86.corrode")) ? "登录成功" : "登录失败") << endl;
	cout << (a.is_authed() ? "认证成功" : "认证失败") << endl;
	getchar();
	return 0;
}
**/

struct   NTP_Packet
{
	int      Control_Word;
	int      root_delay;
	int      root_dispersion;
	int      reference_identifier;
	__int64 reference_timestamp;
	__int64 originate_timestamp;
	__int64 receive_timestamp;
	int      transmit_timestamp_seconds;
	int      transmit_timestamp_fractions;
};


/************************************************************************/  
/* 函数说明:自动与时间服务器同步更新 
/* 参数说明:无 
/* 返 回 值:成功返回TRUE，失败返回FALSE 
/************************************************************************/  
bool UpdateSysTime()
{
    WORD    wVersionRequested;
    WSADATA wsaData;
	int retval;

    // 初始化版本
    wVersionRequested = MAKEWORD( 1, 1 );
    if (0!=WSAStartup(wVersionRequested, &wsaData))
    {  
        WSACleanup();
        return false;
    }
    if (LOBYTE(wsaData.wVersion)!=1 || HIBYTE(wsaData.wVersion)!=1)
    {
        WSACleanup();
        return false;   
    }

    // 这个IP是中国大陆时间同步服务器地址，可自行修改
    SOCKET soc=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    struct sockaddr_in addrSrv;
    addrSrv.sin_addr.S_un.S_addr=inet_addr("203.107.6.88");  // ntp.aliyun.com
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(123);
          
    NTP_Packet NTP_Send,NTP_Recv;
	NTP_Send.Control_Word = htonl(0x0B000000);
	NTP_Send.root_delay = 0;
	NTP_Send.root_dispersion = 0;
	NTP_Send.reference_identifier = 0;
	NTP_Send.reference_timestamp = 0;
	NTP_Send.originate_timestamp = 0;
	NTP_Send.receive_timestamp = 0;
	NTP_Send.transmit_timestamp_seconds = 0;
	NTP_Send.transmit_timestamp_fractions = 0;

	retval = sendto(soc, (const char*)& NTP_Send, sizeof(NTP_Send), 0, (struct sockaddr*) & addrSrv, sizeof(addrSrv));
    if(SOCKET_ERROR == retval || INVALID_SOCKET == retval)
    {
        closesocket(soc);
        return false;
    }
    int sockaddr_Size =sizeof(addrSrv);
	retval = recvfrom(soc, (char*)& NTP_Recv, sizeof(NTP_Recv), 0, (struct sockaddr*) & addrSrv, &sockaddr_Size);
    if(SOCKET_ERROR == retval || INVALID_SOCKET == retval)
    {
        closesocket(soc);
        return false;
    }
    closesocket(soc);
    WSACleanup();

    SYSTEMTIME  newtime;  
    float       Splitseconds;  
    struct      tm  *lpLocalTime;  
    time_t      ntp_time;  
      
    // 获取时间服务器的时间  
    ntp_time    = ntohl(NTP_Recv.transmit_timestamp_seconds)-2208988800;  
    lpLocalTime = localtime(&ntp_time);  
    if(lpLocalTime == nullptr)  
    {  
        return false;  
    }  
          
    // 获取新的时间  
    newtime.wYear      =lpLocalTime->tm_year+1900;  
    newtime.wMonth     =lpLocalTime->tm_mon+1;  
    newtime.wDayOfWeek =lpLocalTime->tm_wday;  
    newtime.wDay       =lpLocalTime->tm_mday;  
    newtime.wHour      =lpLocalTime->tm_hour;  
    newtime.wMinute    =lpLocalTime->tm_min;  
    newtime.wSecond    =lpLocalTime->tm_sec;  
          
    // 设置时间精度  
    Splitseconds=(float)ntohl(NTP_Recv.transmit_timestamp_fractions);  
    Splitseconds=(float)0.000000000200 * Splitseconds;  
    Splitseconds=(float)1000.0 * Splitseconds;  
    newtime.wMilliseconds   =   (unsigned   short)Splitseconds;  
      
    // 修改本机系统时间  
    SetLocalTime(&newtime);  
    return true;  
}

bool Auth::UpdateTimeOffsetHttp()
{
	RestClient::Response res = RestClient::get("http://47.75.254.17/auth/");
	if (200 == res.code)
	{
		// 解析收到的JSON数据
		rapidjson::Document d;
		d.Parse(res.body.c_str());
		// 判断响应是否正常
		if (d.IsObject() && d["payload"].IsObject())
		{
			time_t recvtime;
			time(&recvtime);
			time_offset = d["payload"]["now"].GetInt() - recvtime;
			return true;
		}
	}
	return false;
}


/************************************************************************
*   功能：将一个十六进制字节串转换成 ASCII 码表示的十六进制的字符串
*   输入参数：pHex    -- 十六进制数字节串首地址
*            pAscii -- 转换后的 ASCII 码表示的十六进制字符串的首地址
*            nLen    -- 要转换的十六进制数的长度（字节数）
*   输出参数：None
*   注：  转换后的结果全部是大写 ASCII 表示的十六进制数
************************************************************************/
void HexToAscii(unsigned char* pHex, unsigned char* pAscii, int nLen)
{
	unsigned char Nibble[2];

	for (int i = 0; i < nLen; i++)
	{
		Nibble[0] = (pHex[i] & 0xF0) >> 4;
		Nibble[1] = pHex[i] & 0x0F;
		for (int j = 0; j < 2; j++)
		{
			if (Nibble[j] < 10)
				Nibble[j] += 0x30;
			else
			{
				if (Nibble[j] < 16)
					Nibble[j] = Nibble[j] - 10 + 'A';
			}
			*pAscii++ = Nibble[j];
		}   // for (int j = ...)
	}   // for (int i = ...)
}

/****************************************************************************
*   功能：将一个 ASCII 码表示的十六进制字符串转换成十六进制的字节串
*   输入参数：pAscii -- 转换后的 ASCII 码表示的十六进制字符串的首地址
*            pHex   -- 十六进制数字节串首地址
*            nLen   -- 要转换的 ASCII 码表示的十六进制字符串的长度（字节数）
*   输出参数：None
*   注：  要求输入的 ASCII 码表示的十六进制数的字符个数必须为偶数，除了是1 - 9 和 A(a) - F(f) 以外没有别的字符
****************************************************************************/
void AsciiToHex(unsigned char* pAscii, unsigned char* pHex, int nLen)
{
	if (nLen % 2)
		return;
	int nHexLen = nLen / 2;

	for (int i = 0; i < nHexLen; i++)
	{
		unsigned char Nibble[2];
		Nibble[0] = *pAscii++;
		Nibble[1] = *pAscii++;
		for (int j = 0; j < 2; j++)
		{
			if (Nibble[j] <= 'F' && Nibble[j] >= 'A')
				Nibble[j] = Nibble[j] - 'A' + 10;
			else if (Nibble[j] <= 'f' && Nibble[j] >= 'a')
				Nibble[j] = Nibble[j] - 'a' + 10;
			else if (Nibble[j] >= '0' && Nibble[j] <= '9')
				Nibble[j] = Nibble[j] - '0';
			else
				return;
		}   // for (int j = ...)
		pHex[i] = Nibble[0] << 4;   // Set the high nibble
		pHex[i] |= Nibble[1];   //Set the low nibble
	}   // for (int i = ...)
}

// 字节序转换
void EndianSwap(U8* pData, int startIndex, int length)
{
	int i, cnt, end, start;
	cnt = length / 2;
	start = startIndex;
	end = startIndex + length - 1;
	U8 tmp;
	for (i = 0; i < cnt; i++)
	{
		tmp = pData[start + i];
		pData[start + i] = pData[end - i];
		pData[end - i] = tmp;
	}
}

// 随机十六进制大数生成
const unsigned char allHexChar[17] = "0123456789abcdef";
void generateString(unsigned char* dest, const unsigned int len)
{
	unsigned int cnt, randNo;
	srand((unsigned int)time(NULL));

	for (cnt = 0; cnt < len; cnt++)
	{
		randNo = rand() % 16;
		*dest = allHexChar[randNo];
		dest++;
	}

	*dest = '\0';
}

Auth::Auth()
{
	tpool = new ThreadPool(4);
	request.timeout = 3000;
	time_offset = 0;
}

Auth::~Auth()
{
	logout();
}

inline bool Auth::signSendData(std::ostringstream& senddata)
{
	// 对表单数据进行 SM3摘要 和 SM2签名
	U8 senddata_hash[33] = { 0 };
	unsigned char senddata_sign[65] = { 0 }, random_hexstr[65] = { 0 }, random[33] = { 0 }, client_private_key[33] = { 0 }, client_public_key[65] = { 0 };
	unsigned int senddata_sign_len;
	generateString(random_hexstr, 64);
	AsciiToHex(random_hexstr, random, 64);
	AsciiToHex((unsigned char*)client_private_key_hexstr, client_private_key, 64);
	AsciiToHex((unsigned char*)client_public_key_hexstr, client_public_key, 128);
	std::string msg = senddata.str();
	SM3_Hash((U8*)msg.c_str(), strlen(msg.c_str()), senddata_hash, 32);
	if (0 == EccSign(senddata_hash, 32, random, 32, client_private_key, 32, senddata_sign, &senddata_sign_len))
	{
		// 签名附加回表单
		senddata << "&sign=";
		for (int i = 0; i < 64; i++)
			senddata << std::hex << std::setw(2) << std::setfill('0') << (int)senddata_sign[i];
		return true;
	}
	else
		return false;
}

inline bool Auth::verifyResponseJson(rapidjson::Document &d)
{
	// 验证响应是否合法
	std::ostringstream recvdata;
	struct NameComparator {
		bool operator()(const rapidjson::Value::Member& lhs, const rapidjson::Value::Member& rhs) const {
			return (strcmp(lhs.name.GetString(), rhs.name.GetString()) < 0);
		}
	};
	std::sort(d["payload"].MemberBegin(), d["payload"].MemberEnd(), NameComparator());
	recvdata << "gen_time=" << d["gen_time"].GetString();
	for (auto& m : d["payload"].GetObject())
		recvdata << "&" << m.name.GetString() << "=" << m.value.GetString();
	std::cout << "接收到的涉密表单：" << recvdata.str() << std::endl;
	U8 recvdata_hash[33] = { 0 };
	unsigned char server_public_key[65] = { 0 }, recvdata_sign[65] = { 0 };
	AsciiToHex((unsigned char*)d["sign"].GetString(), recvdata_sign, 128);
	AsciiToHex((unsigned char*)server_public_key_hexstr, server_public_key, 128);
	std::string msg = recvdata.str();
	SM3_Hash((U8*)msg.c_str(), strlen(msg.c_str()), recvdata_hash, 32); // 计算摘要
	return 0 == EccVerify(recvdata_hash, 32, server_public_key, 64, recvdata_sign, 64);
}

bool  Auth::login(std::string& username, std::string& password)
{
	int i = 5;
	while (!UpdateTimeOffsetHttp() && --i) Sleep(1000);
	std::ostringstream senddata;
	// 获取当前时间
	time_t gentime;
	time(&gentime);
	// gentime = NETWORK::_GET_POSIX_TIME();
	// gentime += 10;
	// 开始构造请求表单数据
	senddata << "HWID=" << getHWID();
	senddata << "&gen_time=" << gentime + time_offset;
	senddata << "&password=" << password;
	senddata << "&username=" << username;
	senddata << "&ver=" << menu_version;
	signSendData(senddata); // 对表单签名
	// 进行网络请求
	RestClient::Response response = RestClient::post("http://47.75.254.17/auth/login", "application/x-www-form-urlencoded", senddata.str(), &request);
	if (200 == response.code)
	{
		request.set_cookie(response.cookies);
		// 解析收到的JSON数据
		rapidjson::Document d;
		d.Parse(response.body.c_str());
		// 判断响应是否正常
		if (d.IsObject() && d["payload"].IsObject())
		{
			time_t recvtime;
			time(&recvtime);
			if (abs(recvtime - atoi(d["gen_time"].GetString())) < 15) // 验证响应是否在15秒以内新鲜生成
			{
				if (verifyResponseJson(d)) // 验签通过
				{
					// 判断响应并加载数据
					if (d["status"] == "suc")
					{
						currerr = std::string();
						loginuser = std::string(d["payload"]["user"].GetString());
						authkey = std::string(d["payload"]["auth"].GetString());
						authtype = std::string(d["payload"]["authtype"].GetString());
						return true;
					}
					else if (d["status"] == "err")
					{
						currerr = std::string(d["payload"]["message"].GetString());
						return false;
					}
					else
					{
						currerr = std::string("服务器状态错误");
						return false;
					}
				}
				else
				{
					currerr = std::string("非法的服务器");
					return false;
				}
			}
			else
			{
				currerr = std::string("服务器响应超时");
				return false;
			}
		}
		else
		{
			currerr = std::string("服务器响应不合法");
			return false;
		}
	}
	else
	{
		currerr = std::string("网络错误，请重试");
		return false;
	}
}

bool  Auth::is_authed()
{
	std::ostringstream senddata;
	// 获取当前时间
	time_t gentime;
	time(&gentime);
	// gentime = NETWORK::_GET_POSIX_TIME();
	// gentime += 10;
	// 开始构造请求表单数据
	senddata << "HWID=" << getHWID();
	senddata << "&gen_time=" << gentime + time_offset;
	senddata << "&ver=" << menu_version;
	signSendData(senddata); // 对表单签名
	// 进行网络请求
	RestClient::Response response = RestClient::post("http://47.75.254.17/auth/hb", "application/x-www-form-urlencoded", senddata.str(), &request);
	if (200 == response.code)
	{
		// 解析收到的JSON数据
		rapidjson::Document d;
		d.Parse(response.body.c_str());
		// 判断响应是否正常
		if (d.IsObject() && d["payload"].IsObject())
		{
			time_t recvtime;
			time(&recvtime);
			if (abs(recvtime - atoi(d["gen_time"].GetString())) < 15) // 验证响应是否在15秒以内新鲜生成
			{
				if (verifyResponseJson(d)) // 验签通过
				{
					// 判断响应并加载数据
					if (d["status"] == "suc")
					{
						currerr = std::string();
						return true;
					}
					else if (d["status"] == "err")
					{
						currerr = std::string(d["payload"]["message"].GetString());
						return false;
					}
					else
					{
						currerr = std::string("服务器状态错误");
						return false;
					}
				}
				else
				{
					currerr = std::string("非法的服务器");
					return false;
				}
			}
			else
			{
				currerr = std::string("服务器响应超时");
				return false;
			}
		}
		else
		{
			currerr = std::string("服务器响应不合法");
			return false;
		}
	}
	else
	{
		currerr = std::string("网络错误，请重试");
		return false;
	}
}

bool Auth::is_authed_rate_limited()
{
	if(!is_authed_cache)
		is_authed_cache = is_authed();
	else if (check_count++ > 300)
	{
		check_count = 0;
		tpool->enqueue([this] {this->is_authed_cache = this->is_authed(); });
	}
	return is_authed_cache;
}

bool  Auth::logout()
{
	std::ostringstream senddata;
	// 获取当前时间
	time_t gentime;
	time(&gentime);
	// gentime = NETWORK::_GET_POSIX_TIME();
	// gentime += 10;
	// 开始构造请求表单数据
	senddata << "HWID=" << getHWID();
	senddata << "&gen_time=" << gentime + time_offset;
	senddata << "&ver=" << menu_version;
	signSendData(senddata); // 对表单签名
	// 进行网络请求
	RestClient::Response response = RestClient::post("http://47.75.254.17/auth/logout", "application/x-www-form-urlencoded", senddata.str(), &request);
	if (200 == response.code)
	{
		request.set_cookie(response.cookies);
		// 解析收到的JSON数据
		rapidjson::Document d;
		d.Parse(response.body.c_str());
		// 判断响应是否正常
		if (d.IsObject() && d["payload"].IsObject())
		{
			time_t recvtime;
			time(&recvtime);
			if (abs(recvtime - atoi(d["gen_time"].GetString())) < 15) // 验证响应是否在15秒以内新鲜生成
			{
				if (verifyResponseJson(d)) // 验签通过
				{
					// 判断响应并加载数据
					if (d["status"] == "suc")
					{
						currerr = std::string();
						return true;
					}
					else if (d["status"] == "err")
					{
						currerr = std::string(d["payload"]["message"].GetString());
						return false;
					}
					else
					{
						currerr = std::string("服务器状态错误");
						return false;
					}
				}
				else
				{
					currerr = std::string("非法的服务器");
					return false;
				}
			}
			else
			{
				currerr = std::string("服务器响应超时");
				return false;
			}
		}
		else
		{
			currerr = std::string("服务器响应不合法");
			return false;
		}
	}
	else
	{
		currerr = std::string("网络错误，请重试");
		return false;
	}
}

const char* Auth::getUsername()
{
	return loginuser.c_str();
}

const char* Auth::getAuthKey()
{
	return authkey.c_str();
}

inline std::string Auth::getHWID()
{
	HW_PROFILE_INFOA hwid;
	GetCurrentHwProfileA(&hwid);
	
	U8 hwid_hash[33] = { 0 };
	SM3_Hash((U8*)hwid.szHwProfileGuid, strlen(hwid.szHwProfileGuid), hwid_hash, 32);

	char* ret = new char[65];
	memset(ret, 0, 65);
	std::ostringstream hwidstream;
	for (int i = 0; i < 32; i++)
		hwidstream << std::setiosflags(std::ios::uppercase) << std::hex << std::setw(2) << std::setfill('0') << (int)hwid_hash[i];

	std::string hwidstr = hwidstream.str();

	return hwidstr;
}

std::string Auth::getAuthType()
{
	return authtype;
}

const char* Auth::getErr()
{
	return currerr.c_str();
}

bool Auth::hasErr()
{
	return !currerr.empty();
}