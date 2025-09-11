#!/bin/bash


#Directorio y crear el archivo de monitoreo
DIR="/home/felipe-mata/Documentos/Curso-Programacion-Bajo-Plataformas-Abiertas-/lab_2/ejercicio_3/monitoreo"
LOGFILE="/home/felipe-mata/Documentos/Curso-Programacion-Bajo-Plataformas-Abiertas-/lab_2/ejercicio_3/archivo_monitor.log"

touch "$LOGFILE"



inotifywait -m -r -e create -e modify -e delete --format '%T %e %w%f' --timefmt '%Y-%m-%d %H:%M:%S' "$DIR" |
while read datetime event file; do
    echo "[$datetime] Evento: $event en $file"  >> "$LOGFILE"
done
