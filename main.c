/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:41:45 by abrault           #+#    #+#             */
/*   Updated: 2013/12/21 17:53:06 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "head.h"
#include "libft.h"

t_list	*getList(char *file)
{
	int		fd;
	char	*line;
	t_list	*list;
	char	*tok;
	int		tab[2];

	list = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tab[1] = 0;
		tok = ft_strtok(line, ' ');
		while (tok)
		{
			list = add_element(tab[0], tab[1], tok, list);
			tok = ft_strtok(NULL, ' ');
			tab[1]++;
		}
		tab[0]++;
	}
	return (inverse_list(list));
}

int		getVal(t_list *list, int x, int y)
{
	while (list)
	{
		if (x == list->x && y == list->y)
			return (ft_atoi(list->val));
		list = list->next;
	}
	return (0);
}

void	build(int val[3], int pos[2], Display *dis, Window win)
{
	int		x;
	int		y;

	x = pos[1];
	y = pos[0];
	if ((val[0] != 0 || val[1] != 0) && x > 0)
		XDrawLine(dis, win, mlx_getColor(dis, win,
		"#FFFF00"),(x + 9) * 40 - (y * 20), (y + 2)
		* 25 - val[1] * 2, (x + 10) * 40 -
		(y * 20), (y + 2) * 25 - val[0] * 2);
	else if (x > 0)
		XDrawLine(dis, win, mlx_getColor(dis, win,
		"#FEFEFE"),(x + 9) * 40 - (y * 20), (y + 2)
		* 25, (x + 10) * 40 - (y * 20), (y + 2) * 25);
	if (y > 0 && (val[0] != 0 || val[2] != 0))
		XDrawLine(dis, win, mlx_getColor(dis, win,
		"#FF0000"), (x + 10) * 40 - (y * 20), (y + 2) * 25
		- val[0] * 2, (x + 10) * 40 - ((y - 1) * 20),
		(y + 1) * 25 - val[2] * 2);
	else if (y > 0)
		XDrawLine(dis, win, mlx_getColor(dis, win,
		"#FEFEFE"), (x + 10) * 40 - (y * 20), (y + 2) * 25
		, (x + 10) * 40 - ((y - 1) * 20), (y + 1) * 25);
}

void	BuildSegment(Display *dis, Window win, t_list *list)
{
	int		pos[2];
	int		val[3];
	t_list	*ptr_list;

	pos[0] = -1;
	ptr_list = list;
	while (list)
	{
		if (list->y != pos[0])
		{
			pos[1] = 0;
			pos[0]++;
		}
		val[0] = getVal(ptr_list, pos[1], pos[0]);
		val[1] = getVal(ptr_list, pos[1] - 1, pos[0]);
		val[2] = getVal(ptr_list, pos[1], pos[0] - 1);
		build(val, pos, dis, win);
		pos[1]++;
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	Display	*dis;
	Window	win;
	XEvent	e;
	t_list	*list;

	argc++;
	mlx_CreateWindow(&dis, &win, 700, 1200);
	list = getList(argv[1]);
	while (1)
	{
		XNextEvent(dis, &e);
		if (e.type == Expose)
			BuildSegment(dis, win, list);
		if (e.type == KeyPress)
		{
			if ((int) XLookupKeysym(&e.xkey, 0) == 65307)
				break ;
		}
	}
	XCloseDisplay(dis);
	return (0);
}
