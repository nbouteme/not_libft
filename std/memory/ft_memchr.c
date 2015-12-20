/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:38:52 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/24 13:39:27 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*m;
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	m = (unsigned char *)s;
	while (i < n)
		if (m[i] == (unsigned char)c)
			return (&m[i]);
		else
			++i;
	return (0);
}
