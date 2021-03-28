#include <stdio.h>

long factorial(int num);

int main(int argc, char const *argv[])
{
	printf("El factorial de 36 es %ld\n", factorial(25));
	return 0;
}

long factorial(int num){
	if (num == 0) //caso base
		return 1;
	else
		return num*factorial(num-1);
}