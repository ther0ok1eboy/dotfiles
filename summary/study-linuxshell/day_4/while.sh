#!/bib/bash

num=5

while [ $num -ge 0 ]
do
    clear
    echo $num
    num=$(($num-1))
    sleep 1
done


