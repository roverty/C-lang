
/*-----------------------------------------------------------------------------
 *                         Menu.c ()
 *-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
char menu()
{
	char opcion ;

	//do {
		printf (	"\n"
					"a -- SUMA\n"
					"b -- RESTA\n"
					"c -- MULTIPLICACION\n"
					"d -- DIVISION\n"
					"e -- EXIT\n"                    
					"Su opción> ");
		fflush(stdin);
		fflush(stdin);
		scanf ("%c", &opcion);
	printf ("\n");
	return opcion;
}
