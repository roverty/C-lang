#include <stdio.h>

void holaMundo(){
	printf("Hola mundo desde una función\n");
	return ; // Es opcional ponerlo
}


int main()
{
	printf("Hola mundo\n");
	//Llamando a la función hola mundo
	holaMundo();
	return 0;
}