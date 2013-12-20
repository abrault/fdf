/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:42:40 by abrault           #+#    #+#             */
/*   Updated: 2013/11/28 15:11:24 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HEAD_H
# define	HEAD_H

typedef struct s_list	t_list;

struct s_list
{
	int		y;
	int		x;
	char		*val;
	t_list		*next;
};

#endif
