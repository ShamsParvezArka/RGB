#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>

int main(void)
{
	//1.define the display
	Display *display = XOpenDisplay(NULL);
	if (display == NULL) {
		fprintf(stderr, "ERROR: could not open display\n");
		return 1;
	}

	//2.initialize the window(size, background color)
	Window window = XCreateSimpleWindow(
			display,
			XDefaultRootWindow(display),
			0, 0,
			800, 600,
			0,
			0,
			0);

	//7.Initialize the Delete_window_event function then goto 'event' part
	Atom wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(display, window, &wm_delete_window, 1);

	//6.Initialize the Keyboard_event function.
	XSelectInput(display, window, KeyPressMask);

	XPutImage(display, window, gc, image, 
			src_x, src_y, 
			dest_x, dest_y, 
			800, 600)

	//3.Map the defined display & window together
	XMapWindow(display, window);

	
	//4.Syncronize the defined display
	XSync(display, False);
	
	//event
	int quite = 0;
	while (!quite) {
		XEvent event = {0};
		XNextEvent(display, &event);
		switch (event.type) {
			case KeyPress:
				printf("the key has been pressed\n");
				break;

			case ClientMessage: 
				if ((Atom) event.xclient.data.l[0] == wm_delete_window) {
					printf("Window closed\n");
					quite = 1;
				}
				break;
		}
	
	}
	
	//5.close the window
	XCloseDisplay(display);

	return 0;
}

