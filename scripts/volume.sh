#!/bin/sh
# icon volume on:      \uea26
# icon volume off:     \uea2a

defaultCard=$(pactl list  | grep -B 2 "Name: $(pactl get-default-sink)$" | head -n1  | awk '{print $2}' | tr -d '#')
volume=$(pactl list sinks | grep -A 10 "Sink #$defaultCard" | grep -e '^[[:space:]]Volume:' | awk '{print $5}')
muted=$(pactl list sinks  | grep -A 10 "Sink #$defaultCard" | grep '^[[:space:]]Mute:' | head -n 1 | awk '{print $2}')

if [ "$muted" = "no" ]; then
    echo "  $volume";
    # echo "󰝝 $volume";
else
    echo "󰖁  $volume";
    # echo "󰝟 $volume";
fi

