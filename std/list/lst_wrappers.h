/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:37:31 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:52:00 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_WRAPPERS_H
# define LST_WRAPPERS_H

# include <libft/std.h>

typedef struct		s_map_wrapper
{
	t_dgen			f;
	t_dlisthead		*h;
}					t_map_wrapper;

typedef struct		s_mapup_wrapper
{
	t_dgenup		f;
	t_dlisthead		*h;
	void			*up;
}					t_mapup_wrapper;

typedef struct		s_reduce_wrapper
{
	t_dkeep			f;
	t_dlisthead		*h;
	t_dcopy			c;
}					t_reduce_wrapper;

typedef struct		s_reduceup_wrapper
{
	t_dkeepup		f;
	t_dlisthead		*h;
	t_dcopy			c;
	void			*u;
}					t_reduceup_wrapper;

#endif
