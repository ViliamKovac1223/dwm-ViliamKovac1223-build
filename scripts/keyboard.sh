#!/bin/sh
echo " $(setxkbmap -query | grep layout | sed 's/layout:\s\+//')"
# icon: \ue955
