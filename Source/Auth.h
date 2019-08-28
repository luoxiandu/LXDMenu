#pragma once
#include <string>
#include <iostream>


#include "Auth/restclient-cpp/restclient.hpp"
#include "Auth/rapidjson/document.h"
#include "Auth/rapidjson/writer.h"
#include "Auth/rapidjson/stringbuffer.h"
#include "Auth/ThreadPool.h"


class Auth
{
private:
	bool is_authed_cache;
	int check_count;
	RestClient::Request request;
	ThreadPool* tpool;
	std::string loginuser, authkey, currerr;
	bool verifyResponseJson(rapidjson::Document& d);
	bool signSendData(std::ostringstream& senddata);

public:
	Auth();
	~Auth();
	bool login(std::string& username, std::string& password);
	bool is_authed();
	bool is_authed_rate_limited();
	bool logout();
	const char* getUsername();
	const char* getAuthKey();
	const char* getHWID();
	const char* getErr();
	bool hasErr();
};

extern int menu_version;