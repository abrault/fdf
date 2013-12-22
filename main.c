/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:41:45 by abrault           #+#    #+#             */
/*   Updated: 2013/12/22 13:15:25 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list	*getList(char *file)
{
	int			fd;
	int			tab[2];
	char		*line;
	char		*tok;
	t_list		*list;

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

int		getVal(t_list *list, int x, int y, int *ok)
{
	while (list)
	{
		if (x == list->x && y == list->y)
			return (ft_atoi(list->val));
		list = list->next;
	}
	*ok = 0;
	return (0);
}

void	build(int val[3], int pos[2], t_data *data, int ok)
{
	int			x;
	int			y;

	x = pos[1];
	y = pos[0];
	if ((val[0] != 0 || val[1] != 0) && x > 0)
		XDrawLine(data->dis, data->win, mlx_getColor(data->dis, data->win,
		"#FFFF00"),(x + 9) * 40 - (y * 20), (y + 2)
		* 25 - val[1] * 2, (x + 10) * 40 -
		(y * 20), (y + 2) * 25 - val[0] * 2);
	else if (x > 0)
		XDrawLine(data->dis, data->win, mlx_getColor(data->dis, data->win,
		"#FEFEFE"),(x + 9) * 40 - (y * 20), (y + 2)
		* 25, (x + 10) * 40 - (y * 20), (y + 2) * 25);
	if (y > 0 && (val[0] != 0 || val[2] != 0) && ok)
		XDrawLine(data->dis, data->win, mlx_getColor(data->dis, data->win,
		"#FF0000"), (x + 10) * 40 - (y * 20), (y + 2) * 25
		- val[0] * 2, (x + 10) * 40 - ((y - 1) * 20),
		(y + 1) * 25 - val[2] * 2);
	else if (y > 0 && ok)
		XDrawLine(data->dis, data->win, mlx_getColor(data->dis, data->win,
		"#FEFEFE"), (x + 10) * 40 - (y * 20), (y + 2) * 25
		, (x + 10) * 40 - ((y - 1) * 20), (y + 1) * 25);
}

void	BuildSegment(t_data *data, t_list *list)
{
	int			pos[2];
	int			val[3];
	int			ok;
	t_list		*ptr_list;

	pos[0] = -1;
	ptr_list = list;
	while (list)
	{
		if (list->y != pos[0])
		{
			pos[1] = 0;
			pos[0]++;
		}
		val[0] = getVal(ptr_list, pos[1], pos[0], &ok);
		val[1] = getVal(ptr_list, pos[1] - 1, pos[0], &ok);
		ok = 1;
		val[2] = getVal(ptr_list, pos[1], pos[0] - 1, &ok);
		build(val, pos, data, ok);
		pos[1]++;
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	t_data		*data;
	XEvent		e;
	t_list		*list;

	argc++;
	data = malloc(sizeof(t_data));
	mlx_CreateWindow(&data->dis, &data->win, 700, 1200);
	list = getList(argv[1]);
	while (1)
	{
		XNextEvent(data->dis, &e);
		if (e.type == Expose)
			BuildSegment(data, list);
		if (e.type == KeyPress)
		{
			if ((int) XLookupKeysym(&e.xkey, 0) == 65307)
				break ;
		}
	}
	XCloseDisplay(data->dis);
	return (0);
}
