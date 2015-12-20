#include <stdlib.h>
#include <libft/std.h>
#include <libft/mlx.h>
#include <libft/gfx.h>

void draw_line_bare(t_graphics *g, t_point a, t_point b);

t_graphics *new_graphics(t_display *d)
{
	int osef;
	t_graphics *g;

	g = malloc(sizeof(t_graphics));
	g->d = d;
	g->int_img = mlx_new_image(d->conn, d->dim.w, d->dim.h);
	g->fb = (int*) mlx_get_data_addr(g->int_img, &osef, &osef, &osef);
	g->dim.w = d->dim.w;
	g->dim.h = d->dim.h;
	g->color = 0x00FFFFFF;
	return g;
}

int is_outside(t_graphics *g, t_point a)
{
	if(a.w < 0 || g->dim.w <= a.w)
		return 1;
	if(a.h < 0|| g->dim.h <= a.h)
		return 2;
	return 0;
}

unsigned get_pixel(t_graphics *g, t_point pos)
{
	if(is_outside(g, pos))
		return 0;
	return g->fb[pos.h * g->dim.w + pos.w];
}

void draw_point_bare(t_graphics *g, t_point pos)
{
	g->fb[pos.h * g->dim.w + pos.w] = g->color;	
}

void draw_point(t_graphics *g, t_point pos)
{
	if(is_outside(g, pos))
		return ;
	draw_point_bare(g, pos);
}

void draw_line(t_graphics *g, t_point a, t_point b)
{
	if(clip(g, &a, &b))
		draw_line_bare(g, a, b);		
}

void draw_line_bare(t_graphics *g, t_point a, t_point b)
{
	int oh_boy[7];

	oh_boy[0] = abs(b.w - a.w);
	oh_boy[1] = abs(b.h - a.h);
	oh_boy[2] = sign(b.w - a.w);
	oh_boy[3] = sign(b.h - a.h);
	if ((oh_boy[4] = oh_boy[1] > oh_boy[0]))
		ft_swap_any(&oh_boy[0], &oh_boy[1], sizeof(int));
	oh_boy[5] = 2 * oh_boy[1] - oh_boy[0];
	oh_boy[6] = -1;
	while (++oh_boy[6] < oh_boy[0])
	{
		draw_point(g, a);
		while (oh_boy[5] >= 0)
		{
			oh_boy[5] = oh_boy[5] - 2 * oh_boy[0];
			oh_boy[4] ? (a.w += oh_boy[2]) : (a.h += oh_boy[3]);
		}
		oh_boy[5] = oh_boy[5] + 2*oh_boy[1];
		oh_boy[4] ? (a.h += oh_boy[3]) : (a.w += oh_boy[2]);
	}
}

t_point ndc_to_screen(t_graphics *g, t_point ndc)
{
	int ppn, xoff, yoff;
	if(g->dim.w >= g->dim.h )
	{
		ppn = g->dim.h;
		xoff = (g->dim.w - g->dim.h) >> 1;
		yoff = 0;
	}
	else
	{
		ppn = g->dim.w;
		xoff = 0;
		yoff = (g->dim.h - g->dim.w) >> 1;
	}
	return (t_point){ndc.w * ppn + xoff, g->dim.w - (ndc.h * ppn) + yoff};
}

void draw_nline(t_graphics *g, t_vec4 n1, t_vec4 n2)
{
	t_point a;
	t_point b;

	a = ndc_to_screen(g, (t_point){(*n1)[0], (*n1)[1]});
	b = ndc_to_screen(g, (t_point){(*n2)[0], (*n2)[1]});
	draw_line(g, a, b);
}

void present(t_graphics *g)
{
	mlx_put_image_to_window(g->d->conn, g->d->win, g->int_img, 0, 0);
}

void clear_graphics(t_graphics *g)
{
	ft_memset(g->fb, 0, 4 * g->dim.w * g->dim.h);
}

