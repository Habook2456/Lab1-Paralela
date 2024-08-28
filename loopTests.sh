#!/bin/bash

g++ -g loop1.cpp -o loop1
g++ -g loop2.cpp -o loop2

start=500
end=5000
step=500

for ((dim=$start; dim<=$end; dim+=$step))
do
    echo "Running with dimension: $dim"
    ./loop1 $dim
    ./loop2 $dim
done
