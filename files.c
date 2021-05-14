#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	char ch;
	int a[3][3];
	int b[3][3];
	int suma[3][3];
	int mult[3][3];
	FILE *fp;
	
	fp = fopen("arch.txt", "r"); // read mode

	if (fp == NULL)
	{
	   perror("Error while opening the file.\n");
	   exit(EXIT_FAILURE);
	}

	do{

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				fscanf(fp, "%1d", &a[i][j]);

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				fscanf(fp, "%1d", &b[i][j]);
	}while((ch = fgetc(fp)) != EOF);
	fclose(fp);

	printf("Imprimiendo A...\n");
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j)
			printf("%d\t", a[i][j]);
		printf("\n");
	}

	printf("Imprimiendo B...\n");
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j)
			printf("%d\t", b[i][j]);
		printf("\n");
	}

	/*

		AQUI VA LA SECCION DE CODIGO PARA 
		SUMAR Y MULT


	*/

	printf("Guardando matriz...\n");
	fp = fopen("res.txt", "w"); // read mode
	
	fprintf(fp, "El resultado de la suma es: \n");
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			fprintf(fp, "%d\t", suma[i][j]);
		}
		fprintf(fp, "\n");
	}

	fprintf(fp, "El resultado de la mult es: \n");
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			fprintf(fp, "%d\t", mult[i][j]);
		}
		fprintf(fp, "\n");
	}

	fclose(fp);

	return 0;
}