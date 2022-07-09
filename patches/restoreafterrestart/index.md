Restore after restart
=====================

Description
-----------
After restarting your dwm all your windows/clients are all in one tag, first tag.
Well no more, This patch save tag of every window/client to the file and after dwm is restarted
the file is read and used to get all the windows/clients in their previous tags.

Configuration Options
---------------------
* `SESSION_FILE` - path to the file which is used to store tags to all windows/clients

Notes
-----
This patch is supposed be used along the [restartsig](../restartsig/index.md), if you want use this patch with your own 
way how to restart dwm then put "saveSession()" before restarting dwm and put "restoreSession()" after
dwm was restarted. 
Patch has been coded based on [this debate](https://bbs.archlinux.org/viewtopic.php?id=196975).
This patch is also hosted on my [github](https://github.com/ViliamKovac1223/dwm-ViliamKovac1223-build/tree/main/patches).

Download
--------
* [dwm-restoreafterrestart-20220709-d3f93c7.diff](dwm-restoreafterrestart-20220709-d3f93c7.diff)

Authors
-------
* Viliam Kováč - viliamkovac1223@gmail.com

Fake Internet money
-------------------
If you like my work and want to support me by some fake internet money, here is my monero address

8722XFCUGajWxpdKQY4V2ije88Ti2v97VWLS9p9rvNTcWd7VisuKQzvQYNan37jYnv7thECLkrnbm6CKdA2jhdFFTLV8nav
