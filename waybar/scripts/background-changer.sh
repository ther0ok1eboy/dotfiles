#!/usr/bin/env bash

#wallpapers_path="/home/sorria/Pictures/Wallpapers/Christmas"
wallpapers_path="/home/ther0ok1eboy/Pictures/Wallpapers/backgrounds"

wallpaper_name=$(find $wallpapers_path -type f | shuf -n 1)

swww img --transition-fps 60 --transition-type grow --transition-duration 2 --transition-pos top-left $wallpaper_name
