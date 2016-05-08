/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:54:50 by nbouteme          #+#    #+#             */
/*   Updated: 2016/03/27 03:06:08 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/std.h>

static int	count_tokens(const char *str, int (*f)(int))
{
	int			i;
	const char	*s;

	i = 0;
	s = str;
	while (f(*str))
		++str;
	s = str + 1;
	while (*str)
	{
		while (*s && !f(*s))
			++s;
		while (*s && f(*s))
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

char		**ft_strsplitv(char const *str, int (*f)(int))
{
	const char	*s;
	char		**ret;
	int			i;

	ret = (char**)malloc(sizeof(char*) * (count_tokens(str, f) + 1));
	if (!ret)
		return (0);
	while (f(*str))
		++str;
	s = str;
	i = 0;
	while (*str)
	{
		while (*s && !f(*s))
			++s;
		if (!(ret[i] = ft_strnew(s - str + 1)))
			return (free_array(ret, i));
		ret[i] = ft_strncpy(ret[i], str, s - str);
		while (*s && f(*s))
			++s;
		i += !!ret[i];
		str = s++;
	}
	ret[i] = 0;
	return (ret);
}
