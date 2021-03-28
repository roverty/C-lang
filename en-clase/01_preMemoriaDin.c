#include<stdio.h>
/*Primera solucion para no desperdiciar memoria.*/
int main(){
	int tama=2;
	printf("Ingrese el tamaño del arreglo: ");
	scanf("%d",&tama);
	int arreglo[tama]; //Memoria estatica
	int i = 0;
	for(;i<tama;i++){
		arreglo[i] = i+1;
	}
	int j = 0;
	for(;j<tama;j++){
		printf("%d, ",arreglo[j]);
	}
	
	return 0;
}
