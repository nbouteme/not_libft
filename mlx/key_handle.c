/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:52:16 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 16:57:20 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __linux__
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/extensions/XShm.h>
# define KRM KeyReleaseMask
# define KR KeyRelease
# define KPM KeyPressMask
# define KP KeyPress
#else
# define KRM 2
# define KR 3
# define KPM 1
# define KP 2
#endif

#include <libft/mlx.h>

static int g_key_states[0x10000];

void		set_key_handlers(t_display *d)
{
	mlx_hook(d->win, KP, KPM, &disp_key_pressed, 0);
	mlx_hook(d->win, KR, KRM, &disp_key_released, 0);
}

int			disp_key_released(int key)
{
	g_key_states[key] = 0;
	return (0);
}

int			disp_key_pressed(int key)
{
	g_key_states[key] = 1;
	return (0);
}

int			is_key_pressed(int key)
{
	return (g_key_states[key]);
}
