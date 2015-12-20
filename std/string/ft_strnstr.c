/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:57:34 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 18:57:49 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t a;
	size_t b;

	if (!*s2)
		return ((char*)s1);
	a = 0;
	while (s1[a] && a != n)
	{
		if (s1[a] == s2[0])
		{
			b = 0;
			while ((b + a) != n && s2[b] && s1[a + b] && s1[a + b] == s2[b])
				++b;
			if (!s2[b] || (b == n && s1[a + b] == s2[b]))
				return ((char *)&s1[a]);
		}
		a++;
	}
	return (0);
}
