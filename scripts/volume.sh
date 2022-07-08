#!/bin/sh
amixer sget Master | grep "Right:" | awk '{print $6 $5}' | sed -e 's/\[//g' -e 's/\]//g' -e 's/on//g' -e 's/off//g'
# icon volume on: \uea26
# icon volume off: \uea2a

# increase by 3%
#amixer -q sset Master 3%+

# decrease by 3%
#amixer -q sset Master 3%-

# mute/unmute
#amixer -q sset Master toggle

