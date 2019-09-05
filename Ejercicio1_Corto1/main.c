#include <stdio.h>

int main() {
    //hay un vector para las posiciones, para el precio de cada posicion, y para la disponibilidad de cada posicion(* significa ocupado)
    int posicion[5][5];
    double precio[5][5];
    char disponibilidad[5][5];
    int inicio = 1;
    int centinela = 1;
    double precio1 = 5, precio2 = 3.5, precio3 = 2.5;
    int asiento;
    double ganancias = 0;
    //se llena el vector posicion con la numeracion de los asientos;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            posicion[i][j] = inicio;
            inicio++;
            disponibilidad[i][j] = '-';
        }
    }
    //lleno la primera y ultima fila con los precios
    for (int k = 0; k < 5; ++k) {
        precio[0][k] = precio1;
        precio[4][k] = precio3;
    }
    //lleno los demas precios
    for (int k = 1; k < 4; ++k) {
        for (int i = 0; i < 5; ++i) {
            precio[k][i] = precio2;
        }
    }
    //Hago un menu para comprar asientos
    while (centinela != 0) {
        printf("1.Comprar asientos.\n");
        printf("2.Verificar ganancias.\n");
        printf("0.Salir.\n");
        printf("Ingrese la opcion que desea hacer:\n");
        scanf("%d", &centinela);
        if (centinela == 1) {
            printf("Los asientos de la primera fila tienen un precio de $5.00\n");
            printf("Los asientos de la ultima fila tienen un precio de $2.50\n");
            printf("Los demas asientos tienen un precio de $3.00 \n");
            printf("Las posiciones de la sala son(los asientos marcados con * estan ocupados):\n");
            //imprimo los asientos que estan disponibles
            for (int l = 0; l < 5; ++l) {
                printf("\n");
                for (int i = 0; i < 5; ++i) {
                    if (disponibilidad[l][i] == '*')
                        printf("%c\t", disponibilidad[l][i]);
                    else
                        printf("%d\t", posicion[l][i]);
                }
            }
            printf("\n");
            printf("------------------\n");
            printf("\n");
            printf("Ingrese la posicion que desea comprar(1-25): ");
            scanf("%d", &asiento);
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    //comparo si el asiento esta disponible o no y si lo esta disponible lo pongo como ocupado y rompo los for
                    if (posicion[i][j] == asiento && disponibilidad[i][j] != '*') {
                        disponibilidad[i][j] = '*';
                        i = 5;
                        j = 5;
                    }
                    //si el asiento esta ocupado le digo al usuario que el asiento no esta disponible y rompo los for
                    else if (disponibilidad[i][j] == '*' && posicion[i][j] == asiento) {
                        printf("El asiento ya esta ocupado");
                        i = 5;
                        j = 5;
                    }
                }
            }
            printf("\n");
        }
        //opcion para sumar todos los precios de los asientos ocupados
        if (centinela == 2) {
            ganancias = 0;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (disponibilidad[i][j] == '*') {
                        ganancias = ganancias + precio[i][j];
                    }
                }
            }
            printf("Las ganancias de la sala son: %f", ganancias);
            printf("\n");
        }
    };
    return 0;
}