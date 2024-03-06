#!/bin/sh

defaultCard=$(pactl list | grep -B 2 "Name: $(pactl get-default-sink)$" | head -n1  | awk '{print $2}' | tr -d '#')
pactl set-sink-volume "$defaultCard" +2%
