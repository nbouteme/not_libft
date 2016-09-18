/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cident_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:06:40 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:07:09 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_parser	*cident_parser(void)
{
	t_parser *a;
	t_parser *b;

	a = or_parser(2, (t_parser*[]){alpha_parser(), char_parser('_')});
	b = zom_parser(strfold, or_parser(2, (t_parser*[]){alnum_parser(),
					char_parser('_')}));
	b = and_parser(delete_parser, strfold, 2, (t_parser*[]){a, b});
	return (exp_p(b, "C-like identifier"));
}
