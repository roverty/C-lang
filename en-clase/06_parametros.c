#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (argc >= 2)
	{
		printf("Los argumentos del usuario son: \n");
		for (int i = 0; i < argc; ++i)
		{
			printf("%s\t",argv[i] );
		}
		printf("\n");
	}
	return 0;
}