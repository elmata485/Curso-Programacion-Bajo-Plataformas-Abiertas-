#include <stdio.h>
#include <string.h>
#include <ctype.h>


void limpiarPalabra(char *palabra) {
    int len = strlen(palabra);
    int inicio = 0, fin = len - 1;

    while (inicio <= fin && !isalnum((unsigned char)palabra[inicio])) inicio++;
    while (fin >= inicio && !isalnum((unsigned char)palabra[fin])) fin--;

    int j = 0;
    for (int i = inicio; i <= fin; i++)
        palabra[j++] = palabra[i];
    palabra[j] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <archivo_entrada>
			<palabra_buscar> <palabra_reemplazo> \n", argv[0]);
        return 1;
    }// condición de que el usuario escriba los argumentos necesarios
   
}
