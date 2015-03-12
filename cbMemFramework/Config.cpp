#include "Config.h"
#include "Global.h"

Config::Config(char* filepath)
{
	baseaddress = 0;
	if (!init_cfg(filepath)){
		createNewCFG();
	}
}


Config::~Config()
{
	
}


BOOL Config::init_cfg(char* filepath)
{
	FILE* fp = fopen(filepath, "rb");
	BOOL result = FALSE;

	if (fp == NULL){
		PRINT_DEBUG("Ini Not Found");
		result = TRUE;
	}

	fclose(fp);
	return result;



}


void Config::createNewCFG(){
	
	CreateFileW(L"config.ini", FILE_GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	WritePrivateProfileSectionW(L"config", L"path", L"");
	WritePrivateProfileSectionW(L"config", L"base", 0);
	WritePrivateProfileSectionW(L"config", L"exename", L"");

	




}