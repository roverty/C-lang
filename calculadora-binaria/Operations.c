#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Operations.h"
#include "Bool.h"
#define _ISOC99_SOURCE

bool sum(int num1,int num2, int* resultado){
	int TmpVar;
	while(num2!=0){
		TmpVar=num1&num2;
		num1=num1^num2;
		num2=TmpVar<<1;
	}
	*resultado=num1;
	return TRUE;
}


bool substract(int num1,int num2, int* resultado){
	while(num2!=0){
		bool TmpVar=(~num1)&num2;
		num1=num1^num2;
		num2=TmpVar<<1;
	}
	*resultado=num1;
	return TRUE;
}

bool multiply(int num1,int num2, int* resultado){
	int acum=0;
	if (num1<0 && num2<0)
	{
		num1=num1*(-1);
		num2=num2*(-1);
	}
	for (bool i = 0; i < num2; ++i)
	{
		sum(acum,num1,&acum);
	}
	*resultado=acum;
	return TRUE;
}
bool division(int num1, int num2,int* resultado){
	if (num2==0)
	{
		return FALSE;
	}
	int TmpVar;
	bool negFlag=FALSE;
	sum(num1,num2,&TmpVar);
	if (num1<0 && num2<0)
	{
		num1=num1*(-1);
		num2=num2*(-1);
	}
	if (num2<0)
	{
		num2=num2*(-1);
		negFlag=TRUE;
	}
	if (num1<0)
	{				
		num1=num1*(-1);
		negFlag=TRUE;
	}
	if (num1==num2 && (num2!=0 && num1!=0))
	{
		if (negFlag==TRUE)
		{
			*resultado= -1;
			return TRUE;
		}
		*resultado=1;
		return TRUE;
	}
	int acum=0;
	if (num1==0 && num2==0)		return rand();
		/*Basados en la demostración por series, cero entre 
		cero es cualquier numero.
		*/
	while(TmpVar>num2){
		substract(TmpVar,num2,&TmpVar);
		acum++;
	}
	if (negFlag==TRUE){ *resultado= acum*(-1); return TRUE;}
	*resultado= acum;
	return TRUE;
}

