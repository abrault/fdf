/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:41:45 by abrault           #+#    #+#             */
/*   Updated: 2013/11/28 17:33:08 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "head.h"

/* Permet la creation de la couleur */
GC	Color(char *code)
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

void	BuildAllSegment(int tab[12][19])
{
	int		x;
	int		y;
	int		q;

	y = 0;
	q = 0;
	while (y < 11)
	{
		x = 0;
		while (x < 19)
		{
			if ((tab[y][x] > 0 || tab[y + 1][x] > 0 ||
			tab[y][x + 1] > 0 || (tab[y + 1][x] < tab[y][x]))
			&& y < 11)
				XDrawLine(dis, win, Color("#FF0000"),
				(x + 10) * 25 - (q * 20), (y + 2) * 25 -
				tab[y][x] * 2, (x + 10 + 1) * 25 - (q * 20),
				(y + 2) * 25 - tab[y][x + 1] * 2);
			else if (x < 18)
				XDrawLine(dis, win, Color("#FEFEFE"),
				(x + 10) * 25 - (q * 20), (y + 2) * 25 -
				tab[y][x] * 2, (x + 10 + 1) * 25 - (q * 20),
				(y + 2) * 25 - tab[y][x + 1] * 2);
			if (y <  10 && (tab[y + 1][x] > 0 || tab[y][x] > 0))
				XDrawLine(dis, win, Color("#FF0000"),
				(x + 10) * 25 - (q * 20), (y + 2) * 25 -
				tab[y][x] * 2, (x + 10) * 25 - ((q + 1) * 20),
				(y + 2 + 1) * 25 - tab[y + 1][x] * 2);
			else if (y <  10)
				XDrawLine(dis, win, Color("#FEFEFE"),
				(x + 10) * 25 - (q * 20), (y + 2) * 25 -
				tab[y][x] * 2, (x + 10) * 25 - ((q + 1) * 20),
				(y + 2 + 1) * 25 - tab[y + 1][x] * 2);
			x++;
		}
		q++;
		y++;
	}
}

int	main(void)
{
	int		s;
	int		tab[12][19] ={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,10,10,0,0,10,10,0,0,0,10,10,10,10,10,0,0,0},
	{0,0,10,10,0,0,10,10,0,0,0,0,0,0,0,10,10,0,0},
	{0,0,10,10,0,0,10,10,0,0,0,0,0,0,0,10,10,0,0},
	{0,0,10,10,10,10,10,10,0,0,0,0,10,10,10,10,0,0,0},
	{0,0,0,10,10,10,10,10,0,0,0,10,10,0,0,0,0,0,0},
	{0,0,0,0,0,0,10,10,0,0,0,10,10,0,0,0,0,0,0},
	{0,0,0,0,0,0,10,10,0,0,0,10,10,10,10,10,10,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
	dis = XOpenDisplay(NULL);
	s = DefaultScreen(dis);
	win = XCreateSimpleWindow(dis, RootWindow(dis, s), 1, 1, 750, 350, 1,
		BlackPixel(dis, s), BlackPixel(dis, s));
	XSelectInput(dis, win, ExposureMask | KeyPressMask);
	XMapWindow(dis, win);
	while (1)
	{
		XNextEvent(dis, &e);
		if (e.type == Expose)
			BuildAllSegment(tab);
		if (e.type == KeyPress)
		{
			if ((int) XLookupKeysym (&e.xkey, 0) == 65307)
				break ;
		}
	}
	XCloseDisplay(dis);
	return 0;
}
