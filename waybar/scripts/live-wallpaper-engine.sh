#!/usr/bin/env bash

WALL_DIR="$HOME/Pictures/Wallpapers/dynamicBackgroud/"
MONITOR="*"

# mpvpaper 参数
OPTS="loop --no-audio --panscan=1.0 --hwdec=auto --profile=fast"

while true; do
  VIDEO=$(find "$WALL_DIR" -type f -name "*.mp4" | shuf -n 1)

  echo "[+] switching wallpaper: $VIDEO"

  # 杀掉旧 mpvpaper（关键）
  pkill mpvpaper

  # 启动新壁纸
  mpvpaper "$MONITOR" "$VIDEO" -o "$OPTS" &

  # 等 1 小时
  sleep 3600
done
