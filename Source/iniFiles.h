#pragma once
#include "stdafx.h"

namespace StyleSaver {
	void SaveStyles();
	void LoadStyles();

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
}


