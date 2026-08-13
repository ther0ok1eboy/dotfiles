#!/bin/bash

option0=" Lock"
option1="󰗽 Logout"
option2=" Suspend"
option3=" Reboot"
option4=" Shutdown"

options="$option0\n$option1\n$option2\n$option3\n$option4"

chosen="$(echo -e "$options" | fuzzel --config ~/.config/fuzzel/fuzzel_cliphist.ini --lines 5 --dmenu)"
case $chosen in
$option0)
  hyprlock
  ;;
$option1)
  loginctl terminate-user $(whoami)
  ;;
$option2)
  reboot
  ;;
$option3)
  poweroff
  ;;
esac
