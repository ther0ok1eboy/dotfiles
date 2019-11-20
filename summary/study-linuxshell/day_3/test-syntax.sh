#!/bin/bash

if [ -e /home/sorria ]; then
    echo "this file exist..."
else
    echo "this file not exist..."
fi

#=======calculate operation demo==========

age=20

if [ $age -ge 18 ]; then
    echo "adult..."
else
    echo "child..."
fi

#===============login demo================

read -p "user: " user

read -p "password: " passwd

if [ $user = "root" ] && [ $password = "000" ]; then
    echo "welcome..."
else
    echo "permission denied"
fi

