#!/bin/bash

if [ -e /run/media/sorria ]; then
    echo "have been mounted..."
    read -p "do you want to umount this disk(y/n)" tab
        if (($tab==y)); then
            sudo umount /run/media/sorria
            echo "umount sucessful..."
        else
            echo "have noting to do..."
        fi
else
    echo "have not been mounted..."
    echo "start to mounted to /run/media/sorria"
    cd /run/media
    if [ -e /run/media/sorria ]; then
        sudo rm sorria /rubbish -r
    fi
    sudo mkdir sorria
    cd sorria   
    sudo mount /dev/sda1 . > /home/sorria/err.txt
fi
