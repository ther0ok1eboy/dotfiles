#!/usr/bin/env bash
set -euo pipefail
font_dir="${XDG_DATA_HOME:-$HOME/.local/share}/fonts"
mkdir -p "$font_dir"
cp "$(dirname "$0")/ComicShannsMonoNerdFont-Reverse-v14.otf" "$font_dir/"
fc-cache -f "$font_dir" >/dev/null 2>&1 || true
printf '字体已安装到: %s\n' "$font_dir"
printf 'Kitty 字体设置: ComicShannsMono Nerd Font Reverse V14\n'
printf '自定义圆角正方形: 󱫴󱫵\n'
