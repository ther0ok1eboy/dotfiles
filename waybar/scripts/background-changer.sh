#!/usr/bin/env bash

wallpapers_path="/home/sorria/Pictures/Wallpapers/backgrounds"

wallpaper_name=$(find $wallpapers_path -type f | shuf -n 1)

swww img $wallpaper_name --transition-fps 60 --transition-type grow --transition-duration 2 --transition-pos 0.027,0.977
