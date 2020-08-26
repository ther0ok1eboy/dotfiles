#!/bin/bash

function add(){
    total=0
    num=$1
    for((i = 1; i <= $num; i ++)); do
        total=$(($i+$total))
    done
    echo $total
}

add 100
