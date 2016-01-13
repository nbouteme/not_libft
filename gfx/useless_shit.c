/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless_shit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:51:15 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 18:54:55 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/std.h>
#include <libft/mlx.h>
#include <libft/gfx.h>

void	present(t_graphics *g)
{
	mlx_put_image_to_window(g->d->conn, g->d->win, g->int_img, 0, 0);
}

void	clear_graphics(t_graphics *g)
{
	ft_memset(g->fb, 0, 4 * g->dim.w * g->dim.h);
}
