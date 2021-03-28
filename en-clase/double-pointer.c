#include <stdio.h>
#include <stdlib.h>

void initMatrix(int**);
int ** allocateMatrix(int,int);

int main(int argc, char const *argv[])
{

	int **mat = allocateMatrix(5,5);

	initMatrix(mat);

	printf("Los valores de la matriz son: \n");
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("mat[%d][%d] = %d\n", i,j, *(*(mat + i) + j));
		}
	}
	free(mat);

	return 0;
}

int ** allocateMatrix(int row, int col){
	int **mat;			// integer double pointer
	
	mat = malloc(row*sizeof(int*));
	for (int i=0;i<row;i++)
		mat[i]= (int*)malloc(col*sizeof(int));
	
	return mat;
}

void initMatrix(int ** mat){

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			mat[i][j] = j;
		}
	}
}