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
*   4:) auto-update system            *
*   5:) optmize deepin-tim            *
*   6:) network speedtest             *
*   7:) startup VNC service           *
*   8:) load ssh agent                *
*   9:) power off                     *
*  10:) show menu                     *
*  11:) quit                          *
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
        echo "disk have been mounted...." | lolcat
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
            echo "it maybe spends some times..." | lolcat
            sudo netctl start pppoe
            #test whether or not there is network
            while true; do
            ping -c 3 -n -w5 www.baidu.com >> tempt.txt
            for i in `cat tempt.txt | sed -n '2'p`; do
                sleep 1
                if [[ $i != "" ]]; then
                    if [ -e tempt.txt ]; then
                        mv tempt.txt /rubbish
                    fi    
                    echo "success to connect network..." | lolcat
                    exit
                fi
                done
            sleep 2
            done
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
            read -p "you have not rubbish bin, do you want to build a rubbish bin?(y/n)" isBuild
            if [ $isBuild == "y" ]; then
                sudo mkdir -m 777 /rubbish
                echo "build successfully..."
            else
                echo "nothing to do"
            fi
        fi
        ;;
    
    #*   4:) update
        4)
        sudo pacman -Syu -y
        echo "system update successfully..."
        ;;
    
    #*   5:) optimize deepin-tim  
        5)
        read -p "if execute this function, this menu will hang out there to become daemon for deepin-TIM, whether or not to continue execute it?(y/s) " isExec
    
        if [ $isExec == "y" ]; then
            echo "TIM environments are built completely..."
            /usr/lib/gsd-xsettings
        else
            echo "nothing to do..."
        fi
        ;;

        6) 
        speedtest-cli --bytes 
        ;;  

        7) 
        x11vnc -nap -wait 50 -noxdamage -rfbauth /home/sorria/.vnc/passwd -display :0 -nocursor -forever -o /home/sorria/.vnc/x11vnc.log -bg
        echo "x11vnc.service startup successfully..."
        read -p "Do you want to view the x11vnc log?(y/s)" tag
        if [ $tag == "y" ]; then 
            cat ~/.vnc/x11vnc.log | less
        else 
            echo "have nothing to do..."
        fi
        ;;  

        8)
        read -p "please input the port you want to connect(recommend 10222 or 7233)" port
        ssh -CqTfnN -R :$port:localhost:22 root@49.235.215.98 -p 10022       
        echo "ssh agent load successfully..."
        ;;  

        9) 
        bash /usr/local/poweroff.sh
        ;;  

        10)
        clear
        menu
        ;;
    
        11)
        echo "quit..."
        break
        ;;
    
        *)
        echo "place input right number..."
        ;;  
    esac
done




