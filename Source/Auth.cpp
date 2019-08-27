#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_ERRORS
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
	cout << (a.login(std::string("qzhsjz"), std::string("86.corrode")) ? "��¼�ɹ�" : "��¼ʧ��") << endl;
	cout << (a.is_authed() ? "��֤�ɹ�" : "��֤ʧ��") << endl;
	getchar();
	return 0;
}
**/

/************************************************************************
*   ���ܣ���һ��ʮ�������ֽڴ�ת���� ASCII ���ʾ��ʮ�����Ƶ��ַ���
*   ���������pHex    -- ʮ���������ֽڴ��׵�ַ
*            pAscii -- ת����� ASCII ���ʾ��ʮ�������ַ������׵�ַ
*            nLen    -- Ҫת����ʮ���������ĳ��ȣ��ֽ�����
*   ���������None
*   ע��  ת����Ľ��ȫ���Ǵ�д ASCII ��ʾ��ʮ��������
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
*   ���ܣ���һ�� ASCII ���ʾ��ʮ�������ַ���ת����ʮ�����Ƶ��ֽڴ�
*   ���������pAscii -- ת����� ASCII ���ʾ��ʮ�������ַ������׵�ַ
*            pHex   -- ʮ���������ֽڴ��׵�ַ
*            nLen   -- Ҫת���� ASCII ���ʾ��ʮ�������ַ����ĳ��ȣ��ֽ�����
*   ���������None
*   ע��  Ҫ������� ASCII ���ʾ��ʮ�����������ַ���������Ϊż����������1 - 9 �� A(a) - F(f) ����û�б���ַ�
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

// �ֽ���ת��
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

// ���ʮ�����ƴ�������
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
	
}

Auth::~Auth()
{
	
}

bool Auth::signSendData(std::ostringstream& senddata)
{
	// �Ա����ݽ��� SM3ժҪ �� SM2ǩ��
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
		// ǩ�����ӻر�
		senddata << "&sign=";
		for (int i = 0; i < 64; i++)
			senddata << std::hex << std::setw(2) << std::setfill('0') << (int)senddata_sign[i];
		return true;
	}
	else
		return false;
}

bool Auth::verifyResponseJson(rapidjson::Document &d)
{
	// ��֤��Ӧ�Ƿ�Ϸ�
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
	std::cout << "���յ������ܱ���" << recvdata.str() << std::endl;
	U8 recvdata_hash[33] = { 0 };
	unsigned char server_public_key[65] = { 0 }, recvdata_sign[65] = { 0 };
	AsciiToHex((unsigned char*)d["sign"].GetString(), recvdata_sign, 128);
	AsciiToHex((unsigned char*)server_public_key_hexstr, server_public_key, 128);
	std::string msg = recvdata.str();
	SM3_Hash((U8*)msg.c_str(), strlen(msg.c_str()), recvdata_hash, 32); // ����ժҪ
	return 0 == EccVerify(recvdata_hash, 32, server_public_key, 64, recvdata_sign, 64);
}

bool  Auth::login(std::string& username, std::string& password)
{
	std::ostringstream senddata;
	// ��ȡ��ǰʱ��
	time_t gentime;
	time(&gentime);
	// ��ʼ�������������
	senddata << "HWID=" << "testHWID";
	senddata << "&gen_time=" << gentime;
	senddata << "&password=" << password;
	senddata << "&username=" << username;
	senddata << "&ver=" << menu_version;
	signSendData(senddata); // �Ա�ǩ��
	// ������������
	RestClient::Response response = RestClient::post("http://127.0.0.1:8000/auth/login", "application/x-www-form-urlencoded", senddata.str(), &request);
	request.set_cookie(response.cookies);
	// �����յ���JSON����
	rapidjson::Document d;
	d.Parse(response.body.c_str());
	// �ж���Ӧ�Ƿ�����
	if (d.IsObject() && d["payload"].IsObject())
	{
		time_t recvtime;
		time(&recvtime);
		if (abs(recvtime - atoi(d["gen_time"].GetString())) < 2) // ��֤��Ӧ�Ƿ���2��������������
		{
			if (verifyResponseJson(d)) // ��ǩͨ��
			{
				// �ж���Ӧ����������
				if (d["status"] == "suc")
				{
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
					currerr = std::string("������״̬����");
					return false;
				}
			}
			else
			{
				currerr = std::string("�Ƿ��ķ�����");
				return false;
			}
		}
		else
		{
			currerr = std::string("��������Ӧ��ʱ");
			return false;
		}
	}
	else
	{
		currerr = std::string("��������Ӧ���Ϸ�");
		return false;
	}
}

bool  Auth::is_authed()
{
	std::ostringstream senddata;
	// ��ȡ��ǰʱ��
	time_t gentime;
	time(&gentime);
	// ��ʼ�������������
	senddata << "HWID=" << "testHWID";
	senddata << "&gen_time=" << gentime;
	senddata << "&ver=" << menu_version;
	signSendData(senddata); // �Ա�ǩ��
	// ������������
	RestClient::Response response = RestClient::post("http://127.0.0.1:8000/auth/hb", "application/x-www-form-urlencoded", senddata.str(), &request);
	request.set_cookie(response.cookies);
	// �����յ���JSON����
	rapidjson::Document d;
	d.Parse(response.body.c_str());
	// �ж���Ӧ�Ƿ�����
	if (d.IsObject() && d["payload"].IsObject())
	{
		time_t recvtime;
		time(&recvtime);
		if (abs(recvtime - atoi(d["gen_time"].GetString())) < 2) // ��֤��Ӧ�Ƿ���2��������������
		{
			if (verifyResponseJson(d)) // ��ǩͨ��
			{
				// �ж���Ӧ����������
				if (d["status"] == "suc")
				{
					return true;
				}
				else if (d["status"] == "err")
				{
					currerr = std::string(d["payload"]["message"].GetString());
					return false;
				}
				else
				{
					currerr = std::string("������״̬����");
					return false;
				}
			}
			else
			{
				currerr = std::string("�Ƿ��ķ�����");
				return false;
			}
		}
		else
		{
			currerr = std::string("��������Ӧ��ʱ");
			return false;
		}
	}
	else
	{
		currerr = std::string("��������Ӧ���Ϸ�");
		return false;
	}
}

bool  Auth::logout()
{
	std::ostringstream senddata;
	// ��ȡ��ǰʱ��
	time_t gentime;
	time(&gentime);
	// ��ʼ�������������
	senddata << "HWID=" << "testHWID";
	senddata << "&gen_time=" << gentime;
	senddata << "&ver=" << menu_version;
	signSendData(senddata); // �Ա�ǩ��
	// ������������
	RestClient::Response response = RestClient::post("http://127.0.0.1:8000/auth/logout", "application/x-www-form-urlencoded", senddata.str());
	request.set_cookie(response.cookies);
	// �����յ���JSON����
	rapidjson::Document d;
	d.Parse(response.body.c_str());
	// �ж���Ӧ�Ƿ�����
	if (d.IsObject() && d["payload"].IsObject())
	{
		time_t recvtime;
		time(&recvtime);
		if (abs(recvtime - atoi(d["gen_time"].GetString())) < 2) // ��֤��Ӧ�Ƿ���2��������������
		{
			if (verifyResponseJson(d)) // ��ǩͨ��
			{
				// �ж���Ӧ����������
				if (d["status"] == "suc")
				{
					return true;
				}
				else if (d["status"] == "err")
				{
					currerr = std::string(d["payload"]["message"].GetString());
					return false;
				}
				else
				{
					currerr = std::string("������״̬����");
					return false;
				}
			}
			else
			{
				currerr = std::string("�Ƿ��ķ�����");
				return false;
			}
		}
		else
		{
			currerr = std::string("��������Ӧ��ʱ");
			return false;
		}
	}
	else
	{
		currerr = std::string("��������Ӧ���Ϸ�");
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

const char* Auth::getErr()
{
	return currerr.c_str();
}