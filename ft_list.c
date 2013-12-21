/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 13:59:13 by abrault           #+#    #+#             */
/*   Updated: 2013/12/21 14:07:49 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "head.h"

t_list  *add_element(int y, int x, char *str, t_list *list)
{
	t_list  *new_list;

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

t_list  *inverse_list(t_list *list)
{
	t_list  *temp = NULL;
	t_list  *ret = NULL;

	while (list)
	{
		temp = list;
		list = temp->next;
		temp->next = ret;
		ret = temp;
	}
	return (ret);
}
