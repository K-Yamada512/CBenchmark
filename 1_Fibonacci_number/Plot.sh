#!/bin/sh

gnuplot << EOF
set terminal png
set output "result.png"
set title "Fibonacci number F(n)"
set ylabel "time [s]"
set xlabel "Fibonacci number index n"
set logscale
set key top left
pl "$1" using 1:2 w lp title "$2"
exit
EOF
