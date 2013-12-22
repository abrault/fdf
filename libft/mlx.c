#include "libft.h"

GC	mlx_getColor(Display *dis, Window win, char *code)
{
	GC		color;
	XColor		color_col;
	Colormap	colormap;

	colormap = DefaultColormap(dis, 0);
	color = XCreateGC(dis, win, 0, 0);
	XParseColor(dis, colormap, code, &color_col);
	XAllocColor(dis, colormap, &color_col);
	XSetForeground(dis, color, color_col.pixel);
	return (color);
}

void	mlx_CreateWindow(Display **dis, Window *win, int h, int w)
{
	int		s;

	*dis = XOpenDisplay(NULL);
	s = DefaultScreen(*dis);
	*win = XCreateSimpleWindow(*dis, RootWindow(*dis, s), 1, 1, w,
		h, 1, BlackPixel(*dis, s), BlackPixel(*dis, s));
	XSelectInput(*dis, *win, ExposureMask | KeyPressMask);
	XMapWindow(*dis, *win);
}
