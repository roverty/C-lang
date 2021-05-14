#include <stdio.h>

int main(int argc, char const *argv[])
{
	int opcion,i;
	int x=0 ,y=1, z;
	printf("Ingrese la posicion para calcular la serie de fibonacci");
	scanf("%d",&opcion);
	if(opcion==1){
		printf("0");
	}
	if(opcion==2){
		printf("0 ,1");
	}
	if(opcion>=3){
		printf("0\n");
		printf("1\n");
	for(i=0;i<=opcion-3;i++){
		z=x+y;
		x=y;
		y=z;

		printf("%d\n", z);



	}
}

	return 0;
}