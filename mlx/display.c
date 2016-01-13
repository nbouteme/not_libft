/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:17:17 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:48:38 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft/gfx.h>
#include <libft/mlx.h>

#ifdef __LINUX
# include <X11/keysym.h>
# define ESCAPE	 XK_ESCAPE
# define LEFT XK_LEFT
# define RIGHT XK_RIGHT
# define UP XK_UP
# define DOWN XK_DOWN
# define KP_ADD XK_KP_ADD
# define KP_SUBTRACT XK_KP_SUBTRACT
#else
# include "osx_key_def.h"
#endif

int			disp_expose(t_display *d)
{
	t_mat4		tmp;
	t_mat4		mvp;
	t_vec3		tmp3;

	free(d->camera);
	tmp3 = vec3_copy(vec3_zero());
	(*tmp3)[0] = d->model->w / 2;
	(*tmp3)[1] = d->model->h / 2;
	d->camera = mat4_lookat(d->position, tmp3, vec3_up());
	free(tmp3);
	free(d->proj);
	d->proj = mat4_pers(M_PI_4, (float)d->dim.w / d->dim.h, 0.1f, 100);
	tmp = mat4_mult(d->camera, d->model->model);
	mvp = mat4_mult(tmp, d->proj);
	render_line(d, mvp, d->model->verts);
	free(tmp);
	free(mvp);
	present(d->g);
	return (0);
}

int			disp_handle_key(int key, t_display *d)
{
	clear_graphics(d->g);
	if (key == ESCAPE)
	{
		mlx_destroy_window(d->conn, d->win);
		exit(42);
	}
	if (key == LEFT)
		--(*d->position)[0];
	if (key == RIGHT)
		++(*d->position)[0];
	if (key == UP)
		--(*d->position)[1];
	if (key == DOWN)
		++(*d->position)[1];
	if (key == KP_ADD)
		--(*d->position)[2];
	if (key == KP_SUBTRACT)
		++(*d->position)[2];
	disp_expose(d);
	return (0);
}

t_vec4		project(t_mat4 mvp, t_vec4 n)
{
	t_vec4 ret;

	ret = mat4_m_vec4(mvp, n);
	vec4_sdiv(ret, (*ret)[3]);
	return (ret);
}

t_vec4		to_screen_space(t_point dim, t_vec4 n)
{
	vec4_sadd(vec4_smul(n, 0.5f), 0.5f);
	(*n)[0] *= dim.w;
	(*n)[1] *= dim.h;
	return (n);
}

static void	render_line(t_display *d, t_mat4 mvp, t_vertex *ptr)
{
	t_vertex	a;
	t_vertex	b;
	t_vec4		papbrarb[4];
	int			i;

	i = 0;
	while (i < (5 * (d->model->h - 1) * (d->model->w - 1)))
	{
		a = ptr[d->model->elements[i++]];
		b = ptr[d->model->elements[i++]];
		papbrarb[0] = vec4_from_a4((float[]){a.x, a.y, a.z, 1});
		papbrarb[1] = vec4_from_a4((float[]){b.x, b.y, b.z, 1});
		papbrarb[2] = to_screen_space(d->dim, project(mvp, papbrarb[0]));
		papbrarb[3] = to_screen_space(d->dim, project(mvp, papbrarb[1]));
		if (0 < (*papbrarb[2])[2] && (*papbrarb[2])[2] < 1 &&
			0 < (*papbrarb[3])[2] && (*papbrarb[3])[2] < 1)
			draw_sline(d->g, (t_point){(*papbrarb[2])[0], (*papbrarb[2])[1]},
					(t_point){(*papbrarb[3])[0], (*papbrarb[3])[1]});
		free(papbrarb[0]);
		free(papbrarb[1]);
		free(papbrarb[2]);
		free(papbrarb[3]);
	}
}
