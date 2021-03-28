#include<stdio.h>

int main(){
	int num = 10;
	int *ptr1;
	int **ptr2;
	
	ptr1 = &num;
	ptr2 = &ptr1;
	
	printf("El valor de num es %d\n",num);
	printf("El valor de num es %d\n",*ptr1);
	printf("El valor de num es %d\n",**ptr2);
	
	printf("El valor de num es %p\n",&num);
	printf("El valor de num es %p\n",num);
	printf("La direccion de mem. de num es %p\n",&(*ptr1));
	printf("La direccion de mem. de num es %p\n",ptr1);
}
