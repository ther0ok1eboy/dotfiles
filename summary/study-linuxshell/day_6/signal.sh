#!/bin/bash

trap 'trap_function' 2 3
function trap_function(){
    echo "Ctrl+c and Ctrl+\ are invalid for this process..."

}

value=0
while true; do
echo $value
let value++
sleep 1
done
