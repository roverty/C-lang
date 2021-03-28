#include<stdio.h>
// Para trabajar con memoria dinamica
#include<stdlib.h>
/* Funciones para mem dinamica
* malloc
* calloc
* realloc
* free
*/
int main(){
	
	int tama=6;
	int* ptr;
	
	//ptr = malloc(20); Asi no porque puede haber errores
	ptr = (int*)malloc(tama*sizeof(int));
	
	if(ptr == NULL){
		printf("La memoria no puedo ser asignada");
		//return 1;
		exit(0);
	} 
	
	int i = 0;
	for(i=0;i<tama;i++){
		ptr[i] = i+1;
	}
	
	int j = 0;
	for(;j<tama;j++){
		printf("%d, ",ptr[j]);
	}
	printf("\nEl segundo elemento de mi arreglo es %d\n",*(ptr+2));
	
	printf("Impriendo el arreglo con notacion de apuntadores\n");
	
	for(j=0;j<tama;j++){
		printf("%d, ",*(ptr+j));
	}
	
	free(ptr);
	
	return 0;
}

