/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oom_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:40:01 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:22:07 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>
#include <stdio.h>

void		delete_oom(t_parser *base)
{
	t_oom_parser *self;

	self = (void*)base;
	delete_parser(self->repeat);
	self->repeat = 0;
}

int			match_oom(t_parser *base, t_input *i, void **out)
{
	t_oom_parser	*self;
	int				m;
	void			**buf;
	void			*tmp;

	self = (void*)base;
	buf = 0;
	tmp = 0;
	m = 0;
	while (self->repeat->match_fun(self->repeat, i, &tmp))
	{
		buf = mrealloc(buf, m ? m * 8 : 0, (m + 1) * 8);
		buf[m++] = tmp;
	}
	free(tmp);
	*out = 0;
	if (m > 0)
	{
		*out = self->folder(m, buf);
		free(buf);
	}
	return (m > 0);
}

t_parser	*oom_parser(t_folder f, t_parser *to_repeat)
{
	t_oom_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_oom, delete_oom);
	ret->repeat = to_repeat;
	ret->folder = f;
	ret->base.size = sizeof(*ret);
	return (&ret->base);
}
