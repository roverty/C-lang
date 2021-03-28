#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[10] = {3,2,3,4,5,6,7,8,9,10};
	int *p1 = a;
	int *p2 = &a[5];
	printf("p1 apunta a %d\n", *p1);
	printf("p2 apunta a %d\n", *p2);
	p1 = p1 + 9;
	printf("p1 ahora apunta a %d\n", *p1);
	return 0;
}