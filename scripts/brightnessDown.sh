#!/bin/sh

down_const=2 # decrease of brightness in percentage

xbacklight -dec "$down_const"

# max_brightness=$(cat /sys/class/backlight/intel_backlight/max_brightness)
# brightness=$(cat /sys/class/backlight/intel_backlight/brightness)

# new_brightness=$(($brightness - $max_brightness / 100 * $down_const)) # calculate new_brightness

# if [ "$new_brightness" -lt 0 ]; then
  # new_brightness=0
# fi

# write new value to brightness file
# echo "$new_brightness" | tee /sys/class/backlight/intel_backlight/brightness
