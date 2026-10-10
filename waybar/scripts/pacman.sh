#!/bin/bash

# Pac-Man Waybar animation
#
# Each track position occupies two text cells:
#   bean      = 󱫴󱫵
#   item/ghost = icon + space
#
# A new track is generated for every direction:
#   left -> right -> right -> left -> ...
#
# Scoring:
#   bean       +1
#   black dot  +5
#   cherry    +10
#   orange    +50
#   apple     +70
#   watermelon +100
#   ghost       0

BEAN_COUNT=10
FRAME_DELAY=1

PACMAN_LEFT="󰮯"
PACMAN_RIGHT="󱫱"
BEAN="󱫴󱫵"

# Icons read from ~/a.txt, plus the new black-dot item:
#   ⬤   black dot
#      cherry
#      orange
#   󰉛   food-apple
#   󱁇   fruit-watermelon
#   󰊠   ghost
BLACK_DOT_ICON="⬤"
CHERRY_ICON=""
ORANGE_ICON=""
APPLE_ICON="󰉛"
WATERMELON_ICON="󱁇"
GHOST_ICON="󰊠"

score=0
declare -a slots
declare -a slot_types

random_slot() {
  printf '%d' "$((RANDOM % BEAN_COUNT))"
}

new_track() {
  local i special_index roll

  slots=()
  slot_types=()

  for ((i = 0; i < BEAN_COUNT; i++)); do
    slots[i]="$BEAN"
    slot_types[i]="bean"
  done

  # Mutually exclusive probabilities using a denominator of 300:
  # black dot 1/5, cherry 1/10, orange 1/20, apple 1/30,
  # watermelon 1/50, ghost 1/20, otherwise beans only.
  roll=$((RANDOM % 300))

  if (( roll < 60 )); then
    special_index=$(random_slot)
    slots[special_index]="${BLACK_DOT_ICON} "
    slot_types[special_index]="black_dot"
  elif (( roll < 90 )); then
    special_index=$(random_slot)
    slots[special_index]="${CHERRY_ICON} "
    slot_types[special_index]="cherry"
  elif (( roll < 105 )); then
    special_index=$(random_slot)
    slots[special_index]="${ORANGE_ICON} "
    slot_types[special_index]="orange"
  elif (( roll < 115 )); then
    special_index=$(random_slot)
    slots[special_index]="${APPLE_ICON} "
    slot_types[special_index]="apple"
  elif (( roll < 121 )); then
    special_index=$(random_slot)
    slots[special_index]="${WATERMELON_ICON} "
    slot_types[special_index]="watermelon"
  elif (( roll < 136 )); then
    special_index=$(random_slot)
    slots[special_index]="${GHOST_ICON} "
    slot_types[special_index]="ghost"
  fi
}

consume_slot() {
  local position=$1

  case "${slot_types[position]}" in
    bean)
      ((score += 1))
      ;;
    black_dot)
      ((score += 5))
      ;;
    cherry)
      ((score += 10))
      ;;
    orange)
      ((score += 50))
      ;;
    apple)
      ((score += 70))
      ;;
    watermelon)
      ((score += 100))
      ;;
    ghost)
      score=0
      ;;
  esac

  slots[position]="  "
  slot_types[position]="empty"
}

render_track() {
  local pacman_position=$1
  local pacman_icon=$2
  local line=""
  local i

  for ((i = 0; i < BEAN_COUNT; i++)); do
    if ((i == pacman_position)); then
      # Pac-Man occupies the same two-cell slot as a bean.
      line+="${pacman_icon} "
    else
      line+="${slots[i]}"
    fi
  done

  # The score is always displayed at the beginning.
  printf '%3d | %s\n' "$score" "$line"
}

show_track_without_pacman() {
  local line=""
  local slot

  for slot in "${slots[@]}"; do
    line+="$slot"
  done

  printf '%3d | %s\n' "$score" "$line"
}

run_direction() {
  local direction=$1
  local pacman_icon
  local position

  if [[ "$direction" == "right" ]]; then
    pacman_icon="$PACMAN_LEFT"
    for ((position = 0; position < BEAN_COUNT; position++)); do
      consume_slot "$position"
      render_track "$position" "$pacman_icon"
      sleep "$FRAME_DELAY"
    done
  else
    pacman_icon="$PACMAN_RIGHT"
    for ((position = BEAN_COUNT - 1; position >= 0; position--)); do
      consume_slot "$position"
      render_track "$position" "$pacman_icon"
      sleep "$FRAME_DELAY"
    done
  fi
}

while true; do
  # Left-to-right pass.
  new_track
  show_track_without_pacman
  sleep "$FRAME_DELAY"
  run_direction right

  # Right-to-left pass.
  new_track
  show_track_without_pacman
  sleep "$FRAME_DELAY"
  run_direction left
done
