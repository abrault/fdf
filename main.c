/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:41:45 by abrault           #+#    #+#             */
/*   Updated: 2013/12/12 14:17:29 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		getVal(char *file, int x, int y, char *c)
{
	int		_x;
	int		_y;
	int		fd;
	char	*line;
	char	*tok;

	_y = 0;
	x++;
	y++;
	fd = open(file, O_RDONLY);
	while (_y < y)
	{
		_x = 0;
		get_next_line(fd, &line);
		tok = strtok(line, " ");
		while (_x < x)
		{
			tok = strtok(NULL, " ");
			printf(" %s |", tok);
			if (ft_strcmp(line, "\n") == 0)
				*c = '\n';
			if (ft_strcmp(line, "\0") == 0)
				*c = '\0';
			_x++;
		}
		_y++;
	}
	close(fd);
	return (ft_atoi(tok));
}

void	BuildAllSegment(char *file, Display *dis, Window win)
{
	int		x;
	int		y;
	int		q;
	int		val[3];
	char	c;

	c = '0';
	y = 0;
	q = 0;
	while (c != '\0')
	{
		x = 0;
		while (1)
		{
			printf("x = %d\n", x);
			val[0] = getVal(file, x, y, &c);
			if (c == '\n')
				break ;
			val[1] = getVal(file, x + 1, y, &c);
			val[2] = getVal(file, x, y + 1, &c);
			if (((val[0] > 0) || (val[2] > 0) ||
			(val[1] > 0) || (val[2] < val[0])) && y < 11)
				XDrawLine(dis, win, mlx_getColor(dis, win,
				"#FF0000"),(x + 10) * 25 - (q * 20), (y + 2)
				* 25 - val[0] * 2, (x + 10 + 1) * 25 -
				(q * 20), (y + 2) * 25 - val[1] * 2);
			else if (x < 18)
				XDrawLine(dis, win, mlx_getColor(dis, win,
				"#FEFEFE"),(x + 10) * 25 - (q * 20), (y + 2)
				* 25 - val[0] * 2, (x + 11) * 25 -
				(q * 20), (y + 2) * 25 - val[1] * 2);
			if (y <  10 && (val[2] > 0 || val[0] > 0))
				XDrawLine(dis, win, mlx_getColor(dis, win,
				"#FF0000"), (x + 10) * 25 - (q * 20), (y + 2)
				* 25 - val[0] * 2, (x + 10) * 25 - ((q + 1)
				* 20), (y + 3) * 25 - val[2] * 2);
			else if (y <  10)
				XDrawLine(dis, win, mlx_getColor(dis, win,
				"#FEFEFE"), (x + 10) * 25 - (q * 20), (y + 2)
				* 25 - val[0] * 2, (x + 10) * 25 - ((q + 1)
				* 20), (y + 3) * 25 - val[2] * 2);
			x++;
		}
		q++;
		y++;
	}
}

int	main(int argc, char **argv)
{
	Display		*dis;
	Window		win;
	XEvent		e;

	argc++;
	char		c;

	c = '0';
	mlx_CreateWindow(&dis, &win, 350, 750);
	while (1)
	{
		XNextEvent(dis, &e);
		if (e.type == Expose)
			BuildAllSegment(argv[1], dis, win);
		if (e.type == KeyPress)
		{
			if ((int) XLookupKeysym (&e.xkey, 0) == 65307)
				break ;
		}
	}
	XCloseDisplay(dis);
	return 0;
}
