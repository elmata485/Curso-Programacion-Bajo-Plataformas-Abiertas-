#include <stdio.h>


void Imprimir_mat(int *ptr, int filas, int columnas) {
	int i, j;
	for (i=0; i<filas; i++){
		for (j=0; j<columnas; j++){
		printf("%4d", *(ptr + i * columnas +j));// Imprimo el número que se encuentra en la posición de la matriz que le indico mediante la utilización de punteros	
		}
		printf("\n");	
	}
	
}


void Bubblesort(int *ptr, int filasxcols){
	int i, j, temp;
	for (i=0; i<filasxcols-1;	i++){
		for (j=0; j<filasxcols-i-1; j++){
			// tomar hasta el penultimo número ya que si se prueba con el último puede cambiarse con dirreciónes que tienen basura
			if (*(ptr +j)> *(ptr +j+1)){
				//intercambiar con la ayuda de una variable temporal
				temp = *(ptr +j);
				*(ptr + j) = *(ptr +j+1);
				*(ptr +j +1) = temp;
			}
		}
	}
}



int main() {
	
	//matriz de ejemplo 1
	int mat_1[2][3] = {
		{3, 4, 10},
		{11, 1, 8}
	};

	printf("La matriz a reordenar es: \n");
	Imprimir_mat((int *)mat_1, 2, 3);
	Bubblesort((int *)mat_1, 2 * 3);
	printf("La matriz ya se ordenó, quedó de la siguiente manera: \n");
	Imprimir_mat((int *)mat_1, 2, 3);	

	//matriz de ejemplo 2

	int mat_2[5][5] = {
                {3, 4, 10, 15, 94},
                {11, 1, 8, 108, 41},
		{0, -10, 115, 94, 108},
		{17, 114, 163, 170, 11005},
		{2000, 102, 91, 18, 34}
        };

	printf("La matriz a reordenar es: \n");
        Imprimir_mat((int *)mat_2, 5, 5);
        Bubblesort((int *)mat_2, 5 * 5);
        printf("La matriz ya se ordenó, quedó de la siguiente manera: \n");
        Imprimir_mat((int *)mat_2, 5, 5);
	

	//matriz de ejemplo 3

        int mat_3[5][2] = {
                {3, 4},
                {11, 1},
                {0, -10},
                {17, 114},
		{-1, -94}
        };

        printf("La matriz a reordenar es: \n");
        Imprimir_mat((int *)mat_3, 5, 2);
        Bubblesort((int *)mat_3, 5 * 2);
        printf("La matriz ya se ordenó, quedó de la siguiente manera: \n");
        Imprimir_mat((int *)mat_3, 5, 2);
}

