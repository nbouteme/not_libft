/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:24:20 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/24 13:43:41 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *a;
	const unsigned char *b;
	size_t				i;

	i = 0;
	a = s1;
	b = s2;
	while (i != n)
		if (a[i] != b[i])
			return (a[i] - b[i]);
		else
			++i;
	return (0);
}

size_t	ft_strlen(const char *s)
{
	const char *d;

	d = s;
	while (*d)
		++d;
	return (d - s);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int a;
	int b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	return (ft_memcmp(s1, s2, (a < b ? a : b) + 1));
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *a;
	const unsigned char *b;
	size_t				i;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (i < n && a[i] && b[i])
		if (a[i] != b[i])
			return (a[i] - b[i]);
		else
			++i;
	i -= i == n;
	return (a[i] - b[i]);
}
