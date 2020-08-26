#!/bin/bash

total=0

for i in $*; do
    total=$(($total+$i))
done

echo $total

num=$((33+33))
number=$(($num/3))
number=$(($number*2))
echo $number
