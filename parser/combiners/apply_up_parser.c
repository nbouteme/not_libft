/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_up_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:37:15 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/17 23:37:16 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int			match_apply_up(t_parser *base, t_input *i, void **out)
{
	t_apply_up_parser	*self;
	void				*tmp;
	int					ret;

	self = (void*)base;
	if ((ret = self->p->match_fun(self->p, i, out)))
	{
		tmp = *out;
		*out = self->f(tmp, self->up);
	}
	return (ret);
}

t_parser	*apply_up_parser(t_parser *i, t_apply_fun_up f, void *up)
{
	t_apply_up_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_apply_up, delete_apply);
	ret->p = i;
	ret->f = f;
	ret->up = up;
	ret->base.size = sizeof(*ret);
	return (&ret->base);
}
