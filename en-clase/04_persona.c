#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Carro{
	int annio;
	float precio;
} Carro;

typedef struct Empleado{
	char nombre[50];
	char *apellidos;
	int edad;
	float *sueldo;
	Carro carro;
} Empleado;

int main(){
	
	Empleado p1;
	p1.edad = 15;
	p1.sueldo = (float*)malloc(sizeof(float));
	*p1.sueldo = 10.80;
	p1.apellidos = "Medina Garcia";
	strcpy(p1.nombre,"Rodrigo");
	
	printf("El nombre del empleado es %s\n",p1.nombre);	
	printf("Los apellids del empleado son %s\n",p1.apellidos);
	printf("La edad del empleado es %d annios \n",p1.edad);
	printf("El sueldo del empleado es %f \n",*p1.sueldo);
	
	p1.carro.annio = 2019;
	p1.carro.precio = 100000.89;
	
	printf("El annio del carro del empleado Rodrigo es: %d \n",p1.carro.annio);
	
	free(p1.sueldo);
	
	return 0;
}
