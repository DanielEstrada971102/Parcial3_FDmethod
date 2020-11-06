#--------------------------- Graficas para N=10 --------------------------------
Name = "N=10"
dataFile = "archivos/solutions_10.txt"

reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines

#---------------------------- Graficas para N=20 -------------------------------
Name = "N=20"
dataFile = "archivos/solutions_20.txt"


reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines

#------------------------- Graficas para N=30 ----------------------------------
Name = "N=30"
dataFile = "archivos/solutions_30.txt"


reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines

#-------------------------- Graficas para N=40 ---------------------------------
Name = "N=40"
dataFile = "archivos/solutions_40.txt"


reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines
#---------------------------- Graficas para N=50 -------------------------------
Name = "N=50"
dataFile = "archivos/solutions_50.txt"


reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines

#---------------------------- Graficas para N=60 -------------------------------
Name = "N=60"
dataFile = "archivos/solutions_60.txt"


reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines

#---------------------------- Graficas para N=70 -------------------------------
Name = "N=70"
dataFile = "archivos/solutions_70.txt"


reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines

#-------------------------- Graficas para N=80 ---------------------------------
Name = "N=80"
dataFile = "archivos/solutions_80.txt"


reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines

#-------------------------- Graficas para N=90 ---------------------------------
Name = "N=90"
dataFile = "archivos/solutions_90.txt"


reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines

#------------------------- Graficas para N=100 ---------------------------------
Name = "N=100"
dataFile = "archivos/solutions_100.txt"


reset

set terminal png size 1000, 700
set output "graficas/".Name.".png"

set title Name
set xlabel"X"
set ylabel"Y"

plot dataFile using 1:2 title "Exact" with lines, \
	 dataFile using 1:3 title "Numerical" with lines, 

reset

set terminal png size 1000, 700
set output "graficas/".Name."_error.png"

set title Name." Error"
set xlabel"X"
set ylabel"ERROR"

plot dataFile using 1:4 title "Error" with lines

#-----------------------------Grafica RMS---------------------------------------

reset

set terminal png size 1000, 700
set output "rms.png"

set title "rms deviation"
set xlabel"N"
set ylabel"RMS DEVIATION"

plot "archivos/rms_deviation.txt" using 1:2 title "rms deviation N=100" with lines

reset

set terminal png size 1000, 700
set output "rms_h.png"

set title "rms deviation h"
set xlabel"h^2"
set ylabel"RMS DEVIATION"

plot "archivos/rms_deviation.txt" using 3:2 title "rms deviation h" with lines
