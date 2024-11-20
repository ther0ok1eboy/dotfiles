#!/bin/bash

option0=" Lock"
option1="  Background"
option2="󰗽 Logout"
option3=" Suspend"
option4=" Reboot"
option5=" Shutdown"

options="$option0\n$option1\n$option2\n$option3\n$option4\n$option5\n$option6\n$option7"

chosen="$(echo -e "$options" | fuzzel --lines 5 --dmenu)"
case $chosen in
    $option0)
        hyprlock;;
    $option1)
        killall waybar;;
    $option2)
        loginctl terminate-user $(whoami);;
    $option3)
	    reboot;;
    $option4)
	    poweroff;;
esac
