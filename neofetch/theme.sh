#!/bin/bash

[[ $1 == "" ]] && neofetch --config ~/.config/neofetch/cool_config.conf || neofetch --ascii "$(cowsay -f dragon -W 30 $1)" | lolcat -ats 100

