#!/bin/sh
# echo " $(xbacklight -get)%"# did work fine on manjaro but doesn't work so good on arch linux
# echo " $(xbacklight -get | cut -d '.' -f 1)%"

brightness=$($HOME/.local/src/dwm/scripts/brightnessGet.sh)
echo " $brightness%" # debian version
# icon: \ue9d6
