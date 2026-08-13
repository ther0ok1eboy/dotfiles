#!/bin/bash

# 你的待办文件（可以自己改）
TODO_FILE="$HOME/Documents/future-plans.md"

# 如果文件不存在
if [ ! -f "$TODO_FILE" ]; then
  echo '{"text":"","tooltip":"No TODO file"}'
  exit 0
fi

# 读取待办内容
todo_content=$(cat "$TODO_FILE")

# 如果为空
if [ -z "$todo_content" ]; then
  echo '{"text":"","tooltip":"Nothing to do 🎉"}'
  exit 0
fi

# 转义换行（Waybar tooltip 支持 \n）
tooltip=$(printf "%s" "$todo_content" | sed ':a;N;$!ba;s/\n/\\n/g')

# 显示条目数量
count=$(grep -c "" "$TODO_FILE")

# 输出 JSON
echo "{\"text\":\" $count\",\"tooltip\":\"$tooltip\"}"
