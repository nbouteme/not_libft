/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:07:12 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:56:26 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int			match_eof(t_parser *base, t_input *i, void **out)
{
	(void)base;
	(void)out;
	return (i->cursor >= (i->buffer + ft_strlen(i->buffer)));
}

t_parser	*eof_parser(void)
{
	t_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_eof, do_nothing);
	ret->size = sizeof(*ret);
	return (exp_p(ret, "<EOF>"));
}
