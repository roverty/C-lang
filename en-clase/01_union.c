#include<stdio.h>

union Coordenada {
	int x;
	int y;
};

int main(){
	union Coordenada coord1;
	
	// Usando el operador punto
	coord1.x = 1;
	printf("coordena en x = %d\n",coord1.x);
	coord1.y = 2;
	printf("coordena en y = %d\n",coord1.y);
	
	printf("Analicemos ... \n");
	printf("coordena en x = %d\n",coord1.x);
	printf("coordena en y = %d\n",coord1.y);
	
	//Uso de apuntadores.
	union Coordenada* ptr_coord;
	ptr_coord = &coord1;
	printf("Coordenada en y (usando apuntadores):%d\n",(*ptr_coord).x );
	printf("Coordenada en y (usando apuntadores):%d\n",ptr_coord->x );
	
}
