#include <stdio.h>

struct Coord
{ 
int x, y; 
}; 

typedef struct Coord Cordenada;

typedef struct Point 
{ 
int x, y; 
} Punto;

int main(int argc, char const *argv[])
{
	struct Point punto1; 
	Punto punto2;
	struct Coord coord1;
	Cordenada coord2;

	coord2.x = 1;
	coord2.y = 2;

	Cordenada coord3 = {1,2}; // x= 1, y = 2
	//Hacer los print correspondientes
	Cordenada coord4 = {.y=1,.x=2}; // x= 2, y = 1
	//Hacer los print correspondientes

	Cordenada coord5;
	coord5 = coord4; // Se pueden hacer copias
	//Hacer los print correspondientes

	// Uso de apuntadores

	Cordenada *ptr = &coord5;

	(*ptr).x = 3;
	ptr->y = 4;


	return 0;
}