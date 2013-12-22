/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 13:59:13 by abrault           #+#    #+#             */
/*   Updated: 2013/12/22 13:12:31 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "head.h"

char	*ft_strtok(char *str, char sepa)
{
	static char		*stock = NULL;
	char			*ptr;
	int				i;

	i = 0;
	ptr = NULL;
	if (str != NULL)
		stock = ft_strdup(str);
	while (*stock != '\0')
	{
		if (i == 0 && *stock != sepa)
		{
			i = 1;
			ptr = stock;
		}
		else if (i == 1 && *stock == sepa)
		{
			*stock = '\0';
			stock += 1;
			break ;
		}
		stock++;
	}
	return (ptr);
}

t_list	*add_element(int y, int x, char *str, t_list *list)
{
	t_list			*new_list;

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
	t_list			*temp;
	t_list			*ret;

	temp = NULL;
	ret = NULL;
	while (list)
	{
		temp = list;
		list = temp->next;
		temp->next = ret;
		ret = temp;
	}
	return (ret);
}
