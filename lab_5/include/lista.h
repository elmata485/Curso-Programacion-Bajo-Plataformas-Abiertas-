#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

Nodo* insertar_inicio(Nodo* cabeza, int valor);
Nodo* insertar_final(Nodo* cabeza, int valor);
Nodo* insertar_pos(Nodo* cabeza, int valor, int pos);
Nodo* eliminar(Nodo* cabeza, int valor);
Nodo* buscar(Nodo* cabeza, int valor);
void imprimir(Nodo* cabeza);
void destruir_lista(Nodo* cabeza);

#endif
