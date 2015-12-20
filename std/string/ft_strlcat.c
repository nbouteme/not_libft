/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:58:13 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 18:58:19 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dlen;
	size_t		n;

	d = s1;
	s = s2;
	n = size;
	while (n-- && *d)
		++d;
	dlen = d - s1;
	n = size - dlen;
	if (!n)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
			*d++ = *s;
		n -= n != 1;
		s++;
	}
	*d = 0;
	return (dlen + (s - s2));
}
