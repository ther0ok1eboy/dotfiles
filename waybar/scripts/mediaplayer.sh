#!/bin/bash

player_status=$(playerctl status)
player_name=$(playerctl metadata --format "{{ playerName }}")

artist=$(playerctl metadata --format "{{ artist }}")
title=$(playerctl metadata --format "{{ title }}")
duration=$(playerctl metadata --format "{{ duration(position) }}/{{ duration(mpris:length) }}")


 [[ $player_status == "Playing" ]] &&  \
tooltip=" $player_status  $duration   $artist" || \
tooltip=" $player_status  $duration   $artist"

if [ "$player_name" == "spotify" ]; then
    echo "TODO"
elif [ "$player_name" == "netease-cloud-music" ]; then
    echo "{\"text\":\"󰫔 ${title}\", \"tooltip\":\"${tooltip}\"}"
fi
