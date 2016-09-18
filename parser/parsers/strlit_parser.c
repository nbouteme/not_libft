/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlit_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:28:22 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:28:23 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_parser	*strlit_parser(void)
{
	t_parser *strchar;

	strchar = or_parser(2, (t_parser*[]){escape_parser(), noneof_parser("\"")});
	return (between_parser(oom_parser(strfold, strchar), "\"", "\""));
}

t_parser	*charlit_parser(void)
{
	return (between_parser(or_parser(2, (t_parser*[]){escape_parser(),
					anychar_parser()}), "'", "'"));
}

t_parser	*reglit_parser(void)
{
	t_parser *regexchar;

	regexchar = or_parser(2, (t_parser*[]){escape_parser(),
				noneof_parser("/")});
	return (between_parser(oom_parser(strfold, regexchar), "/", "/"));
}
