#include <stdio.h>

int variable=5;


int suma(int numero1,int numero2);
float division(int ,int );

int main()
{
	//resultado = 5/2; //Marca error
	printf("Mi calculadora\n");
	printf("Usando la operación de suma\n");
	int num1 = 13;
	int num2 = 9;
	int resultado = suma(num1,num2);
	printf("El resultado de la suma de 5+4 es %d\n", resultado);
	float resultado2 = division(10,2);
	printf("El resultado de la divison de 10/2 es %f\n",resultado2);
	
	return 0;
}

int suma(int numero1,int numero2){
	int res;
	res = numero1 + numero2+variable;
	return res;
}

float division(int dividendo,int divisor){
	return dividendo/divisor;
}



