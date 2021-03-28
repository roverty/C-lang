#include<stdio.h>
/*
struct Coord{
	int x;
	int y;
	//int z = 0; // NO se pueden inicializar variables
	char z;
};

typedef struct Coord Cordena;*/

typedef struct Coord {
	int x;
	int y;
} Cordena;

int main(){
	struct Coord coord1;
	// Primera forma de inicializar una estructura
	coord1.x = 1;
	coord1.y = 2;
	
	// Segunda forma de inicializar una estructura
	struct Coord coord2 = {1,2,'a'};
	
	// Tercera forma de inicializar una estructura
	struct Coord coord3 = {.y=2,.x = 1};
	
	// Cuarta forma de inicializar una estructura 
	//(Haciendo una copia de un estructura previa
	
	struct Coord coord4 = coord3;
	
	printf("coord4.x = %d\n",coord4.x);
	printf("coord4.y = %d\n",coord4.y);
	
	Cordena coord5 = {-5,-6};
	printf("coord5.x = %d\n",coord5.x);
	printf("coord5.y = %d\n",coord5.y);
	
	
}
