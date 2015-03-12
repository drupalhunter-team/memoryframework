#include "MemClass.h"


MemoryFramework::MemoryFramework(GameProcess& a){
	gp = a;
}

MemoryFramework::~MemoryFramework(){
	delete &gp;
}





