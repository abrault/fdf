/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:42:40 by abrault           #+#    #+#             */
/*   Updated: 2013/12/22 13:13:11 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HEAD_H
# define	HEAD_H

#include "libft/libft.h"

typedef struct s_list	t_list;
typedef struct s_data	t_data;

struct					s_data
{
	Display				*dis;
	Window				win;
};

struct					s_list
{
	int					y;
	int					x;
	char				*val;
	t_list				*next;
};

t_list					*add_element(int y, int x, char *str, t_list *list);
t_list					*inverse_list(t_list *list);
char					*ft_strtok(char *str, char sepa);

#endif
