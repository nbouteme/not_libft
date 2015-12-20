/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:59:18 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 18:59:36 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/std.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*m;

	len = ft_strlen(s);
	m = malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		m[i] = f(i, s[i]);
		++i;
	}
	return (m);
}
