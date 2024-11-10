set key off
set size ratio -1
set xrange [-1:11]
set yrange[-1:11]
plot "out.txt" index i using 1:2 pt 5 ps 5.5, "out.txt" index i using 1:3 pt 5 ps 5.5, "out.txt" index i using 1:4 pt 5 ps 5.5, "out.txt" index i using 1:5 pt 5 ps 5.5, "out.txt" index i using 1:6 pt 5 ps 5.5, "out.txt" index i using 1:7 pt 5 ps 5.5, "out.txt" index i using 1:8 pt 5 ps 5.5, "out.txt" index i using 1:9 pt 5 ps 5.5, "out.txt" index i using 1:10 pt 5 ps 5.5, "out.txt" index i using 1:11 pt 5 ps 5.5
replot
pause 1
i=i+1
if(i<n) reread
