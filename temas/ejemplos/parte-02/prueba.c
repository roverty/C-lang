#include <stdio.h>
#include <stdbool.h>
int main(){
	printf("El almacenamiento en memoria de un int es %d\n", sizeof(int) );	
	printf("El almacenamiento en memoria de un float es %d\n", sizeof(float) );
	printf("El almacenamiento en memoria de un float es %d\n", sizeof(double) );	
	printf("El almacenamiento en memoria de un long long int es %d\n", sizeof(long long) );	

	printf("Intentando romper enteros\n");
	//int variableEntera = 2147483648321;

	///printf("\nEl entero más grande es: %d\n", variableEntera);

	unsigned int variableSinSigno = -15;
	printf("Var sin sino %u\n", variableSinSigno);

	float variableFlotante = 3.4E+39;
	printf("El valor de la var float es %f\n",variableFlotante );

	bool condicion = false;

	if (condicion == true )
	{
		printf("Hola soy Rodrigo\n");
	}else{
		printf("Hola soy Carlos\n");
	}

}