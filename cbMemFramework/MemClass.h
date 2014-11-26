#pragma once

#include <Windows.h>
#include <TlHelp32.h> 
#include <memory>
#include <iostream>
#include "GameProcess.h"
using namespace std;





enum OPERATOR {
	ADD,
	SUB,
	DIV,
	MUL,
	OR,
	AND,
	XOR,
	XAND,
	SHIFT_L,
	SHIFT_R
};


class MemoryFramework {


private:
	void init_function();
	void finalize_function();

	GameProcess gp;



public:
	MemoryFramework(GameProcess& process);
	MemoryFramework();
	~MemoryFramework();



	template<typename T>
	T ReadMemory(DWORD address){
		DWORD value;
		T ret_value;

		ReadProcessMemory(gp.getGameHandle(), (LPVOID)address, &value, sizeof(value), 0);


		ret_value = static_cast<T>(value);

		return ret_value;
		

	}

	template<typename T>
	T WriteMemory(DWORD address, const T& value){

	}




};