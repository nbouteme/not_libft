/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:00:57 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/30 14:35:11 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *m;

	if (len > ft_strlen(s) - start)
		return (0);
	m = ft_strnew(len + 1);
	if (!m)
		return (0);
	ft_strncpy(m, s + start, len);
	return (m);
}
