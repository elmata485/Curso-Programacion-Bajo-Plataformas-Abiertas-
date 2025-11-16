## Descripción del contenido del repositorio

Este repositorio contiene la implementación de una **lista enlazada** en lenguaje C.  
El proyecto está dividido en módulos, estructura:

- `include/lista.h`: archivo header con las declaraciones de la estructura usada y llamado a las funciones.
- `src/lista.c`: implementación de las funciones de la lista enlazada con las que se trabajaran en el programa.
- `src/main.c`: programa principal donde se prueban las opciones de la estructura.
- `Makefile`: automatiza la compilación y limpieza del proyecto.
- `README.md`: Describe pasos y estructura del proyecto.
 
La lista enlazada implementa las siguientes operaciones:
- Insertar al inicio  
- Insertar al final  
- Insertar en una posición específica  
- Buscar un elemento  
- Eliminar un elemento por valor  
- Imprimir la lista completa  
- Liberar toda la memoria utilizada  

## Pasos para compilar

Desde la carpeta raíz del proyecto, ejecutar:

```bash
make
```

De esta manera se crea el ejecutable.


Para limpiar archivos generados:
```bash
make clean
```
## Ejecutar

```bash
./main
```

