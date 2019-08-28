#pragma once
#include <string>
#include <iostream>


#include "Auth/restclient-cpp/restclient.hpp"
#include "Auth/rapidjson/document.h"


class Auth
{
private:
	RestClient::Request request;
	std::string loginuser, authkey, currerr;
	bool verifyResponseJson(rapidjson::Document& d);
	bool signSendData(std::ostringstream& senddata);

public:
	Auth();
	~Auth();
	bool login(std::string& username, std::string& password);
	bool is_authed();
	bool logout();
	const char* getUsername();
	const char* getAuthKey();
	const char* getErr();
};

extern int menu_version;