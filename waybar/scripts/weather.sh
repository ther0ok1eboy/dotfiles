#!/usr/bin/env bash

CACHE="$HOME/.config/waybar/scripts/weather_cache/weather.json"
CACHE_TIME=600 # 缓存有效期：600 秒

# 创建缓存目录
mkdir -p "$(dirname "$CACHE")"

# 判断是否需要更新
need_update=false

if [ ! -f "$CACHE" ]; then
  need_update=true
else
  now=$(date +%s)
  mtime=$(stat -c %Y "$CACHE")

  if [ $((now - mtime)) -ge "$CACHE_TIME" ]; then
    need_update=true
  fi
fi

# 获取最新天气
if [ "$need_update" = true ]; then
  data=$(curl -s --compressed \
    "https://k6487tfd79.re.qweatherapi.com/v7/weather/now?location=101020100&lang=en&key=ec367b5ebc3847cabeb52006b797c4d2")

  # API 返回正常才保存
  if echo "$data" | jq -e '.now' >/dev/null 2>&1; then
    printf '%s\n' "$data" >"$CACHE"
  fi
fi

# 缓存不存在，直接退出
if [ ! -f "$CACHE" ]; then
  echo '{"text":"󰖙 --°C","tooltip":"Weather data unavailable","class":"weather","alt":"0","percentage":0}'
  exit 0
fi

# 从缓存读取
data=$(cat "$CACHE")

# 解析天气
temp=$(echo "$data" | jq -r '.now.temp // "0"')
feels=$(echo "$data" | jq -r '.now.feelsLike // "0"')
text=$(echo "$data" | jq -r '.now.text // "Unknown"')
windDir=$(echo "$data" | jq -r '.now.windDir // "Unknown"')
windSpeed=$(echo "$data" | jq -r '.now.windSpeed // "0"')

# 确保数字有效
[[ "$temp" =~ ^-?[0-9]+$ ]] || temp=0
[[ "$windSpeed" =~ ^[0-9]+$ ]] || windSpeed=0

# 天气图标：Nerd Font
case "$text" in
Clear | Sunny)
  icon="󰖙 "
  ;;
Cloudy)
  icon="󰖐 "
  ;;
Overcast)
  icon="󰖑 "
  ;;
Rain* | Shower*)
  icon="󰖗 "
  ;;
Thunder*)
  icon="󰖓 "
  ;;
Snow*)
  icon="󰖘 "
  ;;
Fog* | Mist | Haze)
  icon="󰖑 "
  ;;
*)
  icon="󰖐 "
  ;;
esac

# 风速图标：Nerd Font
if [ "$windSpeed" -le 2 ]; then
  windIcon="󰖝 "
elif [ "$windSpeed" -le 5 ]; then
  windIcon="󰖞 "
elif [ "$windSpeed" -le 10 ]; then
  windIcon="󰖙 "
else
  windIcon="󰖛 "
fi

# 温度颜色
if [ "$temp" -le 0 ]; then
  color="#4A90E2"
elif [ "$temp" -le 15 ]; then
  color="#50E3C2"
elif [ "$temp" -le 25 ]; then
  color="#F5A623"
else
  color="#D0021B"
fi

# 输出 JSON 给 Waybar
printf '{"text":"%s%s°C ","tooltip":"%s, Feels like %s°C, %s wind %s %s km/h","class":"weather","alt":"%s","percentage":%s,"color":"%s"}\n' \
  "$icon" "$temp" "$text" "$feels" "$windDir" "$windIcon" "$windSpeed" "$temp" "$temp" "$color"
