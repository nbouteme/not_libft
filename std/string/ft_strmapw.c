/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:58:54 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 19:21:19 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include <stdlib.h>

char	*ft_strmapw(char const *s, int (*f)(int))
{
	size_t	len;
	size_t	i;
	char	*m;

	len = ft_strlen(s) + 1;
	m = malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		m[i] = f(s[i]);
		++i;
	}
	return (m);
}
