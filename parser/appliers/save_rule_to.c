/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rule_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 03:46:41 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:46:48 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	*save_rule_to(void *res, void *up)
{
	t_statement	**sts;
	t_statement	*st;
	t_symtable	*sy;
	t_parser	*p;

	sts = res;
	sy = up;
	while (*sts)
	{
		st = *sts;
		p = get_parser(sy, st->name);
		assign_parser(p, st->gr);
		free(st->name);
		free(st);
		++sts;
	}
	free(res);
	return (0);
}
