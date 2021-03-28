#include <stdio.h>

int main(int argc, char const *argv[])
{
	char cad[] = "HOLA";
	int i = 0;
	do{
		printf("cad[%d] = %d\n",i, cad[i]);
		i++;
	}while(cad[i] != '\0');

	return 0;
}