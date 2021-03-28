# Curso C

## Funciones

No explicación más clara que la de la comunidad de wikiBooks! Veamos que nos dice:

Puede encontrar en texto original en [Programación en C/Uso de funciones](https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Uso_de_funciones), ya que este presenta algunas variaciones.

Como sabemos, C tiene como bloque básico la función `main()` , también hemos visto la sentencia `printf()` que es otra función, y de igual forma hay muchas más funciones predefinidas, pero nosotros mismos también podemos definir nuestras propias funciones. *De hecho, es fundamental hacerlo.*

Podemos definir una función cualquiera de la misma manera en que definimos la función `main()`. Basta con poner 

* su tipo, 
* su nombre, 
* sus argumentos entre paréntesis y luego, 
* entre llaves, su código:

```C
/* Inclusión de archivos */
#include <stdio.h>

void holamundo(void) /* Función donde se ejecuta la lógica del programa */
{
 	printf("Hola Mundo\n"); /* imprime la cadena */
	return; /* sale de la función */
}
 
int main(void) /* Función principal del programa */
{
	holamundo(); /* llamada a la función holamundo */
	return 0; /* sale del programa con código 0 (correcto) */
}
```

Este código es en todo equivalente al "Hola Mundo" original, sólo que nos muestra cómo escribir y cómo utilizar una función. Y además nos muestra un principio de buena programación: meter las sentencias que "hacen el trabajo" en otras funciones específicas para sacarlas de `main()`, dejando en ésta tan sólo un guión general de lo que hace el programa, no las órdenes específicas. De esta manera se facilita la comprensión del programa, y por tanto el futuro trabajo de modificarlo.

### La sentencia `return`

La sentencia `return` puede utilizarse dentro de una función para terminar su ejecución.

En el ejemplo anterior, la función `holamundo` fue declarada con valor de retorno de tipo `void` (es decir, valor de retorno nulo). En ese caso, la sentencia `return` no lleva ningún parámetro adicional, ya que la función no debe devolver ningún valor a la función que la llama.

En cambio, la función `main` tiene un valor de retorno de tipo `int`, por lo que `return` debe ir seguido de un valor entero (0 en el ejemplo). El valor 0 se utiliza para indicar que el programa ha llegado a un punto en el que todo se ha desarrollado correctamente y se utiliza cualquier otro valor para indicar que ha habido algún tipo de error.

La instrucción `return` no es una función, se trata de una sentencia que lo que hace es retornar como valor de la función el valor que se le proporciona como argumento.

### Argumentos

Las funciones también pueden recibir argumentos o parámetros, para modificar su comportamiento. 

Por ejemplo, la definición de una función para sumar dos números sería de la siguiente manera:

```C
#include <stdio.h>

int sumar(int numero1, int numero2)
{
	return numero1 + numero2;
}

int main(void)
{
	int suma = sumar(5, 3); /* Se ejecuta correctamente*/
	printf("La suma es: %d ", suma);
	return 0;
}
```

### Declaración y definición

En el ejemplo anterior podemos notar que la función `sumar` figura en el código antes que `main`. ¿Qué pasaría si las escribiéramos en distinto orden?

```C
#include <stdio.h>

int main(void)
{
	int suma = sumar(5, 3); /* ERROR, sumar no ha sido declarada aún */
	printf("La suma es: %d ", suma);
	return 0;
}

int sumar(int numero1, int numero2)
{
	return numero1 + numero2;
}
```

En este caso el programa es erróneo y no compila, ya que en la línea donde se llama a la función `sumar`, el compilador aún no conoce ninguna función con ese nombre, y cuáles son sus argumentos y valor de retorno.

Una posible solución es **declarar** el **prototipo** de la función al principio, para informar al compilador que existe, y luego **definir** el **cuerpo** de la misma en cualquier lugar del programa:

```c
#include <stdio.h>

/* Declaración */
int sumar(int numero1, int numero2);

int main(void)
{
	int suma = sumar(5, 3);
	printf("La suma es: %d ", suma);
	return 0;
}

/* Definición */
int sumar(int numero1, int numero2)
{
	return numero1 + numero2;
}
```

### Paso de Parámetros

Las funciones pueden recibir datos como lo hemos observado, pero existen dos formas de enviar los datos hacia una función **por valor** y **por referencia**, las cuales modifican en diferente forma el comportamiento del programa.

#### Por Valor

El paso por valor envía una copia de los parámetros a la función por lo tanto los cambios que se hagan en ella no son tomados en cuenta dentro de la función `main()`. Ejemplo:

