#include<stdio.h>
#include<stdlib.h>
#include "reloj.h"
int main(){
	
	Reloj *casio;
	casio = Reloj_New(11,40);
	Reloj_Print(casio);
	Reloj_Delete(casio);
	
	return 0;
}

