/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 03:44:49 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:45:00 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

int		run_parser(t_parser *p, char *s, void **res)
{
	int		ret;
	t_input	i;

	*res = 0;
	i.buffer = s;
	i.cursor = s;
	i.suppress = 0;
	ret = p->match_fun(p, &i, res);
	return (ret);
}
