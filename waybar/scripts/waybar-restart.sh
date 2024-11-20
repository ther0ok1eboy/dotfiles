#!/usr/bin/env sh

# Terminate already running instances
killall -q waybar
killall -q cava
swww kill

# Wait until the processes have been shut down
while pgrep -x waybar >/dev/null; do sleep 1; done

# Launch main
swww init
sleep 1
swww-daemon
waybar
#~/.config/waybar/scripts/add-cpu-memory.sh 2> /dev/null
