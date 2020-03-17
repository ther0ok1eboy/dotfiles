#!/bin/bash

function menu(){
title="menu"
writer="JasonSorria"
date=`date | awk '{print $1 $2 $3}'`

echo -e "\e[37;34m[---]           The Coolshark Studio (\e[0m\e[37;33mCLS\e[0m\e[37;34m)             [---]\e[0m"

echo -e "\e[37;34m[---]           Created by:\e[0m \e[37;31mJason Sorria\e[0m               \e[37;34m[---]\e[0m"
echo -e "                      \e[37;34mVersion:\e[0m \e[37;31m8.0.3\e[0m"
echo -e "                    \e[37;34mCodename: '\e[0m\e[37;33mSystem init\e[0m\e[37;34m'\e[0m"
echo -e "\e[37;34m[---]        Follow us on Twitter:\e[0m \e[37;35m@CLS studio\e[0m         \e[37;34m[---]\e[0m"
echo -e "\e[37;34m[---]        Follow me on Twitter:\e[0m \e[37;35m@sorria\e[0m             \e[37;34m[---]\e[0m"
echo -e "\e[37;34m[---]       Homepage:\e[0m \e[37;33mhttps://www.coolshark.xyz\e[0m        \e[37;34m[---]\e[0m"
echo -e "        \e[37;32mWelcome to use my daliy menu toolkit (\e[0m\e[37;33mCLS\e[0m\e[37;32m).\e[0m"
echo -e "         \e[37;32mThe one stop shop for all of your CLS needs.\e[0m"
echo ""
echo -e "   \e[37;32m CLS is your best choice to initialize your system.\e[0m"
echo ""
echo -e "           \e[37;34mVisit:\e[0m\e[37;32m https://www.coolshark.xyz\e[0m"
echo ""
echo -e "   \e[37;34mIt's easy to use some daily commands and save time to do more!\e[0m"
echo -e "\e[37;34mVisit\e[0m \e[37;33mhttps://github.com/coolshark404/pdf\e[0m \e[37;34mto update all your tools!\e[0m"
echo ""
echo -e "\e[37;31m                      ____ _     ____   \e[0m" 
echo -e "\e[37;31m                     / ___| |   / ___|  \e[0m" 
echo -e "\e[37;31m                    | |   | |   \___ \  \e[0m" 
echo -e "\e[37;31m                    | |___| |___ ___) | \e[0m" 
echo -e "\e[37;31m                     \____|_____|____/  \e[0m" 
echo ""
echo -e "Select from the menu:"
echo ""
echo -e "               1) initialize system            "
echo -e "               2) connect network              " 
echo -e "               3) recycle rubbish              " 
echo -e "               4) auto-update system           " 
echo -e "               5) optmize deepin-tim           " 
echo -e "               6) network speedtest            " 
echo -e "               7) startup VNC service          " 
echo -e "               8) load ssh agent               " 
echo -e "               9) login in server              " 
echo -e "              10) open frp to penetrate        " 
echo -e "              11) torrent downloader           " 
echo -e "              12) power off                    " 
echo -e "              13) show menu                    " 
echo -e "              14) quit                         "

}

menu
while true; do
    read -p "Choose> " number
    case $number in
    #*   1:) initialize system 
        1)
        figlet i3 initalizing  ..... | lolcat
        sleep 2
        clear
        /usr/local/unix 
        sleep 3
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
            ping -c 3 -n -w5 www.baidu.com >> ~/tempt.txt
            for i in `cat ~/tempt.txt | sed -n '2'p`; do
                sleep 1
                if [[ $i != "" ]]; then
                    if [ -e ~/tempt.txt ]; then
                        mv ~/tempt.txt /rubbish
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
        read -p "if execute this function, this menu will hang out there to become daemon for deepin-TIM, whether or not to continue execute it?(y/n) " isExec
    
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
        read -p "Do you want to view the x11vnc log?(y/n)" tag
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
        cat ~/documents/server-list.md
        read -p "Which server is you want to login?(1 for domestic/2 for abroad)" server
        if [ $server -eq 1 ]; then
            ssh root@49.235.215.98 -p 10022
        else 
            ssh root@35.236.0.163
        fi
        ;;  

        10) 
        echo "pkill frp to close frp service"   
        /home/sorria/downloads/google-download/frp/frpc -c /home/sorria/downloads/google-download/frp/frpc.ini
        ;;  

        11) 
        ~/downloads/aria2/vuze/azureus
        echo "azureus loading, the download file will be stored in path ~/Vuze Downloads"
        ;;  

        12) 
        bash /usr/local/poweroff.sh
        ;;  

        13)
        clear
        menu
        ;;
    
        14)
        echo "quit..."
        break
        ;;
    
        *)
        echo "place input right number..."
        ;;  
    esac
done
                  
