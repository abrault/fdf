/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:42:40 by abrault           #+#    #+#             */
/*   Updated: 2013/12/21 14:07:36 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HEAD_H
# define	HEAD_H

typedef struct s_list	t_list;

struct s_list
{
	int					y;
	int					x;
	char				*val;
	t_list				*next;
};

t_list					*add_element(int y, int x, char *str, t_list *list);
t_list					*inverse_list(t_list *list);

#endif
