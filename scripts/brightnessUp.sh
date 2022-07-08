#!/bin/sh

up_const=2 # increase of brightness in percentage

xbacklight -inc "$up_const"

# max_brightness=$(cat /sys/class/backlight/intel_backlight/max_brightness)
# brightness=$(cat /sys/class/backlight/intel_backlight/brightness)

# new_brightness=$(($max_brightness / 100 * $up_const + $brightness)) # calculate new_brightness

# if [ "$new_brightness" -gt "$max_brightness" ]; then
  # new_brightness=$max_brightness
# fi

# write new value to brightness file
# echo "$new_brightness" | tee /sys/class/backlight/intel_backlight/brightness
