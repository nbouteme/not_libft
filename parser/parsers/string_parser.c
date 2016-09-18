/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:26:40 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:57:41 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int			match_string(t_parser *base, t_input *i, void **out)
{
	char			*to_cmp;
	t_string_parser	*self;

	self = (void*)base;
	to_cmp = self->to_parse;
	if (ft_strncmp(to_cmp, i->cursor, ft_strlen(to_cmp)))
		return (0);
	i->cursor += ft_strlen(to_cmp);
	*out = ft_strdup(to_cmp);
	return (1);
}

void		delete_string(t_parser *base)
{
	t_string_parser *self;

	self = (void*)base;
	free(self->to_parse);
}

t_parser	*string_parser(const char *str)
{
	t_string_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_string, delete_string);
	ret->to_parse = ft_strdup(str);
	return (exp_p(&ret->base, str));
}
