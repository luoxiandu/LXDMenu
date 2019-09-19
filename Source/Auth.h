#pragma once
#include <string>
#include <iostream>


#include "Auth/restclient-cpp/restclient.hpp"
#include "Auth/rapidjson/document.h"
#include "Auth/rapidjson/writer.h"
#include "Auth/rapidjson/stringbuffer.h"
#include "Auth/ThreadPool.h"
#pragma execution_character_set("utf-8")

class Auth
{
private:
	bool is_authed_cache;
	int check_count;
	int fail_count;
	int time_offset;
	ThreadPool* tpool;
	RestClient::Request request;
	std::string loginuser, authkey, authtype, currerr;
	bool verifyResponseJson(rapidjson::Document& d);
	bool signSendData(std::ostringstream& senddata);
	bool UpdateTimeOffsetHttp();

public:
	Auth();
	~Auth();
	int curTime;
	bool login(std::string& username, std::string& password);
	bool is_authed();
	bool is_authed_rate_limited();
	bool logout();
	const char* getUsername();
	const char* getAuthKey();
	std::string getAuthType();
	std::string getHWID();
	const char* getErr();
	bool hasErr();
};

extern std::string menu_version;