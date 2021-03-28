#include <stdio.h>

int fibo(int n);

int main(int argc, char const *argv[])
{
	printf("El 4 termino de la serie es %d\n", fibo(4));
	return 0;
}

int fibo(int n){
	if (n == 0)		
		return 0;
	else if(n == 1)
		return 1;
	else if( n == 2)
		return 1;
	else 
		return fibo(n-1)+fibo(n-2);
}