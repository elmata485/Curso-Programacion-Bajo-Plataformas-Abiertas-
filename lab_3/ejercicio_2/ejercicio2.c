#include <stdio.h>
#include <stdlib.h>   // rand()
#include <time.h>     // crear semilla de  rand()

#ifndef SIZE   //Si el usuario no quiere cambiar el tamaño de matriz
#define SIZE 3  // Se puede cambiar con -DSIZE=#
#endif


/*  
 * Función: CuadradoMagico()
 * 
 * Verifica si una matriz cuadrada, es un cuadrado mágico. Esto quiere decir la suma de los elementos por fila, por columna y por la diagonal son iguales entre sí.
 *  Ocupa una matriz como entrada
 *
 */



int CuadradoMagico(int matriz[SIZE][SIZE]) {
    int sumaObjetivo = 0;

    // Se usa la primera fila como referencia para la suma que hay que llegar
    for (int j = 0; j < SIZE; j++) {
        sumaObjetivo += matriz[0][j];
    }

    // Verificar otras filas
    for (int i = 1; i < SIZE; i++) {
        int sumaFila = 0;
        for (int j = 0; j < SIZE; j++) {
            sumaFila += matriz[i][j];
        }
	
        if (sumaFila != sumaObjetivo) {// si es distinto la suma de referencia con la de esta fila se devuelve returnando 0 es decir el booleano sería negativa
            return 0; 
        }
    }

    // Verificar columnas de las matriz
    for (int j = 0; j < SIZE; j++) {
        int sumaCol = 0;
        for (int i = 0; i < SIZE; i++) {
            sumaCol += matriz[i][j];
        }
        if (sumaCol != sumaObjetivo) {// si es distinto la suma de referencia con la de la columna retorna booleano 0
            return 0;
        }
    }

    // Verificar diagonal principal
    int sumaDiag1 = 0;
    for (int i = 0; i < SIZE; i++) {
        sumaDiag1 += matriz[i][i];// suma de elementos en diagonal
    }
    if (sumaDiag1 != sumaObjetivo) {// si es disinto devuelve boolean negativo
        return 0;
    }

    // Verificar diagonal contraria
    int sumaDiag2 = 0;
    for (int i = 0; i < SIZE; i++) {
        sumaDiag2 += matriz[i][SIZE - 1 - i];// forma de ver los elementos de la diagonal contraria
    }
    if (sumaDiag2 != sumaObjetivo) {// si es distinto devuelve negativo
        return 0;
    }

    return 1; // SI nunca retorna booleano negativo quiere decir que cumple todas las condiciones por lo que devuelve 1 es decir booleano positivo
}



/*
 * Función: printMatriz():
 * Imprime una matriz cuadrada en consola.
 */
void printMatriz(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d ", matriz[i][j]);//forma de recorrer la matriz para imprimir en la terminal por filas y que se vea estetico
        }
        printf("\n");
    }
}


/*
 * Función: MatrizAleatoria
 * Llena una matriz cuadrada con valores aleatorios.
 */
void MatrizAleatoria(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matriz[i][j] = rand() % 10 ; // Valores entre 0 y 9
        }// forma de asignar valores por elemento de la matriz en un size determinado
    }
}

int main(void) {
   /*
       	// Matriz de ejemplo que queremos comprobar antes de aleatoriedad (SE ENCUENTRA EN COMENTARIOS PARA QUE NO AFECTE A LA PARTE DE ALEATORIEDAD AL FINAL) 
    int matriz[SIZE][SIZE] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    printf("La matriz utilizada corresponde a:\n");
    printMatriz(matriz);
//condicional sabiendo el resultado de la funcion de verificación si es cuadrado magico
    if (CuadradoMagico(matriz)) {
        printf("La matriz es cuadrado magico.\n");
    } else {
        printf("La matriz NO es cuadrado magico.\n");
    }
*/

    //Parte donde se empieza a usar la aleatoriedad
    // Semilla para aleatoriedad
    srand(time(NULL));

    // Matriz aleatoria
    int randommatriz[SIZE][SIZE];
    MatrizAleatoria(randommatriz);//se llama a la función de matriz aleatoria

    printf("\nMatriz generada aleatoriamente:\n");
    printMatriz(randommatriz);//imprime matriz

    //Verifica si es cuadrado magico y lo indica en la terminal
    if (CuadradoMagico(randommatriz)) {
        printf("La matriz aleatoria es cuadrado magico.\n");
    } else {
        printf("La matriz aleatoria NO es cuadrado magico.\n");
    }
 
//Termina el programa
    return 0;
}