```C
#include <stdio.h>

void sumar_valor(int numero); /* prototipo de la función */

int main(void)
{
	int numero = 57; /* definimos numero con valor de 57*/

	sumar_valor(numero); /* enviamos numero a la función */

	printf("Valor de numero dentro de main() es: %d\n", numero);
	/* podemos notar que el valor de numero se modifica
	 * sólo dentro de la función sumar_valor pero en la principal
	 * número sigue valiendo 57 
	 */

	return 0;
}

void sumar_valor(int numero)
{
	numero++; /* le sumamos 1 al numero */

	/* el valor de número recibido se aumenta en 1
	 * y se modifica dentro de la función sumar_valor()
	 */
	printf("Valor de numero dentro sumar_valor() es: %d\n", numero);

	return;
}
```

#### Por Referencia

El paso por referencia se hace utilizando apuntadores. Se envía la dirección de memoria de la variable, por lo tanto los cambios que haga la función si afectan el valor de la variable. Ejemplo:

```c
#include <stdio.h>

void sumar_referencia(int *numero); /* prototipo de la función */


int main(void)
{
	int numero = 57; /* definimos numero con valor de 57*/

	sumar_referencia(&numero); /* enviamos numero a la función */

	printf("\nValor de numero dentro de main() es: %d ", numero);
	/* podemos notar que el valor de numero se modifica
	 * y que ahora dentro de main() también se ha modificado
	 * aunque la función no haya retornado ningún valor.
	 */

	return 0;
}

void sumar_referencia(int *numero)
{
	*numero += 1; /* le sumamos 1 al numero */

	/* el valor de numero recibido se aumenta en 1
	 * y se modifica dentro de la función
	 */
	printf("\nValor de numero dentro sumar_referencia() es: %d", *numero);

	return;
}
```

### Variables Locales y Globales

Además de pasar valores a una función, también se pueden declarar tipos de datos dentro de las funciones, estos tipos de datos declarados dentro de una función solo son accesibles dentro de esta misma función y se les conocen como variables locales, así pues podemos definir los mismos nombres de variables en diferentes funciones, ya que estas variables solo son accesibles dentro de esas funciones. Ejemplo:

```c
#include <stdio.h>

void funcion1()
{
	int dato = 53; /* definimos dato en 53*/
	char num1 = 'a'; /* num1 vale a */

	/* imprimimos */
	printf("Funcion1, dato=%d, num1=%c\n", dato, num1);

	return;
}

void funcion2()
{
	int dato = 25; /* definimos dato en 25*/
	char num2 = 'z'; /* num2 vale z*/

	/* imprimimos */
	printf("Funcion2, dato=%d, num2=%c\n", dato, num2);

	return;
}

int main(void)
{
	funcion1(); /* llamamos a funcion1() */

	funcion2(); /* llamamos a funcion2() */

	return 0;
}
```

En este caso la variable dato, esta definida dentro de cada una de las funciones y son totalmente distinta una de otra y no se puede utilizar fuera de esta, así pues num2 no puede ser utilizada por la funcion1() y num1 tampoco puede ser utilizada por funcion2().

Existen pues variables que se definen fuera de la función principal `main()` y fuera de cualquier otra función creada por nosotros, estas variables se les conoce con el nombre de Variables Globales ya que se pueden utilizar dentro de `main()` y dentro de cualquier función creada por nosotros. Ejemplo:

```c
#include <stdio.h>

int variable_global = 99; /* inicializamos la variable global */

void funcion();

int main(void)
{
	/* imprimimos el valor*/
	printf("main(), acceso a variable_global %d\n", variable_global);

	/* llamamos a la función */
	funcion();

	return 0;
}

void funcion()
{
	/* imprimimos el valor*/
	printf("funcion(), acceso a variable_global %d\n", variable_global);

	return;
}
```

Las variables globales se consideran una de las peores prácticas a la hora de programar, por lo tanto hay que evitarlas.

<!-- Describir por que son una mala práctica -->

## Funciones Recursivas

La recursividad (recursión) es la propiedad por la cual una función se llama a sí misma **directa** o **indirectamente**. La recursión indirecta implica utilizar más de una función.

Se puede considerar la recursividad como una alternativa a la iteración. La recursión permite especificar soluciones naturales, sencillas, que serían, en caso contrario, difíciles de resolver. Toda función recursiva debe contemplar un **caso base** o **condición de salida**, para terminar, o la recursividad no podrá terminar nunca.

Una función recursiva podría definirse así:

```C
funcion_recursiva( /* parámetros recibidos por la función */ )
{
	/* Código */
	funcion_recursiva( ); /* llamada a la función misma */
	/* Código */
}
```

Uno de los ejemplos más representativos en la recursividad es el factorial de un numero ( n! ):

${\displaystyle n!=\prod _{k=1}^{n}k\qquad \forall n\in \mathbb {N} \!}$

la definición de recursividad del factorial es:

${\displaystyle n!={\begin{cases}1&{\text{ Si }}n=0\\n(n-1)!&{\text{ Si }}n>0\\\end{cases}}\qquad \forall n\in \mathbb {N} .}$

En esta definición, n = 0, es nuestro caso base, que le da fin a la recursividad.

