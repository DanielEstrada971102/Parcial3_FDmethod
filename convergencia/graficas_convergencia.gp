reset

set terminal png size 1000, 700
set output "N=10.png"

set title "N=10"
set xlabel"X"
set ylabel"Y"

plot "graficas/solutions_10.txt" using 1:2 title "Exact" with lines, \
	 "graficas/solutions_10.txt" using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "N=10_error.png"

set title "N=10 Error"
set xlabel"X"
set ylabel"ERROR"

plot "graficas/solutions_10.txt" using 1:4 title "Error" with lines

reset

set terminal png size 1000, 700
set output "N=100.png"

set title "N=100"
set xlabel"X"
set ylabel"Y"

plot "graficas/solutions_100.txt" using 1:2 title "Exact" with lines, \
	 "graficas/solutions_100.txt" using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "N=100_error.png"

set title "N=100 Error"
set xlabel"X"
set ylabel"ERROR"

plot "graficas/solutions_100.txt" using 1:4 title "Error" with lines

reset

set terminal png size 1000, 700
set output "N=1000.png"

set title "N=1000"
set xlabel"X"
set ylabel"Y"

plot "graficas/solutions_1000.txt" using 1:2 title "Exact" with lines, \
	 "graficas/solutions_1000.txt" using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "N=1000_error.png"

set title "N=1000 Error"
set xlabel"X"
set ylabel"ERROR"

plot "graficas/solutions_1000.txt" using 1:4 title "Error" with lines

reset

set terminal png size 1000, 700
set output "N=10000.png"

set title "N=10000"
set xlabel"X"
set ylabel"Y"

plot "graficas/solutions_10000.txt" using 1:2 title "Exact" with lines, \
	 "graficas/solutions_10000.txt" using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "N=10000_error.png"

set title "N=10000 Error"
set xlabel"X"
set ylabel"ERROR"

plot "graficas/solutions_10000.txt" using 1:4 title "Error" with lines



reset

set terminal png size 1000, 700
set output "rms_N=100.png"

set title "rms deviation N=100"
set xlabel"N"
set ylabel"RMS DEVIATION"

plot "rms_deviation100.txt" using 1:2 title "rms deviation N=100" with lines

reset

set terminal png size 1000, 700
set output "rms_N=1000.png"

set title "rms deviation N=1000"
set xlabel"N"
set ylabel"RMS DEVIATION"

plot "rms_deviation1000.txt" using 1:2 title "rms deviation N=1000" with lines

reset

set terminal png size 1000, 700
set output "rms_N=10000.png"

set title "rms deviation N=10000"
set xlabel"N"
set ylabel"RMS DEVIATION"

plot "rms_deviation10000.txt" using 1:2 title "rms deviation N=10000" with lines


reset

set terminal png size 1000, 700
set output "rms_h=100.png"

set title "rms deviation h=0.5/100"
set xlabel"h^2"
set ylabel"RMS DEVIATION"

plot "rms_deviation100.txt" using 3:2 title "rms deviation h=0.5/100" with lines

reset

set terminal png size 1000, 700
set output "rms_h=1000.png"

set title "rms deviation h=0.5/1000"
set xlabel"h^2"
set ylabel"RMS DEVIATION"

plot "rms_deviation1000.txt" using 3:2 title "rms deviation h=0.5/1000" with lines

reset

set terminal png size 1000, 700
set output "rms_h=10000.png"

set title "rms deviation h=0.5/10000"
set xlabel"h^2"
set ylabel"RMS DEVIATION"

plot "rms_deviation10000.txt" using 3:2 title "rms deviation h=0.5/10000" with lines