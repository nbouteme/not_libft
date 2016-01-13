/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless_as_heck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:28:59 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:41:06 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft/gfx.h>
#include <libft/mlx.h>

void		run_display(t_display *d)
{
	mlx_loop(d->conn);
}

int			disp_loop(t_display *d)
{
	(void)d;
	return (0);
}

t_display	*new_display(t_model *m)
{
	t_display *ret;

	ret = malloc(sizeof(*ret));
	ret->conn = mlx_init();
	ret->dim.w = 420;
	ret->dim.h = 420;
	ret->win = mlx_new_window(ret->conn, ret->dim.w, ret->dim.h, "FdF");
	ret->g = new_graphics(ret);
	ret->model = m;
	ret->position = ft_memalloc(sizeof(*ret->position));
	ret->camera = 0;
	ret->proj = 0;
	(*ret->position)[0] = 5.75;
	(*ret->position)[1] = 5.75;
	(*ret->position)[2] = 25.75;
	mlx_key_hook(ret->win, &disp_handle_key, ret);
	mlx_expose_hook(ret->win, &disp_expose, ret);
	mlx_loop_hook(ret->conn, &disp_expose, ret);
	return (ret);
}
