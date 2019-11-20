#!/bin/bash

#for calculation:
echo $((333+333))

echo $(($1+$2))

#must include Space betwen '+-*/'
expr 333 + 333

expr $1 + $3

#function of $?:
if [[ $? == 0 ]]; then
    echo "last oder excute sucessfully..."
else
    echo "excute failure..."
fi

echo "numbers of current value is ${#}.."

echo "current value have $*.."

echo "current oder is $0"
