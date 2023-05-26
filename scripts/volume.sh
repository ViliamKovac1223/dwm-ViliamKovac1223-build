#!/bin/sh
# icon volume on:      \uea26
# icon volume off:     \uea2a

volume=$(pactl list sinks | grep -e '^[[:space:]]Volume:' | awk '{print $5}')
muted=$(pactl list sinks | grep '^[[:space:]]Mute:' | head -n 1 | awk '{print $2}')

if [ "$muted" = "no" ]; then
    echo "$volume";
else
    echo "$volume";
fi

