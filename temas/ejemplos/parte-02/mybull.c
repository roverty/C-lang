#include <stdio.h>

typedef enum {false, true} bool;
//typedef enum {false=0, true=1} bool;

int main() {
  bool x = false;
  if(x == true){
    printf("x is true.\n");
  }
  else{
    printf("x is false.\n");
  }
  
  char vector[]={'H','o','l','a','a'}; /* Un vector de 4 elementos,
  con los elementos 'H','o','l' y 'a' */
  char espacio_cadena[1024]="Una cadena en C";

  printf("Imprimiendo una cadena: %s\n", vector);


  return 0;
}
