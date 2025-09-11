#!/bin/bash


###Script para:
#Ver si el usaurio que ejecuta es root.
#Recibe párametros (usario, nombre de un grupo y ruta de un archivo)
#MOdificar la pretencia del archivo 
#Modificar los permisos de lectura, escritura y ejecución
#Hacer caso si existe o no existe y psoibles errores y ayuda si no sabe ejecutar

#Ayuda:
#
mostrar_ayuda() {
    echo "Uso: $0 <usuario> <grupo> <ruta_archivo>"
    echo
    echo "Descripción de la función del archivo:"
    echo "  Este script crea/verifica un usuario y un grupo."
    echo " Además cambia la pertenencia y permisos de un archivo específico."
    echo "Recuerde que para ejecutar este archivo debe ser usuario root"
    echo
    echo "Parámetros:"
    echo "  usuario       Nombre del usuario a verificar o crear"
    echo "  grupo         Nombre del grupo a verificar o crear"
    echo "  ruta_archivo  Ruta absoluta del archivo a modificar, debe existir."
    echo
    echo "Opciones:"
    echo "  -h            Muestra  información y ayuda para ejecutar"
    echo
    echo "Ejemplo:"
    echo "  sudo bash $0 felipe felipes /home/felipe/Documentos/xd.txt"
}

if [[ "$1" == "-h" ]]; then
    mostrar_ayuda
    exit 0
fi


#Comprobar si es root
if [ "$(id -u)" -ne 0 ]; then
    echo "Error:  Tenga en cuenta que debe ejecutar este script como un usuario root. \n Si quiere más info: bash $0 -h"
    exit 1
fi

#Verificar cantidad necesaria de parámetros
if [ $# -ne 3 ]; then
    echo "Error: Número de parámetros inválido.Observe esta ayuda: "
    mostrar_ayuda

    exit 1
fi

#Definir variables de entrada
Usuario=$1
Grupo=$2
Ruta=$3


#Ruta existe?
if [ ! -e "$ARCHIVO" ]; then
    echo "error:  la ruta de '$Ruta' no existe.Verifiquela y vuelva a intentar."
    exit 1
fi




#Grupo existe?
if getent group "$Grupo" > /dev/null; then
    echo "El grupo '$Grupo' ya existe."
else
    groupadd "$Grupo"
fi


#Usuario existe?
if id "$Usuario" &>/dev/null; then
    echo "El usuario '$Usuario' existe"
    usermod -aG "$Grupo" "$Usuario"
else
    useradd -m -g "$Grupo" "$Usuario"
fi

#Pertenencia
chown "$Usuario:$Grupo" "$Ruta"
echo "Pertenencia de '$Ruta' cambiada a usuario '$Usuario' y al grupo '$Grupo' indicados."





#Permisos
chmod 740 "$Ruta"
echo "Se cambiaron los permisos de '$Ruta' "





