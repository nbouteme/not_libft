/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:01:15 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/30 14:35:37 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*m;
	size_t	len;

	len = ft_strlen(s1);
	m = ft_strnew(len + ft_strlen(s2) + 1);
	if (!m)
		return (m);
	ft_strcpy(m, s1);
	ft_strcat(m, s2);
	return (m);
}
