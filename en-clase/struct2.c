#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Carros
{
	int annio;
	char *modelo;
	float precio;
} Carros;

typedef struct Persona{
	char nombre[50];
	char *apellidos;
	int edad;
	Carros carro;
	float *sueldo;
}Persona;


int main(int argc, char const *argv[])
{
	Persona p1;
	//p1.nombre = "Rodrigo"; //Asi falla
	strcpy(p1.nombre,"Rodrigo");
	//p1.apellidos = "Francisco Pablo";
	p1.edad = 12;
	p1.carro.annio = 1998;

	printf("La informacion del usuario es:\n");
	printf("nombre : %s\n", p1.nombre);
	printf("apellidos : %s\n", p1.apellidos);
	printf("edad: %d\n", p1.edad);
	printf("Annio del CARRO: %d\n", p1.carro.annio);

	//p1.sueldo = 12.5; //Falla
	// no es necesario pero debe hacerse
	p1.sueldo = (float*)malloc(sizeof(float)); 
	*p1.sueldo = 12.5;
	printf("sueldo: %.2f\n", *p1.sueldo);
	free(p1.sueldo);

	// Arreglos con apuntadores

	Persona personas[3];

	for (int i = 0; i < 2; ++i)
	{
		printf("Para la persona %d\n", i+1);
		printf("nombre: ");
		scanf("%s",personas[i].nombre);
		fflush(stdin);
		printf("apellidos: ");
		personas[i].apellidos  = (char*)malloc(sizeof(char*));
		// Sin la linea de arriba, crashea, por qué? 
		// Respuesta: Se quiere guardar en un apuntador que apunta a NULL
		scanf("%s",personas[i].apellidos);
		fflush(stdin);
	}

	printf("\nImprimiendo datos de las personas\n");
	for (int i = 0; i < 2; ++i)
	{
		printf("******Persona %d**********\n", i+1);
		printf("nombre: %s\n",personas[i].nombre);
		printf("apellidos: %s\n",personas[i].apellidos);
	}

	return 0;
}