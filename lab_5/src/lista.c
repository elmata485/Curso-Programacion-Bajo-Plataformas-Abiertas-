#include "../include/lista.h"
#include <stdio.h>
#include <stdlib.h>

Nodo* insertar_inicio(Nodo* cabeza, int valor) {
    Nodo* nuevo = malloc(sizeof(Nodo));
    if (!nuevo) return cabeza;
    nuevo->dato = valor;
    nuevo->sig = cabeza;
    return nuevo;
}

Nodo* insertar_final(Nodo* cabeza, int valor) {
    Nodo* nuevo = malloc(sizeof(Nodo));
    if (!nuevo) return cabeza;
    nuevo->dato = valor;
    nuevo->sig = NULL;

    if (!cabeza) return nuevo;

    Nodo* temp = cabeza;
    while (temp->sig) temp = temp->sig;
    temp->sig = nuevo;
    return cabeza;
}

Nodo* insertar_pos(Nodo* cabeza, int valor, int pos) {
    if (pos <= 0) return insertar_inicio(cabeza, valor);

    Nodo* nuevo = malloc(sizeof(Nodo));
    if (!nuevo) return cabeza;
    nuevo->dato = valor;

    Nodo* temp = cabeza;
    for (int i = 0; i < pos - 1 && temp; i++) temp = temp->sig;

    if (!temp) {
        free(nuevo);
        return insertar_final(cabeza, valor);
    }

    nuevo->sig = temp->sig;
    temp->sig = nuevo;
    return cabeza;
}

Nodo* eliminar(Nodo* cabeza, int valor) {
    if (!cabeza) return NULL;

    if (cabeza->dato == valor) {
        Nodo* temp = cabeza->sig;
        free(cabeza);
        return temp;
    }

    Nodo* actual = cabeza;
    while (actual->sig && actual->sig->dato != valor) {
        actual = actual->sig;
    }

    if (actual->sig) {
        Nodo* nodo_eliminar = actual->sig;
        actual->sig = nodo_eliminar->sig;
        free(nodo_eliminar);
    }

    return cabeza;
}

Nodo* buscar(Nodo* cabeza, int valor) {
    Nodo* temp = cabeza;
    while (temp) {
        if (temp->dato == valor) return temp;
        temp = temp->sig;
    }
    return NULL;
}

void imprimir(Nodo* cabeza) {//print como se encuentra el nodo
    printf("Lista: ");
    Nodo* temp = cabeza;
    while (temp) {
        printf("%d ", temp->dato);
        temp = temp->sig;
    }
    printf("\n");
}

void destruir_lista(Nodo* cabeza) {//eliminar restos y se limpia heap
    while (cabeza) {
        Nodo* temp = cabeza->sig;
	free(cabeza);
        cabeza = temp;
    }
}

