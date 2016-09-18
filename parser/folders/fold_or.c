/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:52:22 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/17 23:52:37 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

/*
** Returns a "or" combination from the two first parsers of the array
** or simply the first parser if it's the only one present in the array.
** Expects the array elements to point to parsers.
*/

void	*fold_or(int n, void **o)
{
	void *ret;

	(void)n;
	if (!o[1])
		ret = o[0];
	else
		ret = or_parser(2, (t_parser*[]){o[0], o[1]});
	return (ret);
}
