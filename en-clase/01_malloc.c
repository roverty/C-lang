#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    int* ptr; 
    int n, i; 

    n = 5; // Es la longitud (variable) del arreglo
    printf("La longitud del arreglo será: %d\n", n); 

    // asignacion por memoria dinamica
    ptr = (int*)malloc(n * sizeof(int)); 

    // Verifica si fue posible asignar la memoria
    if (ptr == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 

        printf("Memory successfully allocated using malloc.\n"); 

        // Llenando el arreglo de manera dinamica.
        for (i = 0; i < n; ++i) { 
            ptr[i] = i + 1; 
        } 

        printf("The elements of the array are: "); 
        for (i = 0; i < n; ++i) { 
            printf("%d, ", ptr[i]); 
        } 
        printf("\n");

        printf("Rellenando el arreglo con notacion de apuntadores: \n");
        for (int i = 0; i < n; ++i)
        {
            *(ptr+i) = i + 5;

        }
        printf("Imprimiendo el arreglo con notacion de apuntadores:\n");
        for (int i = 0; i < n; ++i)
        {
            printf("%d, ", *(ptr+i));
        }
        printf("\n");
    } 

    return 0; 
}