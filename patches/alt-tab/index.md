Alt-tab
=======

Description
-----------
This patch add alt-tab like functionality to dwm.
It cycles through windows/clients in their recently used order.

Configuration Options
---------------------
* `tabModKey` - If this key is hold the alt-tab functionality stays active. This key must be the same as key that is used to active function altTabStart 
* `tabCycleKey` - If this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active function altTabStart
* `tabPosY` - Tab position on Y axis, 0 = bottom, 1 = center, 2 = top
* `tabPosX` - Tab position on X axis, 0 = left, 1 = center, 2 = right
* `maxWTab` - Tab menu width
* `maxHTab` - Tab menu height

keycode
-------
tabModkye and tabCycleKey are keycodes values.
If you want to change them you can get different keycode values from "get-xkey" program bellow.

Compile get-xkey
``
gcc get-xkey.c -L/usr/X11R6/lib -lX11 -o get-xkey
``
run
``
./get-xkey
``
Now just press desired key and watch output in stdout.
To quit program just close the window or in the terminal press Ctrl+c.

Notes
-----
This patch is also hosted on my [github](https://github.com/ViliamKovac1223/dwm-ViliamKovac1223-build/tree/main/patches).

Download
--------
* [dwm-alttab-20220709-d3f93c7.diff](dwm-alttab-20220709-d3f93c7.diff)
* [dwm-alttab-6.4.diff](dwm-alttab-6.4.diff) LATEST
* [get-xkey.c](get-xkey.c)

Authors
-------
* Viliam Kováč - viliamkovac1223@gmail.com

Contributors
------------
* Daniel Gerblick - daniel.gerblick@gmail.com

Fake Internet money
-------------------
If you like my work and want to support me by some fake internet money, here is my monero address

85EVKkDnQMYZxmJ7Fj5dG6Lw9V3vZRxAjft3btaB2FhzTCGoGocbRTAS857tgZvy1QD5cShxxp98S6y3utG3nqMTVARnW8P
