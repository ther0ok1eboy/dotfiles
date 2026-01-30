#!/usr/bin/env bash

# 获取完整路径
filepath="$1"

# 参数检查
[ -z "$filepath" ] && {
  echo "Usage: $0 <file_path>"
  exit 1
}

# 检查文件是否存在
[ ! -f "$filepath" ] && {
  echo "File does not exist: $filepath"
  exit 1
}

# 提取目录和文件名
dir="$(dirname "$filepath")"
file="$(basename "$filepath")"

# 切换到目录
cd "$dir" || exit 1

# 使用 wps 打开文件
wps "$file" &
