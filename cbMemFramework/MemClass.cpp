#include "MemClass.h"


MemoryFramework::MemoryFramework(GameProcess& a){
	gp = a;
}

MemoryFramework::~MemoryFramework(){
	delete &gp;
}


/*
initialize a naked function 
store the last stack  to EBP
till finish
*/
void MemoryFramework::init_function(){

	__asm{
		push ebp
		mov ebp, esp

		}
}

/*
This function is to finalize naked functions
just return stack back and return (returns nothing)
*/
void MemoryFramework::finalize_function(){
	__asm{
		push edx
		ret
	}
}


