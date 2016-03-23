/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:54:50 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/30 14:46:48 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/std.h>

static int	count_tokens(const char *str, char c)
{
	int			i;
	const char	*s;

	i = 0;
	s = str;
	while (*str == c)
		++str;
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

static void	*free_array(char **ret, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(ret[i]);
		++i;
	}
	return (0);
}

char		**ft_strsplit(char const *str, char c)
{
	const char	*s;
	char		**ret;
	int			i;

	ret = (char**)malloc(sizeof(char*) * (count_tokens(str, c) + 1));
	if (!ret)
		return (0);
	while (*str == c)
		++str;
	s = str;
	i = 0;
	while (*str)
	{
		while (*s && *s != c)
			++s;
		if (!(ret[i] = ft_strnew(s - str + 1)))
			return (free_array(ret, i));
		ret[i] = ft_strncpy(ret[i], str, s - str);
		while (*s && *s == c)
			++s;
		i += !!ret[i];
		str = s++;
	}
	ret[i] = 0;
	return (ret);
}
