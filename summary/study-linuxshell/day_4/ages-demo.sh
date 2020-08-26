#!/bin/bash

read -p "please input your ages..." ages

if [ $ages -le 18 ]; then 
    echo "child..."
elif [ $ages -gt 18 ] && [ $ages -le 30 ]; then
    echo "adult..."
elif [ $ages -gt 30 ] && [ $ages -le 50 ]; then
    echo "man..."
else
    echo "elders..."
fi



week=`date +%w`

case $week in
    1)
    echo "monday..."
    ;;

    2)
    echo "turthday..."
    ;;

    *)
    echo "system: i don't known..."
esac
