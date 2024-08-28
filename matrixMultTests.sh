#!/bin/bash

g++ -g blockMatrixMult.cpp -o blockMatrixMult
g++ -g classicMatrixMult.cpp -o classicMatrixMult

start=100
end=1000
step=50

for ((dim=$start; dim<=$end; dim+=$step))
do
    echo "Running with dimension: $dim"
    ./blockMatrixMult $dim 32
    ./classicMatrixMult $dim
done
