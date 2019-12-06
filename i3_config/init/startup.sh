#!/bin/bash

function menu(){
title="menu"
writer="JasonSorria"
date=`date | awk '{print $1 $2 $3}'`
cat << eof
***************************************
**               ${title}                **
***************************************
*   1:) initialize system             *
*   2:) connect network               *
*   3:) recycle rubbish               *
*   4:) go to github                  *
*   5:) optmize deepin-tim            *
*   6:) show menu                     *
*   7:) quit                          *
***************************************
**${writer}          ${date}**
***************************************

eof
}

menu
while true; do
    read -p "please input this number to execute: " number
    case $number in
    #*   1:) initialize system 
        1)
        figlet i3 initalizing  ..... | lolcat
        sleep 2
        sl | lolcat
        clear
        sleep 1
        figlet loading .... | lolcat
        neofetch
        echo "initializing..." | lolcat
        sleep 4
        clear
        cowsay -f dragon welcome to manjaro world
        sudo mount /dev/sda4 ~/new-world
        echo "disk have been mounted...."
        sleep 3
        sudo modprobe -a vmw_vmci vmmon
        echo "vmware workstation initialize completely..." | lolcat
        sleep 1
        xmodmap ~/.xmodmap
        echo "keyboard has been initialized..." | lolcat
        sleep 1
        #sudo ntpdate -u time1.aliyun.com
        sudo ntpdate time1.aliyun.com
        echo "system time and date has been changed..." | lolcat
        ;;
    
    #*   2:) connect network
        2)
        read -p "we will shut down the enp2s0 and do you want connect network?(y/n) " isConnect
        if [ $isConnect == 'y' ]; then
            echo "yes"
            sudo ip link set enp2s0 down
            echo "it is maybe spends some times..."
            #test whether or not there is network
            while true; do
            ping -c 3 -n -w5 www.baidu.com >> tempt.txt
            for i in `cat b.txt | sed -n '2'p`; do
                sleep 1
                if [[ $i != "" ]]; then
                    if [ -e b.txt ]; then
                        mv temp.txt /rubbish
                    fi    
                    echo "success to connect network..."
                    exit
                fi
                done
            sleep 2
            done

            sudo netctl start pppoe
            echo "connect network successfully by pppoe protocol..."
        else
            echo "nothing to do..."
        fi
        ;;
    
    #*   3:) recycle rubbish
        3)
        if [ -e /rubbish ]; then
            file_size=`ls -s /rubbish | sed -n '1'p | awk '{print $2}'`
            if [ $file_size -lt 100 ]; then
                echo "the size of rubbish bin is less then 100K and nothing to do..."
            else
                sudo mv /rubbish/* /tmp
                echo "recycle rubbish bin successfully..."
            fi
        else
            read -p "you have not rubbish bin, do you want to build a rubbish bin?(y/n) isBuild"
            if [ $isBuild == "y" ]; then
                sudo mkdir /rubbish
                echo "build successfully..."
            else
                echo "nothing to do"
            fi
        fi
        ;;
    
    #*   4:) go to github
        4)
        if [ -e ~/documents/github-local/manjaro_config ]; then
            cd ~/documents/github-local/manjaro_config
            echo "maybe this function have some bugs to execute..."
        else
            echo "this directory not exist..."
        fi
        ;;
    
    #*   5:) optimize deepin-tim  
        5)
        read -p "if execute this function, this menu will hang out there to become daemon for deepin-TIM, whether or not to continue execute it?(y/s) " isExec
    
        if [ $isExec="y" ]; then
            echo "TIM environments are built completely..."
            /usr/lib/gsd-xsettings
        else
            echo "nothing to do..."
        fi
        ;;
    
        6)
        clear
        menu
        ;;
    
        7)
        echo "quit..."
        break
        ;;
    
        *)
        echo "place input right number..."
        ;;  
    esac
done


