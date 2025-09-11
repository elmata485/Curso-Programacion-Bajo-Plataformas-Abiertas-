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

#Archivo
LOGFILE="$1.log"
echo "# Tiempo(s)   CPU(%)   MEM(%)" > "$LOGFILE"

#Proceso en segundo plano
"$1" &
PID=$!

#Monitoreo
START=$(date +%s)
while kill -0 $PID 2>/dev/null; do
    NOW=$(date +%s)
    ELAPSED=$((NOW - START))

	# CPU y MEM 
    USAGE=$(ps -p $PID -o %cpu,%mem --no-headers)
    CPU=$(echo $USAGE | awk '{print $1}')
    MEM=$(echo $USAGE | awk '{print $2}')
	#guardar en logfile
    echo "$ELAPSED   $CPU   $MEM" >> "$LOGFILE"

    sleep 2  # intervalo de muestreo (2s)
done

echo " Proceso finalizado."
echo " Datos guardados en $LOGFILE"


#Gráfica
#
GNUPLOT_SCRIPT="plot.gnuplot"
cat > $GNUPLOT_SCRIPT <<EOF
set terminal png size 800,600
set output 'monitor.png'
set title "Consumo de CPU y Memoria"
set xlabel "Tiempo (s)"
set ylabel "Uso (%)"
set grid
plot "$LOGFILE" using 1:2 with lines title "CPU (%)", \
     "$LOGFILE" using 1:3 with lines title "Mem (%)"
EOF

gnuplot $GNUPLOT_SCRIPT
