#!/usr/bin/env bash

temperature_conv(){
	echo "($1-32)/1.8" | bc
}

text=$(curl -s "https://wttr.in/$1?format=%c+%f")

if [[ $? == 0 ]]
then
    text=$(echo "$text" | sed -E "s/\s+/ /g")
    weather_icon=$(echo "$text" | sed -E "s/\s+/ /g" | awk '{print $1}')
    temperature=$(echo "$text" | tr -c '[:digit:]' ' ' | sed -E "s/\s+//g")
    #temperature=$(temperature_conv $temperature)
    tooltip=$(curl -s "https://wttr.in/$1?format=%l:+%C+%c+%t+%w")
    if [[ $? == 0 ]]
    then
        tooltip=$(echo "$tooltip" | sed -E "s/\s+/ /g")
        echo "{\"text\":\"${weather_icon} ${temperature}°C\", \"tooltip\":\"$tooltip\"}"
        exit
    fi
fi

echo "{\"text\":\"Service Unavailable\", \"tooltip\":\"Service Unavailable\"}
