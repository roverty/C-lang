#include <stdio.h>

int main()
{
	typedef enum {falso,verdadero} bool;

	bool condicion = falso;

	if (condicion == verdadero )
	{
		printf("Hola soy Rodrigo\n");
	}else{
		printf("Hola soy Carlos\n");
	}

	return 0;
}