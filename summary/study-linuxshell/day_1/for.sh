#!/bin/fish
#shell的作用--命令解释器."翻译官"

for i in a b c d; do 
    echo $i
    sleep 1
done

for ((i = 0; i < 3; i++)); do
    echo $i
    sleep 1
done

free -g | grep -i 内存 | awk '{print "total: "$6"\nuse: "$5"\nhave: "$4}'

df -Th

history 

sleep 2 && clear
