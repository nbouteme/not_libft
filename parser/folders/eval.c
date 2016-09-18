/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:51:43 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/17 23:51:43 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

/*
** Returns the nth value of the array, freeing any other
*/

void	*eval_nth_f(int x, int n, void **b)
{
	void	*ret;
	int		i;

	ret = x <= n ? b[x] : 0;
	i = 0;
	while (i < n)
		if (i != x)
			free(b[i++]);
		else
			++i;
	return (ret);
}

void	*eval_second(int n, void **b)
{
	return (eval_nth_f(1, n, b));
}

void	*eval_first(int n, void **b)
{
	return (eval_nth_f(0, n, b));
}
