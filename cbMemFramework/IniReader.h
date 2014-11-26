#pragma once

#include <iostream>
#include <fstream>


/* C++11 incoming!*/
struct _config_s {



	template<typename T>
	bool loadConfig(std::string& filename){
		std::ifstream filecfg(filename.c_str(), std::ifstream::binary );
		char buf[10]

		if (filecfg.good()){

			while (!filecfg.eof()){

				filecfg.read(&buf, 10);
				std::cerr << buf;
				
			}

		}


	}

};

typedef struct _config_s Config;


class IniReader
{
public:
	IniReader();
	virtual ~IniReader();
};

