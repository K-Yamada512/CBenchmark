#!/bin/sh

gnuplot << EOF
set terminal png
set output "result.png"
set title "OpenMP"
set logscale
set ylabel "time [s]"
set xlabel "threads"
pl "$1" using 1:2 w lp title "$2"
exit
EOF
