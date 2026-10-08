#!/bin/bash

set -euo pipefail

geometry=$(slurp) || exit 0

ocr_text=$(
  grim -g "$geometry" - |
    magick - \
      -resize 200% \
      -colorspace Gray \
      -contrast-stretch 0x10% \
      png:- |
    tesseract stdin stdout \
      -l eng+chi_sim \
      --psm 6 \
      2>/dev/null |
    perl -CSD -pe '
        s/\s+/ /g;

        # 中文之间去除 OCR 空格
        s/([\x{3400}-\x{4DBF}\x{4E00}-\x{9FFF}])\s+(?=[\x{3400}-\x{4DBF}\x{4E00}-\x{9FFF}])/$1/g;

        # 中文标点前去空格
        s/ +([，。！？；：、）】》」』’”])/$1/g;

        # 左括号/引号后去空格
        s/([（【《「『“‘]) +/$1/g;

        # 中英文/数字之间保留一个空格
        s/([A-Za-z0-9]) +(?=[\x{3400}-\x{4DBF}\x{4E00}-\x{9FFF}])/$1 /g;
        s/([\x{3400}-\x{4DBF}\x{4E00}-\x{9FFF}]) +(?=[A-Za-z0-9])/$1 /g;

        s/^ +| +$//g;
    '
)

if [[ -z "${ocr_text//[[:space:]]/}" ]]; then
  notify-send "🔍 OCR" "❌ No text recognized"
  exit 1
fi

printf '%s' "$ocr_text" | wl-copy

notify-send "🔍 OCR" "✅ Successful. The text has been copied to the clipboard."
