#include <stdio.h>
#include "lista.h"

int main() {
    Nodo* lista = NULL;
	
    printf("Lista al principio\n");
    imprimir(lista);


    printf("Lista antes de insertar al inicio\n");
    imprimir(lista);
    lista = insertar_inicio(lista, 10);
    printf("Lista despues de insertar al inicio\n");
    imprimir(lista);


    printf("Lista antes de insertar al final\n");
    imprimir(lista);
    lista = insertar_final(lista, 20);
    printf("Lista despues de insertar al final \n");
    imprimir(lista);


    printf("Lista antes de insertar en posición1 \n");
    imprimir(lista);
    lista = insertar_pos(lista, 15, 1);
    printf("Lista después de insertar en posición 1 \n");
    imprimir(lista);



    printf("Lista antes de buscar dato \n");
    imprimir(lista);
    Nodo* encontrado = buscar(lista, 15);
    if (encontrado) {
        printf("Encontrado: %d\n", encontrado->dato);
    }
    printf("Lista despues de buscar dato \n");
    imprimir(lista);

    printf("Lista antes de eliminar dato \n");
    imprimir(lista);
    lista = eliminar(lista, 20);
    printf("Lista despues de eliminar dato \n");
    imprimir(lista);

    destruir_lista(lista);

    return 0;
}

