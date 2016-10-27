/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zom_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:41:33 by nbouteme          #+#    #+#             */
/*   Updated: 2016/10/27 23:59:09 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>
#include <stdio.h>

int			match_zom(t_parser *base, t_input *i, void **out)
{
	t_oom_parser	*self;
	int				m;
	void			**buf;
	void			*tmp;

	self = (void*)base;
	buf = 0;
	tmp = 0;
	m = 0;
	*out = 0;
	while (self->repeat->match_fun(self->repeat, i, &tmp))
	{
		buf = mrealloc(buf, m * 8, (m + 1) * 8);
		buf[m++] = tmp;
	}
	free(tmp);
	*out = 0;
	if (m)
		*out = self->folder(m, buf);
	free(buf);
	return (1);
}

t_parser	*zom_parser(t_folder f, t_parser *p)
{
	t_oom_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_zom, delete_oom);
	ret->folder = f;
	ret->repeat = p;
	ret->base.size = sizeof(*ret);
	return (&ret->base);
}
