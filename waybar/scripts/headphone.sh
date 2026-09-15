#!/usr/bin/env bash

# ============================================================
# 检查已连接的蓝牙设备
# ============================================================

device=""

while read -r _ mac _; do
  [[ -z "$mac" ]] && continue

  info=$(bluetoothctl info "$mac" 2>/dev/null)

  # 必须是已连接
  if ! grep -q "Connected: yes" <<<"$info"; then
    continue
  fi

  # 判断是否为耳机/音频设备
  if grep -Eq "Icon: audio-(headset|headphones)" <<<"$info"; then
    device="$mac"
    break
  fi

done < <(bluetoothctl devices Connected 2>/dev/null)

# ============================================================
# 没有连接蓝牙耳机
# ============================================================

if [[ -z "$device" ]]; then
  sleep 0.1
  pavucontrol &
  exit 0
fi

# ============================================================
# 获取蓝牙耳机信息
# ============================================================

info=$(bluetoothctl info "$device" 2>/dev/null)

name=$(awk -F': ' '/^[[:space:]]*Name:/ {
    print $2
    exit
}' <<<"$info")

battery=$(awk -F'[()]' '/Battery Percentage:/ {
    print $2
    exit
}' <<<"$info")

# ============================================================
# 无法读取电量
# ============================================================

if [[ ! "$battery" =~ ^[0-9]+$ ]]; then
  notify-send \
    -a "Bluetooth" \
    "󰋋 蓝牙耳机" \
    "${name:-蓝牙耳机} 已连接，但无法读取电量"
  exit 0
fi

# ============================================================
# 根据电量选择图标
# ============================================================

if ((battery <= 10)); then
  icon="󰂎"
elif ((battery <= 20)); then
  icon="󰁻"
elif ((battery <= 30)); then
  icon="󰁼"
elif ((battery <= 40)); then
  icon="󰁽"
elif ((battery <= 50)); then
  icon="󰁾"
elif ((battery <= 60)); then
  icon="󰁿"
elif ((battery <= 70)); then
  icon="󰂀"
elif ((battery <= 80)); then
  icon="󰂁"
elif ((battery <= 90)); then
  icon="󰂂"
else
  icon="󰂃"
fi

# ============================================================
# Mako 通知
# ============================================================

notify-send \
  -a "Bluetooth" \
  -u normal \
  "$icon  $name" \
  "Current Battery Level: ${battery}%" \
  -h "string:x-canonical-private-synchronous:bluetooth-battery"
