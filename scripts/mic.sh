#!/bin/sh
# icon for microphone   

volume=$(pactl list sources | grep "Source #[0-9]" -A 9 | tail -n1 | awk '{print $5}')
muted=$( pactl list sources | grep "Source #[0-9]" -A 8 | tail -n1 | awk '{print $2}')

if [ "$muted" = "no" ]; then
    echo "$volume";
else
    echo "!$volume";
fi

