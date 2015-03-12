#pragma once

#include <windows.h>
#include <iostream>
#include <cstdio>

class Config
{
public:
	Config::Config(char* filepath);
	~Config();
	char* ini_path;
	DWORD baseaddress;
	char* exe_name;
	BOOL init_cfg(char* filepath);


private:
	void createNewCFG();
};

