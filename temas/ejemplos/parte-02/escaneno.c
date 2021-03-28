#include <stdio.h>

int main()
{
	//char cadena[8] = "Hola Mundo";
	//printf("%s \n",cadena);

	int x;
	printf("Ingresa un número entero: ");
	scanf("%d",&x);
	printf("\nEl numero ingreado es: %d\n",x);

	char cadena[20];
	printf("Ingrsa una cadena: ");
	scanf("%s",cadena);

	printf("La cadena es %s\n", cadena);

	return 0;
}