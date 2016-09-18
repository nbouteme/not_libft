/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oneof_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:23:22 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:10:51 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int			match_oneof(t_parser *base, t_input *i, void **out)
{
	t_noneof_parser *self;

	self = (void*)base;
	if (!ft_strchr(self->ign, i->cursor[0]))
		return (0);
	if (!*i->cursor)
		return (0);
	*out = ft_strdup(" ");
	*(char*)*out = *i->cursor++;
	return (1);
}

t_parser	*oneof_parser(const char *ign)
{
	t_noneof_parser	*ret;
	char			*e;

	ret = init_parser(malloc(sizeof(*ret)), match_oneof, delete_noneof);
	ret->ign = ft_strdup(ign);
	ret->base.size = sizeof(*ret);
	e = ft_memalloc(ft_strlen("Expected something in `") + ft_strlen(ign) + 2);
	ft_strcpy(e, "Expected something in `");
	ft_strcat(e, ign);
	ft_strcat(e, "`");
	ret = (void*)exp_p(&ret->base, e);
	free(e);
	return (&ret->base);
}
