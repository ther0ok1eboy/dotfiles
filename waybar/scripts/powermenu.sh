#!/bin/bash

option0=" Lock"
option1="󰗽 Logout"
option2=" Suspend"
option3=" Reboot"
option4=" Shutdown"

options="$option0\n$option1\n$option2\n$option3\n$option4\n$option5\n$option6\n$option7"

chosen="$(echo -e "$options" | fuzzel --lines 5 --dmenu)"
case $chosen in
    $option0)
	swaylock --font "ComicShannsMono Nerd Font";;
    $option1)
        loginctl terminate-user $(whoami);;
    $option2)
	killall wayfire;;
    $option3)
	killall wayfire;;
    $option4)
	killall wayfire;;
esac
