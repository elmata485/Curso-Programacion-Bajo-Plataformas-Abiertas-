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
	
//matriz de ejemplo
	int mat_1[2][3] = {
		{3, 4, 10},
		{11, 1, 8}
	};

	printf("La matriz a reordenar es: \n");
	Imprimir_mat((int *)mat_1, 2, 3);
	Bubblesort((int *)mat_1, 2 * 3);
	printf("La matriz ya se ordenó, quedó de la siguiente manera: \n");
	Imprimir_mat((int *)mat_1, 2, 3);	
}

