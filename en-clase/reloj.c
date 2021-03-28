#include<stdio.h>
#include<stdlib.h>
#include "reloj.h"
#include <stdbool.h>
Reloj* Reloj_New(int _horas,int _minutos){
	Reloj* p;
	p = (Reloj*)malloc(sizeof(Reloj));
	
	if(p){
		p->horas = _horas;
		(*p).minutos = _minutos;
	}

	return p;
}

void Reloj_Print(Reloj* this){
	printf("%d:%d\n", this->horas,this->minutos);
}

void Reloj_Delete(Reloj* this){
	if(this != NULL){
		free(this);
		this = NULL;
	}
}
