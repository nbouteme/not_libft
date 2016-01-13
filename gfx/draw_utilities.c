/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:50:36 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 18:54:36 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/std.h>
#include <libft/mlx.h>
#include <libft/gfx.h>

int			is_outside(t_graphics *g, t_point a)
{
	if (a.w < 0 || g->dim.w <= a.w)
		return (1);
	if (a.h < 0 || g->dim.h <= a.h)
		return (2);
	return (0);
}

unsigned	get_pixel(t_graphics *g, t_point pos)
{
	if (is_outside(g, pos))
		return (0);
	return (g->fb[pos.h * g->dim.w + pos.w]);
}

void		draw_point_bare(t_graphics *g, t_point pos)
{
	g->fb[pos.h * g->dim.w + pos.w] = g->color;
}

void		draw_point(t_graphics *g, t_point pos)
{
	if (is_outside(g, pos))
		return ;
	draw_point_bare(g, pos);
}

void		draw_line(t_graphics *g, t_point a, t_point b)
{
	if (clip(g, &a, &b))
		draw_line_bare(g, a, b);
}
