#!/bin/bash

last_hash=""

while clipnotify; do
  # 先尝试获取 X11 的剪贴板内容类型
  mimetype=$(xclip -selection clipboard -t TARGETS -o 2>/dev/null)

  if echo "$mimetype" | grep -q "image/png"; then
    # 是图片，从 X11 拿图片 → 写入 wl-copy
    xclip -selection clipboard -t image/png -o 2>/dev/null | wl-copy --type image/png
    # 再存入 cliphist（只支持 wl 方向）
    wl-paste --no-newline --type image/png | cliphist store --type image/png 2>/dev/null
  else
    # 获取文本（默认行为）
    selection="$(xclip -o -selection clipboard 2>/dev/null)"
    if [ $? -eq 0 ]; then
      echo -n "$selection" | wl-copy
    else
      selection="$(wl-paste --no-newline)"
      echo -n "$selection" | xclip -i
    fi

    # 使用哈希避免重复存储
    current_hash="$(printf "%s" "$selection" | sha256sum | awk '{print $1}')"
    if [ "$current_hash" != "$last_hash" ] && [ -n "$selection" ]; then
      printf "%s" "$selection" | cliphist store 2>/dev/null
      last_hash="$current_hash"
    fi
  fi
done
