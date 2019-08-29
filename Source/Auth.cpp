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

int menu_version = 1.0;

const char* client_private_key_hexstr = "D2F58410E5A3B13BD25A89574C5AEB771042E6403C8F55F81309D593D3071B83";
const char* server_public_key_hexstr = "86D2E8E41C9A1BECFD336BBE1D3C888C60AF0B9D1C483441007494B712657A70BA1CC8BB5CE850141FF8E12F4ABB5266A51C442EAA3408041A18A0A114154376";
const char* client_public_key_hexstr = "A905EE38C83C2DDBC528396B0DA2341E7FFE7418B0775E35E54D2345CF1D1C5E7E4BEC2E32384C743A2932F261B493CCDCDA5CDDC3C59F8C034EBE4D6DA15801";

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
	std::ostringstream senddata;
	// 获取当前时间
	time_t gentime;
	time(&gentime);
	// 开始构造请求表单数据
	senddata << "HWID=" << getHWID();
	senddata << "&gen_time=" << gentime;
	senddata << "&password=" << password;
	senddata << "&username=" << username;
	senddata << "&ver=" << menu_version;
	signSendData(senddata); // 对表单签名
	// 进行网络请求
	RestClient::Response response = RestClient::post("http://39.97.241.22:8000/auth/login", "application/x-www-form-urlencoded", senddata.str(), &request);
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
			if (abs(recvtime - atoi(d["gen_time"].GetString())) < 3) // 验证响应是否在3秒以内新鲜生成
			{
				if (verifyResponseJson(d)) // 验签通过
				{
					// 判断响应并加载数据
					if (d["status"] == "suc")
					{
						currerr = std::string();
						loginuser = std::string(d["payload"]["user"].GetString());
						authkey = std::string(d["payload"]["auth"].GetString());
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
	// 开始构造请求表单数据
	senddata << "HWID=" << getHWID();
	senddata << "&gen_time=" << gentime;
	senddata << "&ver=" << menu_version;
	signSendData(senddata); // 对表单签名
	// 进行网络请求
	RestClient::Response response = RestClient::post("http://39.97.241.22:8000/auth/hb", "application/x-www-form-urlencoded", senddata.str(), &request);
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
			if (abs(recvtime - atoi(d["gen_time"].GetString())) < 3) // 验证响应是否在3秒以内新鲜生成
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
	else if (check_count++ > 2000)
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
	// 开始构造请求表单数据
	senddata << "HWID=" << getHWID();
	senddata << "&gen_time=" << gentime;
	senddata << "&ver=" << menu_version;
	signSendData(senddata); // 对表单签名
	// 进行网络请求
	RestClient::Response response = RestClient::post("http://39.97.241.22:8000/auth/logout", "application/x-www-form-urlencoded", senddata.str());
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
			if (abs(recvtime - atoi(d["gen_time"].GetString())) < 3) // 验证响应是否在3秒以内新鲜生成
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

const char* Auth::getHWID()
{
	HW_PROFILE_INFOA hwid;
	GetCurrentHwProfileA(&hwid);
	
	U8 hwid_hash[33] = { 0 };
	SM3_Hash((U8*)hwid.szHwProfileGuid, strlen(hwid.szHwProfileGuid), hwid_hash, 32);

	std::ostringstream hwidstream;
	for (int i = 0; i < 32; i++)
		hwidstream << std::hex << std::setw(2) << std::setfill('0') << (int)hwid_hash[i];

	return hwidstream.str().c_str();
}

const char* Auth::getErr()
{
	return currerr.c_str();
}

bool Auth::hasErr()
{
	return !currerr.empty();
}