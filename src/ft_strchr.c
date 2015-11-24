/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:27:49 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/24 14:04:54 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == c)
			return ((char *)&s[i]);
	return (0);
}

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

char	*ft_strstr(const char *s1, const char *s2)
{
	int a;
	int b;

	if (!*s2)
		return ((char*)s1);
	a = 0;
	while (s1[a])
	{
		if (s1[a] == s2[0])
		{
			b = 0;
			while (s2[b] && s1[a + b] && s1[a + b] == s2[b])
				++b;
			if (!s2[b])
				return ((char *)&s1[a]);
		}
		a++;
	}
	return (0);
}

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
