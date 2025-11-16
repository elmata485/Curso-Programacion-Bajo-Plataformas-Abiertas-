#include <stdio.h>
#include "lista.h"

int main() {
    Nodo* lista = NULL;
	
    printf("Lista al principio");
    imprimir(lista);


    printf("Lista antes de insertar al inicio");
    imprimir(lista);
    lista = insertar_inicio(lista, 10);
    printf("Lista despues de insertar al inicio");
    imprimir(lista);


    printf("Lista antes de insertar al final");
    imprimir(lista);
    lista = insertar_final(lista, 20);
    printf("Lista despues de insertar al final");
    imprimir(lista);


    printf("Lista antes de insertar en posición1");
    imprimir(lista);
    lista = insertar_pos(lista, 15, 1);
    printf("Lista después de insertar en posición 1");
    imprimir(lista);



    printf("Lista antes de buscar dato");
    imprimir(lista);
    Nodo* encontrado = buscar(lista, 15);
    if (encontrado) {
        printf("Encontrado: %d\n", encontrado->dato);
    }
    printf("Lista despues de buscar dato");
    imprimir(lista);

    printf("Lista antes de eliminar dato");
    imprimir(lista);
    lista = eliminar(lista, 20);
    printf("Lista despues de eliminar dato");
    imprimir(lista);

    printf("Lista antes de destruir lista de memoria dinámica");
    imprimir(lista);
    destruir_lista(lista);
    printf("Lista después  de destruir lista");
    imprimir(lista);

    return 0;
}

