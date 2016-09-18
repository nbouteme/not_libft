/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:54:13 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:13:01 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

/*
** Concats a string arrays. Frees each reference in the array.
** @n: number of elements in the array
** @b: string array
*/

void	*strfold(int n, void **b)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (i < n)
	{
		len += ft_strlen(b[i] ? b[i] : "");
		++i;
	}
	ret = ft_memalloc(len + 1);
	*ret = 0;
	i = 0;
	while (i < n)
	{
		ft_strcat(ret, b[i] ? b[i] : "");
		free(b[i++]);
	}
	return (ret);
}