Entonces nuestro programa que calcula el factorial es:

```c
#include <stdio.h>

long factorial(int n)
{
	if (n == 0) /* caso base */
		return 1; /* como 0! = 1, se retorna 1*/
	else
		return n * factorial (n - 1); /* llamada a esta misma función */
}

int main(void)
{
	/* en este caso se llama a la función y se imprime directamente*/
	printf("%ld ", factorial(5));

	return 0;
}
```

También existen otros tipos de funciones recursivas como lo es el producto de dos números. El producto de $a{\displaystyle \times } b$, donde **a** y **b** son números enteros positivos seria:

**Solución iterativa:**

${\displaystyle a\times b={\begin{matrix}\underbrace {a+a+\cdots +a} \\\ b\ veces\end{matrix}}=\sum _{i=1}^{b}a}$

**Solución recursiva:**

${\displaystyle a\times b={\begin{cases}0&{\text{ Si }}b=0\\a+a\times (b-1)&{\text{ Si }}b>0\\\end{cases}}}$

Así pues ${\displaystyle 7\times 3}$ es:

${\displaystyle 7\times 3=7+7\times 2=7+7+7\times 1=7+7+7+0=21}$

Podemos ver que la multiplicación de dos números a, b se puede transformar en otro problema más pequeño multiplicar **a** por **(b-1)**, el caso base se produce cuando **b = 0** y el producto es **0**. Ejemplo:

```c
#include <stdio.h>

int producto(int a, int b)
{
	if (b == 0) /* caso base */
		return 0; /* como b = 0, se retorna 0*/
	else
		return a + producto (a, b - 1); /* llamada a esta misma función */
}

int main(void)
{
	/* en este caso se llama a la función y se imprime directamente*/
	printf("%i ", producto( 7, 3));

	return 0;
}
```

### Recursión versus Iteración

Tanto la iteración como la recursión se basan en estructura de control: la iteración utiliza una estructura repetitiva y la recursión una estructura de selección. La iteración utiliza explícitamente una estructura repetitiva mientras que la recursión consigue la repetición mediante llamadas repetitivas a funciones.

La iteración termina si la condición del bucle no se cumple, mientras que la recursión termina cuando se reconoce un caso base.

La recursión puede presentar desventajas ante la iteración ya que se invoca repetidas veces al mecanismo de llamada de funciones y se necesita un tiempo mayor para realizar cada llamada.

La razón por la cual se puede elegir u optar por usar recursividad es que existen muchos problemas complejos que poseen naturaleza recursiva y, en consecuencia, son mas fáciles de implementar.

#### Ejemplo Iterativo

```c
#include <stdio.h>

long factorial(int numero);

int main(int argc, char** argv)
{
	int contador = 0;

	/* calcula el factorial de 0 a 10 */
	for ( contador = 0; contador <= 10; contador++ )
		printf("%d! = %ld\n", contador, factorial( contador ));

	return 0;
}

/* funcion factorial iterativa */
long factorial( int numero )
{
	long resultado = 1;
	int i = 0;

	/* declaracion de la función factorial iterativa */
	for ( i = numero; i >= 1; i-- )
		resultado *= i;

	return resultado;
}
```

#### Ejemplo Recursivo

```c
#include <stdio.h>

long factorial(int numero);

int main(int argc, char** argv)
{
	int contador = 0;

	/* calcula el factorial de 0 a 10 */
	for ( contador = 0; contador <= 10; contador++ )
		printf("%d! = %ld\n", contador, factorial( contador ));

	return 0;
}

/* función factorial recursiva */
long factorial( int numero )
{                                               
	if ( numero <= 0 ) /* caso base */
		return 1; /* casos bases: 0! = 1 y 1! = 1 */
	else /* llamada recursiva */
		return numero * factorial( numero - 1 ); /* llamada a la función factorial */
}
```

#### Ejemplo fibonacci

```c
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
  if (n>2)
    return fibonacci(n-1) + fibonacci(n-2);
  else if (n==2)
    return 1;
  else if (n==1)       
    return 1;
  else if (n==0)
    return 0;
}

int main(void)
{
    int num;

    for (num=0; num<=20; num++)
    {
      printf("%d\n", fibonacci(num));
    }
   
  return 0;
}  
```

**Ahora de manera iterativa**

```shell
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x,y,suma,i;

  x=0;
  y=1;
 
  printf("0\n1\n",suma);
 
  for (i=1;i<=20;i=i+1)
  {
      suma=x+y;
      printf("%d\n",suma);
      x=y;
      y=suma;
  }
     
  return 0;
}
```

## Parámetros de la funcion main

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    if( argc >= 2 )
    {
        printf("The arguments supplied are:\n");
        for(i = 1; i < argc; i++)
        {
            printf("%s\t", argv[i]);
        }
    }
    else
    {
        printf("argument list is empty.\n");
    }
    return 0;
}
```