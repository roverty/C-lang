#include <stdio.h>
int main(int argc, char const *argv[])
{
	int i;
	
	int arreglo[13]= {1,2,3,4,5,6,7,8,9,10,11,15,13};

	for (i= 0; i <13; ++i){
		printf("[%d]\n", arreglo[i]);
		if (arreglo[i]==3)
		{
			printf("fiz\n");

		}
		if(arreglo[i]==5){
			printf("boss\n");
		}
		//if(arreglo[i]%3==0 && arreglo[i]%5==0){
		if(arreglo[i]%15==0){
			printf("Fiz-boss\n");

		}

	}

	return 0;
}