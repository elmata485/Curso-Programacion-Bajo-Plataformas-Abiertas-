#include <stdio.h>
#include "lista.h"

int main() {
    Nodo* lista = NULL;

    lista = insertar_inicio(lista, 10);
    lista = insertar_final(lista, 20);
    lista = insertar_pos(lista, 15, 1);

    imprimir(lista);

    Nodo* encontrado = buscar(lista, 15);
    if (encontrado) {
        printf("Encontrado: %d\n", encontrado->dato);
    }

    lista = eliminar(lista, 20);
    imprimir(lista);

    destruir_lista(lista);

    return 0;
}

