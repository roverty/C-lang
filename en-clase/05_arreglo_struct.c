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
	
	Empleado personas[2];
	
	for(int i=0; i<2;i++){
		printf("Dame los datos la persona %d\n",i+1);
		printf("Nombre: ");
		scanf("%s",personas[i].nombre);
		personas[i].apellidos = (char*)malloc(sizeof(char));
		printf("Apellido: ");
		scanf("%s",personas[i].apellidos);
		printf("Edad: ");
		scanf("%d",&personas[i].edad);
	}
	
	for(int i=0; i<2;i++){
		printf("Los datos la persona %d\n",i+1);
		printf("Nombre: %s ",personas[i].nombre);
		//printf("Apellido: %s",personas[i].apellidos);
		printf("Edad: %d\n",personas[i].edad);
	}
	
	for(int i =0 ;i<2; i++){
		free(personas[i].apellidos);
	}
		
	return 0;
}
