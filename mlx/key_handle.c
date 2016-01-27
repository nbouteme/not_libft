#ifdef __linux__
#include	<X11/Xlib.h>
#include	<X11/Xutil.h>
#include	<X11/extensions/XShm.h>
#endif

#include <libft/mlx.h>

static int g_key_states[0x10000];

void set_key_handlers(t_display *d) __attribute__ ((optnone))
{
	mlx_hook(d->win, KeyPress, KeyPressMask, &disp_key_pressed, 0);
	mlx_hook(d->win, KeyRelease, KeyReleaseMask, &disp_key_released, 0);
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

int is_key_pressed(int key)
{
	return (g_key_states[key]);
}
