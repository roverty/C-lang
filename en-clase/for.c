#include <stdio.h>

char* obtenerSaludo(){
	char *saludo = "Hola amigos";
	return saludo;
}

int main(int argc, char const *argv[])
{
	char *saludo;
	saludo = obtenerSaludo();
	printf("%s\n", saludo);
	return 0;
}