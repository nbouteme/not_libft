/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:02:38 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:04:10 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_parser	*tok_between_parser(t_parser *p, const char *l, const char *r)
{
	return (and_parser(delete_parser, eval_second, 3, (t_parser*[]) {
			string_parser(l), tok_parser(p), string_parser(r)
		}));
}

t_parser	*between_parser(t_parser *p, const char *l, const char *r)
{
	return (and_parser(delete_parser, eval_second, 3, (t_parser*[]) {
						string_parser(l), p, string_parser(r)
					}));
}

t_parser	*paren_parser(t_parser *p)
{
	return (between_parser(p, "(", ")"));
}
