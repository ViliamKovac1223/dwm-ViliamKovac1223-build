#!/bin/sh
sensors | grep Package | cut -d ' ' -f 5 | sed -e s/+//g # -e s/°C//g
