/*Programa que convierte de bin a deci y viceversa.*/
#include <stdio.h>
#include <math.h>
void decToBin(int num){
	int bin[20];
	int pos=0;
	while(num>1){
		bin[pos] = num%2;pos++;
		num = num/2;
	}
	bin[pos]=1;
	printf("El numero es: ");
	for (int j = pos; j >= 0; --j)	{
		printf("%d",bin[j] );
	}pos=0;
}
void binToDec(int num){
	int bin[20];
	int dec=0;
	int pos=0;
	while(num>0){
		bin[pos]= num%10; pos++;
		num/=10;
	}
	for (int i = 0; i < pos; ++i)
		dec += pow(2,i)*(bin[i]);
	pos=0;
	printf("El número es %d \n",dec);
	
}
int main(int argc, char const *argv[]){
	int op;
	int num;
	do{
		printf("Bienvenido al conversor\n");
		printf("\t1) Convertir binario a decimal\n");
		printf("\t2) Convertir de decimal a binario\n");
		printf("\t3) Salir\n");
		printf("Su opción: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Conversor de binario a decimal\n");
				printf("Ingrese un num en binario: ");
				scanf("%d",&num);
				binToDec(num);
				break;
			case 2:
				printf("Conversor de decimal a binario\n");
				printf("Ingrese un num en decimal: ");
				scanf("%d",&num);
				decToBin(num);
				break;
			case 3:
				printf("Ha elegido a opción de salir :(\n");
				break;
			default:
				printf("Opcion no válida, intente de nuevo...\n");
				break;
		}
		printf("\n");
	}while(op!=3);
	printf("Hasta luego...\n");
  
	return 0;
}