/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_char_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 03:45:34 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:45:42 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	*gen_char_parser(void *i)
{
	char		*s;
	t_parser	*ret;

	s = i;
	if (s[0] == '.')
		ret = anychar_parser();
	else if (s[0] == '^')
		ret = bof_parser();
	else if (s[0] == '$')
		ret = eof_parser();
	else
		ret = char_parser(s[0]);
	free(i);
	return (ret);
}
