#ifndef  OPERATIONS_INC
#define  OPERATIONS_INC
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Bool.h"
#define _ISOC99_SOURCE

/**
 * @brief sum es un funcion que suma mediante operadores de bits
 * @details sum recibe dos numeros y los suma, el resultado es alojado en *resultado
 * 
 * @param num1 es un sumando
 * @param num2 es otro sumando
 * @param resultado es donde se aloja el resultado de la suma
 * @return TRUE si la suma se completo sin errores
 */
bool sum(int num1,int num2, int* resultado);
/**
 * @brief substract es el complemento de sum y opera con bits de igual manera
 * @details susbtract resta un numero de otro
 * 
 * @param num1 es el minuendo
 * @param num2 es el substraendo
 * @param resultado es donde se aloja el resultado de la resta
 * @return TRUE si la resta se realizo sin errores
 */
bool substract(int num1,int num2, int* resultado);
/**
 * @brief multiply es un funcion multiplicadora por medio de bits
 * @details multiply se basa en que la multiplicacion es un caso de la suma
 * 
 * @param num1 es un factor
 * @param num2 es otro factor
 * @param resultado es donde se aloja el resultado de multiplicar
 * @return TRUE  si no hubo problemas
 */
bool multiply(int num1,int num2, int* resultado);
/**
 * @brief division es un funcion para realizar divisiones con operadores  bits
 * @details division se basa en el concepto de resta sucesiva
 * 
 * @param num1 es el dividendo
 * @param num2 es el divisor
 * @param resultado es donde se aloja el resultado de la divison
 * @return TRUE Si hubo problemas, FALSE si se divide entre cero
 */
bool division(int num1, int num2,int* resultado);



#endif   /* ----- #ifndef OPERATIONS_INC  ----- */