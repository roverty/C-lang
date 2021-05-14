#include <stdio.h>
#include <stdlib.h>
#define _ISOC99_SOURCE
#include "Operations.h"
#include "Menu.h"
void getNumbers(int *num1,int *num2){
	printf("Num1: ");
	scanf("%d",num1);
	printf("\nNum2: ");
	scanf("%d",num2);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int num1=0;
	int num2=0;
	int resultado;
	char op=menu();
	do{
		switch(op){
			case 'a':
				getNumbers(&num1,&num2);
				sum(num1,num2,&resultado);
				printf("%d+%d=%d\n\n", num1,num2,resultado);
				break;
			case 'b':
				getNumbers(&num1,&num2);
				substract(num1,num2,&resultado);
				printf("%d-%d=%d\n\n", num1,num2,resultado);
				break;
			case 'c':
				getNumbers(&num1,&num2);
				multiply(num1,num2,&resultado);
				printf("%d*%d=%d\n\n", num1,num2,resultado);
				break;
			case 'd':
				getNumbers(&num1,&num2);
				if (division(num1,num2,&resultado)==TRUE)
					printf("%d/%d=%d\n\n",num1,num2, resultado);
				else printf("No puedes dividir entre cero\n");
				break;
			default:
				printf("Opcion invalida\n");
				break;
		}
		op=menu();
	}while(op!='e');
	printf("ADIOS...\n");
	return 0;
}
