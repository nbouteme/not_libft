/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:01:30 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/30 14:36:04 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char		*ft_strtrim(char const *s)
{
	char const	*m;
	char const	*n;
	char		*o;

	m = s;
	n = s + ft_strlen(s) - 1;
	while (n != m && (*n == ' ' || *n == '\n' || *n == '\t'))
		--n;
	while (m != n && (*m == ' ' || *m == '\n' || *m == '\t'))
		++m;
	if (n == m)
		return (ft_strdup(""));
	o = ft_strnew(n - m + 1);
	if (o)
		ft_strncpy(o, m, n - m + 1);
	return (o);
}
