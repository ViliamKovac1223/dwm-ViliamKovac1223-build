#!/bin/bash

keybord="$(setxkbmap -query | grep layout | cut -c 13,14)"

if [ $keybord  == "us" ];then
	setxkbmap sk qwerty
else
	setxkbmap us
fi		
