#!/bin/bash

delete(){
    sed -i "s/\"cpu\",//g" ~/.config/waybar/config
    sed -i "s/\"memory\",//g" ~/.config/waybar/config
    sed -i '/^$/d' ~/.config/waybar/config
} 

delete

Player_status=$(playerctl status) 

insert_pos="backlight"
insert_text="\\t\\t\"cpu\",\\n\\t\\t\"memory\","

if [[  $Player_status == "" ]]; then
    sed -i "/${insert_pos}/ a\\${insert_text}" ~/.config/waybar/config
else
    delete
   fi


