#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanio, posicion;
    //ingresar el tamanio del vector
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &tamanio);
    int vector[tamanio];
    //se llena el vector de forma random
    for (int i = 0; i < tamanio; ++i) {
        vector[i] = rand() % 10;
    }
    printf("\n");
    //se imprimen los datos del vector
    printf("Los valores del vector son: \n");
    for (int j = 0; j < tamanio; ++j) {
        printf("%d\t", vector[j]);
    }
    printf("\n");
    //Ingresar la posicion del vector que desea borrar
    printf("Ingrese la posicion que decea borrar (1-%d):", tamanio);
    scanf("%d", &posicion);
    for (int k = posicion; k < tamanio; ++k) {
        vector[k - 1] = vector[k];
    }
    //se copian los valores del vector anterior en un nuevo vector redimensionado en posicion-1
    int vectoraux[tamanio - 1];
    for (int m = 0; m < tamanio - 1; ++m) {
        vectoraux[m] = vector[m];
    }
    printf("\n");
    //se imprimen los nuevos valores sin el que ha sido borrado
    printf("Los nuevos valores del vector son: \n");
    for (int l = 0; l < tamanio - 1; ++l) {
        printf("%d\t", vectoraux[l]);
    }
    return 0;
}