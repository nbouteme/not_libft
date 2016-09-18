/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anychar_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:02:32 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:59:01 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int			match_anychar(t_parser *base, t_input *i, void **out)
{
	(void)base;
	(void)i;
	if (*i->cursor)
	{
		*out = ft_strdup(" ");
		*(char*)*out = *i->cursor++;
		return (1);
	}
	else
	{
		i->cursor++;
		*out = 0;
		return (0);
	}
}

t_parser	*anychar_parser(void)
{
	t_parser *ret;

	ret = init_parser(malloc(sizeof(*ret)), match_anychar, do_nothing);
	ret->size = sizeof(*ret);
	return (exp_p(ret, "any char"));
}

t_parser	*escape_parser(void)
{
	return (and_parser(delete_parser, strfold, 2, (t_parser*[]){
				char_parser('\\'), anychar_parser()}));
}
