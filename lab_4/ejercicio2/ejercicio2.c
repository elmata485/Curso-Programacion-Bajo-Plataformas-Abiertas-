#include <stdio.h>
#include <string.h>
#include <ctype.h>


void limpiarPalabra(char *palabra) {
    int len = strlen(palabra); //longitud de palabra
    int inicio = 0, fin = len - 1; 

    while (inicio <= fin && !isalnum((unsigned char)palabra[inicio])) {
        inicio++;
    }// avanza hasta que el caracter sea alfanumerico
    while (fin >= inicio && !isalnum((unsigned char)palabra[fin])) {
        fin--;
    }//retrocede el fin hasta que el caracter sea alfanumerico

    int j = 0;
    for (int i = inicio; i <= fin; i++)
        palabra[j++] = palabra[i];// recorta la palbra dejandola sin signos de puntuación
    palabra[j] = '\0';//marca el fin de la palabra
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <archivo_entrada>
			<palabra_buscar> <palabra_reemplazo> \n", argv[0]);
        return 1;
    }// condición de que el usuario escriba los argumentos necesarios






  FILE *entrada = fopen(argv[1], "r");
    if (!entrada) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    FILE *salida = fopen("output.txt", "w");
    if (!salida) {
        perror("Error al crear el archivo de salida");
        fclose(entrada);
        return 1;
    }


    fclose(entrada);
    fclose(salida);

    printf("Archivo modificado guardado en 'output.txt'\n");
    return 0;
}



