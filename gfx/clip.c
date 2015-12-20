#include <libft/gfx.h>

enum e_rel
{
	IN    = 0x00000000,
	LEFT  = 0x00000001,
	RIGHT = 0x00000100,
	TOP   = 0x00010000,
	BOT   = 0x01000000
};

static int gen_rel(const t_graphics *g, const t_point *a)
{
	int ret;

	ret = 0;
	ret = a->w < 0 ? ret | LEFT : ret;
	ret = a->h < 0 ? ret | BOT : ret;
	ret = a->w > g->dim.w ? ret | RIGHT : ret;
	ret = a->h > g->dim.h ? ret | TOP : ret;
	return ret;
}

static void apply_clip(t_graphics *g, t_point *t[3], int rtmp)
{
	if(rtmp & TOP)
		*t[0] = (t_point){ t[1]->w + (t[2]->w - t[1]->w) * (g->dim.h - t[1]->h)
						/ (t[2]->h - t[1]->h), g->dim.h };
	else if(rtmp & BOT)
		*t[0] = (t_point){ t[1]->w + (t[2]->w - t[1]->w) * -t[1]->h
						/ (t[2]->h - t[1]->h), 0 };
	else if(rtmp & RIGHT)
		*t[0] = (t_point){ g->dim.w, t[1]->h + (t[2]->h - t[1]->h) *
						(g->dim.w - t[1]->w) / (t[2]->w - t[1]->w)};
	else if(rtmp & LEFT)
		*t[0] = (t_point){ 0, t[1]->h + (t[2]->h - t[1]->h) *
						-t[1]->w / (t[2]->w - t[1]->w)};
}

int clip(t_graphics *g, t_point *a, t_point *b)
{
	int ra;
	int rb;
	int rtmp;
	t_point *t;
	int ret;

	ra = gen_rel(g, a);
	rb = gen_rel(g, b);
	while(1)
	{
		if((ret = !(ra | rb)) || (ra & rb))
			return ret;
		t = ra ? a : b;
		rtmp = ra ? ra : rb;
		apply_clip(g, (t_point*[3]){t, a, b}, rtmp);
		if(rtmp == ra)
			ra = gen_rel(g, a);
		else
			rb = gen_rel(g, b);
	}
	return ret;
}
