#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
 
int main(void) {
	Display *dpy;
	Window win;
	XEvent e;
	int s;
 
	dpy = XOpenDisplay(NULL);
	if (dpy == NULL) {
		fprintf(stderr, "Cannot open display\n");
		exit(1);
	}
 
	s = DefaultScreen(dpy);
	win = XCreateSimpleWindow(dpy, RootWindow(dpy, s), 10, 10, 100, 100, 0, 0, 0);
	XSelectInput(dpy, win, ExposureMask | KeyPressMask);
	XMapWindow(dpy, win);
 
	while (1) {
		XNextEvent(dpy, &e);
		if (e.type == KeyPress)
			printf("0x%x\n",e.xkey.keycode);
	}
 
   XCloseDisplay(dpy);
   return 0;
}
