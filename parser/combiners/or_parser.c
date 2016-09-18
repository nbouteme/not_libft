/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:40:48 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:31:01 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int			match_or(t_parser *base, t_input *i, void **out)
{
	t_or_parser	*self;
	int			idx;
	void		*tmp;

	self = (void*)base;
	idx = 0;
	tmp = i->cursor;
	*out = 0;
	while (idx < self->n_or)
	{
		free(*out);
		*out = 0;
		if (self->to_or[idx]->match_fun(self->to_or[idx], i, out))
			return (1);
		++idx;
	}
	i->cursor = tmp;
	return (0);
}

void		delete_or(t_parser *p)
{
	t_or_parser	*self;
	int			i;

	self = (void*)p;
	i = 0;
	while (i < self->n_or)
	{
		delete_parser(self->to_or[i]);
		self->to_or[i] = 0;
		++i;
	}
	free(self->to_or);
}

t_parser	*or_parser(int n, t_parser *parser[])
{
	t_or_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_or, delete_or);
	ret->to_or = malloc(n * sizeof(void*));
	ret->to_or = ft_memcpy(ret->to_or, parser, n * sizeof(void*));
	ret->n_or = n;
	ret->base.size = sizeof(*ret);
	return (&ret->base);
}
