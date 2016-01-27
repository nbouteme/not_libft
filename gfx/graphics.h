/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:55:38 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 18:56:30 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

typedef struct s_display	t_display;
typedef struct s_point	t_point;

typedef struct	s_graphics
{
	void		*int_img;
	int			*fb;
	t_display	*d;
	t_point		dim;
	unsigned	color;
}				t_graphics;

t_graphics		*new_graphics(t_display *d);
int				is_outside(t_graphics *g, t_point a);
unsigned		get_pixel(t_graphics *g, t_point pos);
void			draw_point_bare(t_graphics *g, t_point pos);
void			draw_point(t_graphics *g, t_point pos);
void			present(t_graphics *g);
void			draw_nline(t_graphics *g, t_vec4 n1, t_vec4 n2);
void			clear_graphics(t_graphics *g);
void			draw_line_bare(t_graphics *g, t_point a, t_point b);

#endif
