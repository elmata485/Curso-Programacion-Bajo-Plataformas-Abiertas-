#include <stdio.h>

int cuadrado_sin_punteros(int n){
	return n*n ;	
}

void cuadrado_con_punteros(int *p){
	*p = (*p) * (*p) ;	
}

int main() {
    int num = 5; //número que queremos calcular su cuadrado

    // Llamada a la función sin punteros
    int resultado_sin_punteros = cuadrado_sin_punteros(num);
    printf("Cuadrado sin punteros: %d\n",  resultado_sin_punteros);

    // Llamada a la función con punteros
    cuadrado_con_punteros(&num);//se cambia la variable por su cuadrado
    printf("Cuadrado con punteros: %d\n", num);

    return 0;
}
