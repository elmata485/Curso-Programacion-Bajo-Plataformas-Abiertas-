#include <stdio.h>

void Imprimir_mat(int *ptr, int filas, int columnas) {
	int i, j;
	for (i=0; i<filas; i++){
		for (j=0; j<columnas; j++){
		printf("%4d", *(ptr + i * columnas +j));	
		}
		printf("\n");	
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
	
}

