#!/usr/bin/env bash

set -u

PIPE="/tmp/waybar-cava.fifo"
CONFIG="/tmp/waybar-cava.conf"

# Cava levels: 0-7
BARS="▁▂▃▄▅▆▇█"

cava_pid=""

cleanup() {
  if [[ -n "$cava_pid" ]]; then
    kill "$cava_pid" 2>/dev/null
    wait "$cava_pid" 2>/dev/null
  fi

  rm -f "$PIPE" "$CONFIG"
}

trap cleanup EXIT INT TERM HUP

# Clean up possible leftovers
rm -f "$PIPE" "$CONFIG"

# Create FIFO
mkfifo "$PIPE"

# Cava configuration
cat >"$CONFIG" <<EOF
[general]
bars = 16
framerate = 30

[output]
method = raw
raw_target = $PIPE
data_format = ascii
ascii_max_range = 7
EOF

# Start Cava
cava -p "$CONFIG" &
cava_pid=$!

# Read Cava output
while IFS= read -r line; do
  # Remove semicolon without spawning sed
  line=${line//;/}

  # Convert 0-7 to ▁▂▃▄▅▆▇█
  output=""

  for ((i = 0; i < ${#line}; i++)); do
    char=${line:i:1}

    case "$char" in
    0) output+="▁" ;;
    1) output+="▂" ;;
    2) output+="▃" ;;
    3) output+="▄" ;;
    4) output+="▅" ;;
    5) output+="▆" ;;
    6) output+="▇" ;;
    7) output+="█" ;;
    esac
  done

  printf '%s\n' "$output"
done <"$PIPE"
