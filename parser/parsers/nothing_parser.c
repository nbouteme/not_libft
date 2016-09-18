/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nothing_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:21:16 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:21:58 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int			match_nothing(t_parser *base, t_input *i, void **out)
{
	(void)base;
	(void)i;
	*out = 0;
	return (1);
}

t_parser	*nothing_parser(void)
{
	t_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_nothing, do_nothing);
	ret->size = sizeof(*ret);
	return (ret);
}
