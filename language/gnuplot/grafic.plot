# grafic in scala logaritmica, o functie analitica si doua definite prin date in fisierul "grafic.dat"
set logscale y 10
set grid
set style function linesp
set style data linesp
set samples 20 # pentru functii definite analitic
set title "Rezultatele analitice si experimentale"
set xlabel "x [m]"
set ylabel "f(x) [-]"
set term postscript eps mono "Times-Roman" 20
set output "graficx.eps"

f(x) = x**2
plot [0.1:5] \
	f(x) title "Analitic", \
	"grafic.dat" using 1:2 title "Experiment 1", \
	"grafic.dat" using 1:3 title "Experiment 2"
