#!/usr/bin/env bash

file="$1"

# 参数校验
[ -z "$file" ] && {
  echo "Usage: $0 <file>"
  exit 1
}

# 统一转小写后缀
case "${file##*.}" in
docx)
  exec pandoc "$file" --strip-comments -t plain
  ;;
xlsx)
  exec xlsx2csv "$file"
  ;;
xls)
  exec xls2csv "$file"
  ;;
*)
  exec file -sL "$file"
  ;;
esac
