/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_fold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:53:46 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:43:25 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	*sm_fold(int n, void **b)
{
	void **ret;

	if (!b)
		return (0);
	ret = ft_memcpy(malloc((n + 1) * sizeof(void*)), b, n * sizeof(void*));
	ret[n] = 0;
	return (ret);
}
