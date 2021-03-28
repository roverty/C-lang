#include<stdio.h>

int main(void) {
    float edadDeRodrigo = 12.4; // Convencion camell case
    float edadDeMike = 2.70;

    //float modulo = edadDeRodrigo%edadDeMike;

    if( !edadDeRodrigo && edadDeMike ){
        printf("Las edades son distintas de 0\n");
    }else{
        printf("Las edades son cero (ambas)\n");
        printf("La edad de Rod es %f \n", !edadDeRodrigo);
        
    }

    //printf("Modulo de la edad de Rod: %f\n", modulo);

    edadDeMike ++;

    printf("edad de mike ahora es %f\n", edadDeMike);

    return 0;
}
