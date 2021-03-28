#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int matriz[2][3] = {{1,2,3},{4,5,6}};
	
	int** mat; // Este doble apuntador va almacenar la matrix
	// la fila y la col se le pueden pedir al usuario
	int fila = 5;
	int col = 5;
	mat = (int **)malloc(fila*sizeof(int*));
	int i = 0,j = 0;
	for(i=0;i<fila;i++){
		mat[i] = (int*)malloc(col*sizeof(int));
	}
	for(i = 0;i<fila;i++){
		for(j=0;j<col;j++){
			mat[i][j] = j;
		}
	}
	printf("Los valores de la matriz son:\n");
	for(i = 0;i<fila;i++){
		printf("\n");
		for(j=0;j<col;j++){
			printf("%d\t",mat[i][j]);
		}
	}
	
	printf("\n mat[1][2] = %d",*(*(mat+1)+2));
}
