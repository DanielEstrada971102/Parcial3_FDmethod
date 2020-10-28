set autoscale
set grid
show grid
show autoscale
plot "solutions.txt" using 2 title 'Y' with lines, \
     "solutions.txt" using 3 title 'Y_{FD}' with lines, \
     #"solutions.txt" using 4 title 'Y RK4' with lines