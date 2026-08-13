#!/usr/bin/env bash

time=$1

while (($time > 0)); do
  if (($time == 1)); then
    killall waybar
    sleep 1
    waybar &
    time=$1
  fi
  sleep 1
  let "time--"
  echo $time
done
