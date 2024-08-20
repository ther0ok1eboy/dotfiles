#!/bin/bash

# Screenshot for text recognition and copy to clipboard
grim -g "$(slurp)" - | swappy -f - -o /tmp/ocr.png

tesseract -l eng+chi_sim /tmp/ocr.png /tmp/ocr

cat /tmp/ocr.txt | sed -r 's/([^0-9a-z])?\s+([^0-9a-z])/\1\2/ig' | wl-copy

