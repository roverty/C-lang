#include <stdio.h>
// Paso por valor y paso por referencia

//Primero paso por valor
void sumar1(int numero);

int main()
{
	int numero = 45;
	sumar1(numero);
	printf("El valor del número en la función main es %d\n", numero);
	return 0;
}

void sumar1(int numero){
	//numero = numero +1;
	//numero +=1;
	numero++;
	printf("El valor del número en la función sumar1 es %d\n", numero);
}
