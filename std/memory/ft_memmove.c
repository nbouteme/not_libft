/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:23:04 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/24 13:53:09 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dst;
	s = src;
	if (d > s && (size_t)(d - s) <= len)
		while (len--)
			d[len] = s[len];
	else
	{
		i = 0;
		while (i != len)
		{
			d[i] = s[i];
			++i;
		}
	}
	return (dst);
}
