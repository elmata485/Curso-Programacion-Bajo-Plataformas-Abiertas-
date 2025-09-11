set terminal png size 800,600
set output 'monitor.png'
set title "Consumo de CPU y Memoria"
set xlabel "Tiempo (s)"
set ylabel "Uso (%)"
set grid
plot "firefox.log" using 1:2 with lines title "CPU (%)",      "firefox.log" using 1:3 with lines title "Mem (%)"
