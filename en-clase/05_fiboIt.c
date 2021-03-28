#include <stdio.h>

void fibo(int);

int main(int argc, char const *argv[])
{
	printf("La serie de fibo hasta el termino 6 es:\n");
	fibo(6);
	return 0;
}

void fibo(int n){
	int x = 0;
	int y = 1;
	int suma ;

	if (n == 1)
	{
		printf("0\n");
	}else if(n==2){
		printf("0 1\n");
	}

	for (int i = 2; i < n; ++i)
	{
		suma = x + y;
		printf("%d\n", suma);
		x = y;
		y = suma;
	}

}