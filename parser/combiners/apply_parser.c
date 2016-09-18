/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:35:46 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/17 23:35:47 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int			match_apply(t_parser *base, t_input *i, void **out)
{
	t_apply_parser	*self;
	void			*tmp;
	int				ret;

	self = (void*)base;
	*out = 0;
	if ((ret = self->p->match_fun(self->p, i, out)))
	{
		tmp = *out;
		*out = self->f(tmp);
	}
	return (ret);
}

void		delete_apply(t_parser *base)
{
	t_apply_parser *self;

	self = (void*)base;
	delete_parser(self->p);
	self->p = 0;
}

t_parser	*apply_parser(t_parser *i, t_apply_fun f)
{
	t_apply_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_apply, delete_apply);
	ret->p = i;
	ret->f = f;
	ret->base.size = sizeof(*ret);
	return (&ret->base);
}
