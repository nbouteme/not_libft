/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_escape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:32:56 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:55:53 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

static int	find_in(const char *n, const char **h)
{
	int i;

	i = 0;
	while (h[i])
	{
		if (ft_strncmp(n, h[i], ft_strlen(h[i])) == 0)
			return (i);
		++i;
	}
	return (-1);
}

char		*str_escape(char *s, const char *in[], const char *out[])
{
	char	*outp;
	char	*f;
	char	*tmp;
	int		ol;
	int		i;

	outp = ft_memalloc(ft_strlen(s));
	ol = 0;
	f = outp;
	while (*s)
	{
		if ((i = find_in(s, in)) != -1)
		{
			tmp = outp;
			outp = ft_memalloc(strlen(tmp) + ft_strlen(out[i]) + 1);
			ft_strcat(outp, tmp);
			ft_strcat(outp, out[i]);
			ol += ft_strlen(out[i]);
			s += ft_strlen(in[i]);
			f = outp;
		}
		else
			f[ol++] = *s++;
	}
	return (outp);
}
