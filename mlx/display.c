/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:17:17 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 16:50:56 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft/gfx.h>
#include <libft/mlx.h>
#include "key_defs.h"

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
	while (i < (2 * (2 * (d->model->h) * (d->model->w)
					- d->model->w - d->model->h)))
	{
		a = ptr[d->model->elements[i++]];
		b = ptr[d->model->elements[i++]];
		papbrarb[0] = &(float[]){a.x, a.y, a.z, 1};
		papbrarb[1] = &(float[]){b.x, b.y, b.z, 1};
		papbrarb[2] = to_screen_space(d->dim, project(mvp, papbrarb[0]));
		papbrarb[3] = to_screen_space(d->dim, project(mvp, papbrarb[1]));
		if (0 < (*papbrarb[2])[2] && (*papbrarb[2])[2] < 1 &&
			0 < (*papbrarb[3])[2] && (*papbrarb[3])[2] < 1)
			draw_line(d->g, (t_point){(*papbrarb[2])[0], (*papbrarb[2])[1]},
					(t_point){(*papbrarb[3])[0], (*papbrarb[3])[1]});
		free(papbrarb[2]);
		free(papbrarb[3]);
	}
}

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
	d->proj = mat4_pers(M_PI_4, (float)d->dim.w / d->dim.h, 0.1f, 1000);
	tmp = mat4_mult(d->camera, d->model->model);
	mvp = mat4_mult(tmp, d->proj);
	render_line(d, mvp, d->model->verts);
	free(tmp);
	free(mvp);
	present(d->g);
	mlx_do_sync(d->conn);
	return (0);
}

int			disp_handle_key(t_display *d)
{
	if (is_key_pressed(ESCAPE))
	{
		mlx_destroy_window(d->conn, d->win);
		exit(42);
	}
	if (is_key_pressed(LEFT))
		--(*d->position)[0];
	if (is_key_pressed(RIGHT))
		++(*d->position)[0];
	if (is_key_pressed(UP))
		--(*d->position)[1];
	if (is_key_pressed(DOWN))
		++(*d->position)[1];
	if (is_key_pressed(KP_ADD))
		--(*d->position)[2];
	if (is_key_pressed(KP_SUBTRACT))
		++(*d->position)[2];
	clear_graphics(d->g);
	disp_expose(d);
	return (0);
}
