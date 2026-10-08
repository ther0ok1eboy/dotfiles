#!/bin/bash

player_status=$(playerctl status 2>/dev/null)

[[ "$player_status" != "Playing" ]] && exit 0

artist=$(playerctl metadata --format "{{ artist }}")
title=$(playerctl metadata --format "{{ title }}")
duration=$(playerctl metadata --format "{{ duration(position) }}/{{ duration(mpris:length) }}")

tooltip=" $player_status  $duration  $artist"

echo "{\"text\":\"$title\", \"tooltip\":\"$tooltip\"}"
