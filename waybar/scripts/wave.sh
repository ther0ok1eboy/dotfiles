#!/bin/bash
#

bar="▂▄▆▇█▇▆▄▂▁"
#bar="󰮯󰊠󰊠󰊠󰊠󰊠󰊠󰊠󰊠󰊠"
dict="s/;//g;"

# creating "dictionary" to replace char with bar
i=0
while [ $i -lt ${#bar} ]
do
    dict="${dict}s/$i/${bar:$i:1}/g;"
    i=$((i=i+1))
done

while true
do
    echo "0;1;2;3;4;5;6;7;8;9" | sed $dict
    sleep 0.1   
    echo "1;2;3;4;5;6;7;8;9;0" | sed $dict
    sleep 0.1  
    echo "2;3;4;5;6;7;8;9;0;1" | sed $dict
    sleep 0.1  
    echo "3;4;5;6;7;8;9;0;1;2" | sed $dict
    sleep 0.1   
    echo "4;5;6;7;8;9;0;1;2;3" | sed $dict
    sleep 0.1  
    echo "5;6;7;8;9;0;1;2;3;4" | sed $dict
    sleep 0.1   
    echo "6;7;8;9;0;1;2;3;4;5" | sed $dict
    sleep 0.1   
    echo "7;8;9;0;1;2;3;4;5;6" | sed $dict
    sleep 0.1   
    echo "8;9;0;1;2;3;4;5;6;7" | sed $dict
    sleep 0.1   
    echo "9;0;1;2;3;4;5;6;7;8" | sed $dict
    sleep 0.1   
done
