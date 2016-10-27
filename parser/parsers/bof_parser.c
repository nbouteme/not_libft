/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bof_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:05:33 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:05:58 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int			match_bof(t_parser *base, t_input *i, void **out)
{
	(void)base;
	(void)out;
	return (i->cursor == i->buffer);
}

t_parser	*bof_parser(void)
{
	t_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_bof, do_nothing);
	ret->size = sizeof(*ret);
	return (exp_p(ret, "<BOF>"));
}
