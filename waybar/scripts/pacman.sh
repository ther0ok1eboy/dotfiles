#!/bin/bash

frames=(
  "󰮯 󰊠 󰊠 󰊠 󰊠 󰊠 󰊠 "
  "  󰮯 󰊠 󰊠 󰊠 󰊠 󰊠 "
  "    󰮯 󰊠 󰊠 󰊠 󰊠 "
  "      󰮯 󰊠 󰊠 󰊠 "
  "        󰮯 󰊠 󰊠 "
  "          󰮯 󰊠 "
  "            󰮯 "
  "󰊠 󰊠 󰊠 󰊠 󰊠 󰊠 󰊠 "
  "󰊠 󰊠 󰊠 󰊠 󰊠 󰊠 󱫱 "
  "󰊠 󰊠 󰊠 󰊠 󰊠 󱫱   "
  "󰊠 󰊠 󰊠 󰊠 󱫱     "
  "󰊠 󰊠 󰊠 󱫱       "
  "󰊠 󰊠 󱫱         "
  "󰊠 󱫱           "
  "󱫱             "
)

while true; do
  for frame in "${frames[@]}"; do
    printf '%s\n' "$frame"
    sleep 1
  done
done
