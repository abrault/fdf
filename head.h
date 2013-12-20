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

# include <stdlib.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/Xos.h>
# include <X11/Xatom.h>
# include <X11/keysym.h>

typedef struct s_list	t_list;

struct s_list
{
	int		y;
	int		x;
	char		*val;
	t_list		*next;
};

#endif
