#!/bin/sh

gnuplot << EOF
set terminal png
set output "result.png"
set title "BLAS(dgemm)"
set logscale
set ylabel "time [s]"
set xlabel "dimension of square matrix"
set key top left
pl "$1" using 1:2 w lp title "$2"
exit
EOF
