/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:54:50 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 18:26:10 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char   *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *m;

	m = ft_strnew(len + 1);
	ft_strncpy(m, s + start, len);
	return m;
}

char   *ft_strjoin(char const *s1, char const *s2)
{
	char *m;
	size_t len;

	len = ft_strlen(s1);
	m = ft_strnew(len + ft_strlen(s2) + 1);
	ft_strcpy(m, s1);
	ft_strcat(m, s2);
	return m;
}

char   *ft_strtrim(char const *s)
{
	char const *m;
	char const *n;
	char *o;

	m = s;
	n = s + ft_strlen(s) - 1;
	while(*m == ' ' || *m == '\n' | *m == '\t')
		++m;
	while(*n == ' ' || *n == '\n' | *n == '\t')
		--n;
	o = ft_strnew(n - m + 1);
	ft_strncpy(o, m, n - m);
	return o;
}

static int count_tokens(const char *str, char c)
{
	int		i;
	const char	*s;

	i = 0;
	s = str + 1;
	while (*str)
	{
		while (*s && *s != c)
			++s;
		while (*s && *s == c)
			++s;
		str = s++;
		++i;
	}
	return (i);
}

char   **ft_strsplit(char const *str, char c)
{
	const char		*s;
	char		**ret;
	int			i;
	int			j;

	ret = (char**)malloc(sizeof(char*) * (count_tokens(str, c) + 1));
	if (!ret)
		return (0);
	s = str;
	i = 0;
	while (j = 0, *str)
	{
		while (*s && *s != c)
			++s;
		ret[i] = ft_strncpy(ft_strnew(s - str), str, s - str);
		while (*s && *s == c)
			++s;
		i += !!ret[i];
		str = s++;
	}
	ret[i] = 0;
	return (ret);
}
