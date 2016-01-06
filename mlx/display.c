#include <stdio.h>
#include <stdlib.h>
#include <libft/gfx.h>
#include <libft/mlx.h>

int disp_expose(t_display *d);

#ifdef __LINUX
#include <X11/keysym.h>
#else
#include "osx_key_def.h"
#endif

int disp_handle_key(int key, t_display *d)
{
	clear_graphics(d->g);
	if (key == XK_Escape)
	{
		mlx_destroy_window(d->conn, d->win);
		exit(42);
	}
	if (key == XK_Left)
		--(*d->position)[0];
	if (key == XK_Right)
		++(*d->position)[0];
	if (key == XK_Up)
		--(*d->position)[1];
	if (key == XK_Down)
		++(*d->position)[1];
	if (key == XK_KP_Add)
		--(*d->position)[2];
	if (key == XK_KP_Subtract)
		++(*d->position)[2];
	disp_expose(d);
	return 0;
}

void draw_line(t_graphics *g, t_point a, t_point b);

t_vec4 project(t_mat4 mvp, t_vec4 n)
{
	t_vec4 ret;

	ret = mat4_m_vec4(mvp, n);
	vec4_sdiv(ret, (*ret)[3]);
	return ret;
}

t_vec4 to_screen_space(t_point dim, t_vec4 n)
{
	vec4_sadd(vec4_smul(n, 0.5f), 0.5f);
	(*n)[0] *= dim.w;
	(*n)[1] *= dim.h;
	return n;
}

int disp_expose(t_display *d)
{
	t_graphics *g;
	t_mat4 tmp;
	t_vec3 tmp3;
	t_mat4 mvp;
	g = d->g;
	//draw_line(g, (t_point){100, 250}, (t_point){208, 208});

	free(d->camera);
	tmp3 = vec3_copy(vec3_zero());
	(*tmp3)[0] = d->model->w / 2;
	(*tmp3)[1] = d->model->h / 2;
	d->camera = mat4_lookat(d->position, tmp3, vec3_up());
	free(tmp3);
	free(d->proj);
	d->proj = mat4_pers(M_PI_4, (float)d->dim.w / d->dim.h, 0.1f, 100);

	t_vertex *ptr;
	int i = 0;
	ptr = d->model->verts;
	tmp = 0;
	tmp = mat4_mult(d->camera, d->model->model);
	mvp = mat4_mult(tmp, d->proj);
	while(i < (5 * (d->model->h - 1) * (d->model->w - 1)))
	{
		t_vertex a;
		t_vertex b;
		t_vec4 pa, pb;
		t_vec4 ra, rb;

		a = ptr[d->model->elements[i++]];
		b = ptr[d->model->elements[i++]];

		pa = vec4_from_a4((float[]){a.x, a.y, a.z, 1});
		pb = vec4_from_a4((float[]){b.x, b.y, b.z, 1});
		ra = to_screen_space(d->dim, project(mvp, pa));
		rb = to_screen_space(d->dim, project(mvp, pb));
		if(0 < (*ra)[2] && (*ra)[2] < 1 && 0 < (*rb)[2] && (*rb)[2] < 1)
			draw_line(g, (t_point){(*ra)[0], (*ra)[1]}, (t_point){(*rb)[0], (*rb)[1]});
		free(ra);
		free(rb);
		free(pa);
		free(pb);
	}

	free(tmp);
	free(mvp);
	present(g);
	return 0;
}

int disp_loop(t_display *d)
{
	(void)d;

	return 0;
}

t_display *new_display(t_model *m)
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
	return ret;
}

void run_display(t_display *d)
{
	mlx_loop(d->conn);
}
