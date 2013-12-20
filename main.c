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
#include "head.h"
#include "libft.h"

t_list	*add_element(int y, int x, char *str, t_list *list)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	new_list->y = y;
	new_list->x = x;
	new_list->val = str;
	if (!list)
		new_list->next = NULL;
	else
		new_list->next = list;
	return (new_list);
}

t_list	*inverse_list(t_list *list)
{
	t_list	*temp = NULL;
	t_list	*ret = NULL;

	while (list)
	{
		temp = list;
		list = temp->next;
		temp->next = ret;
		ret = temp;
	}
	return (ret);
}

t_list	*getList(char *file)
{
	int	fd;
	char	*line;
	t_list	*list;
	char	*tok;
	int	tab[2];

	list = NULL;
	tab[1] = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tab[1] = 0;
		tok = strtok(line, " ");
		while (tok)
		{
			list = add_element(tab[0], tab[1], tok, list);
			tok = strtok(NULL, " ");
			tab[1]++;
		}
		tab[0]++;
		list = list->next;
	}
	return (inverse_list(list));
}

int	getVal(t_list *list, int x, int y)
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
	int	x;
	int	y;

	x = pos[1];
	y = pos[0];
	if ((val[0] != 0 || val[1] != 0) && x > 0)
		XDrawLine(dis, win, mlx_getColor(dis, win,
		"#ffff00"),(x + 9) * 40 - (y * 20), (y + 2)
		* 25 - val[1] * 3, (x + 10) * 40 -
		(y * 20), (y + 2) * 25 - val[0] * 3);
	else if (x > 0)
		XDrawLine(dis, win, mlx_getColor(dis, win,
		"#fefefe"),(x + 9) * 40 - (y * 20), (y + 2)
		* 25, (x + 10) * 40 - (y * 20), (y + 2) * 25);
	if (y > 0 && (val[0] != 0 || val[2] != 0))
		XDrawLine(dis, win, mlx_getColor(dis, win,
		"#ff0000"), (x + 10) * 40 - (y * 20), (y + 2) * 25
		- val[0] * 3, (x + 10) * 40 - ((y - 1) * 20),
		(y + 1) * 25 - val[2] * 3);
	else if (y > 0)
		XDrawLine(dis, win, mlx_getColor(dis, win,
		"#fefefe"), (x + 10) * 40 - (y * 20), (y + 2) * 25
		, (x + 10) * 40 - ((y - 1) * 20), (y + 1) * 25);
}

void	BuildSegment(Display *dis, Window win, t_list *list)
{
	int	pos[2];
	int	val[3];
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

int	main(int argc, char **argv)
{
	Display	*dis;
	Window	win;
	XEvent	e;
	t_list	*list;

	argc++;
	mlx_CreateWindow(&dis, &win, 700, 800);
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
