#include "MemClass.h"


Mem::Mem(GameProcess& a){
	gp = a;
}

/*
initialize a naked function 
store the last stack  to EBP
till finish
*/
void Mem::init_function(){

	__asm{
		push ebp
		mov ebp, esp

		}
}

/*
This function is to finalize naked functions
just return stack back and return (returns nothing)
*/
void Mem::finalize_function(){
	__asm{
		push edx
		ret
	}
}


DWORD Mem::getBaseAddress(HWND window, DWORD pid){
	MODULEENTRY32 module;
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	module.dwSize = sizeof(MODULEENTRY32);
	Module32First(snapshot, &module);
	DWORD base_address = (DWORD)module.modBaseAddr;

	return base_address;


}