#ifndef RELOJ
#define RELOJ
#include <stdio.h>
#include <stdlib.h>

typedef struct Reloj{
	int horas;
	int minutos;
} Reloj;

Reloj* Reloj_New(int,int);
void Reloj_Print(Reloj*);
void Reloj_Delete(Reloj*);

#endif
