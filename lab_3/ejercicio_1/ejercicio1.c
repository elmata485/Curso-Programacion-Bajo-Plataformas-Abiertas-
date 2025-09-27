#include <stdio.h>

// Función factorial
int factorial(int n) {
    int i = 1;
    while (n > 1) {
        i = i * n;
        n = n - 1;   // Ya no se declara dos veces el número n
    }
    return i;
}

//Main
int main(int argc, char *argv[]) {
    int num; //Declaramos un número para recibirlo del usuario
    printf("Ingrese un número: "); //Pedimos el número
    scanf("%d", &num);   //Lo scaneamos

    
    int resultado = factorial(num); //Asignamos al cálculo del factorial del número un espacio en memoria
    printf("%d! = %d\n", num, resultado);//Lo mostramos al usuario

    return 0;
}

