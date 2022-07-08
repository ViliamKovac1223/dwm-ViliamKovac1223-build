#!/bin/sh
amixer | grep "'Capture',0" -A 5 | tail -n 1 | awk '{ print $5$6 }' | sed -e 's/\[//g' -e 's/\]//g' -e 's/off/!/' -e 's/on//'
# '  '
#'  '

