#!/usr/bin/env bash

# 获取当前小时
current_hour=$(date +"%H")

# 判断当前时间段
if ((current_hour >= 8 && current_hour < 17)); then
  wallpapers_path="/home/ther0ok1eboy/Pictures/Wallpaper-Bank-main/wallpapers/Dynamic-Wallpapers/Dark"
else
  wallpapers_path="/home/ther0ok1eboy/Pictures/Wallpaper-Bank-main/wallpapers/Dynamic-Wallpapers/Light"
fi

wallpaper_name=$(find $wallpapers_path -type f | shuf -n 1)

awww img --transition-fps 60 --transition-type grow --transition-duration 2 --transition-pos top-left $wallpaper_name
