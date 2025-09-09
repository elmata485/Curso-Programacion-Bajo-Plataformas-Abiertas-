#!/bin/bash



#Ejercicio 2


#Help
mostrar_ayuda() {
    echo "Uso: $0 <proceso> "
    echo
    echo "Descripción de la función del archivo:"
    echo "  Este script monitorea un proceso dado por el usuario."
    echo "Crea un log de salida con los datos de la memoria y el consumo de cpu"
    echo "A su vez, gráfica esos datos"
    echo
    echo "Parámetros:"
    echo "  proceso      Nombre del proceso a monitorear"
    echo
    echo "Opciones:"
    echo "  -h            Muestra  información y ayuda para ejecutar"
    echo
    echo "Ejemplo:"
    echo "  bash $0 firefox "
}

if [[ "$1" == "-h" ]]; then
    mostrar_ayuda
    exit 0
fi


#Verificar que dieron un proceso
if [ $# -ne 1 ];then
	echo "Error: número de parámetros inválido. Observe esta ayuda:"
	mostrar_ayuda
	exit 1
fi





