#include<stdio.h>

int main(){
    int tama;
    printf("Tama arreglo: ");
    scanf("%d",&tama);
    int arreglo[tama];
    printf("Ingrese %d al azar\n", tama);
    for (int i = 0; i < tama; ++i)
    {
    	printf("arreglo[%d]: ", i);
    	scanf("%d",&arreglo[i]);
    }

    printf("Los valores ingresados son: \n");
    for (int i = 0; i < tama; ++i)
    {
    	printf("arreglo[%d] = %d\n",i,arreglo[i] );
    }
    return 0;
}
