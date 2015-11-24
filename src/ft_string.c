/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:27:49 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/24 14:01:08 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strdup(const char *s)
{
	size_t len;

	len = ft_strlen(s);
	return (ft_memcpy(malloc(sizeof(char) * len), s, len));
}

char	*ft_strcpy(char *dst, const char *src)
{
	ft_memccpy(dst, src, 0, ft_strlen(src));
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (i < n)
		dst[i++] = 0;
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	char *a;

	a = s1 + ft_strlen(s1);
	ft_strcpy(a, s2);
	return (s1);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *a;

	a = s1 + ft_strlen(s1);
	*(a + ft_strlen(s2)) = 0;
	ft_strncpy(a, s2, n);
	return (s1);
}
