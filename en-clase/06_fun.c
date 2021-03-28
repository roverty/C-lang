#include<stdio.h>
#include<stdlib.h>

int** matrix_new(int,int);
void matrix_init(int **,int,int);
void matrix_print(int**,int,int);

int main(){
	
	int** mat; // Este doble apuntador va almacenar la matrix
	// la fila y la col se le pueden pedir al usuario
	int fila = 5;
	int col = 5;
	int i,j;
	i = j = 0;
	mat = matrix_new(fila,col);
	
	matrix_init(mat,fila,col);
	
	matrix_print(mat,fila,col);
	
	printf("\n mat[1][2] = %d",*(*(mat+1)+2));
}

int** matrix_new(int fila,int col){
	int **mat;
	mat = (int **)malloc(fila*sizeof(int*));
	for(int i=0;i<fila;i++)
		mat[i]  = (int*)malloc(col*sizeof(int));
	return mat;
	
}

void matrix_init(int** mat,int fila,int col){
	
	for(int i = 0;i<fila;i++){
		for(int j=0;j<col;j++){
			mat[i][j] = rand()%50;
		}
	}
}

void matrix_print(int** mat,int fila,int col){
	
	printf("Los valores de la matriz son:\n");
	for(int i = 0;i<fila;i++){
		printf("\n");
		for(int j=0;j<col;j++){
			///printf("%d\t",mat[i][j]);
			printf("%d\t",*(*(mat+i)+j));
		}
	}
}
