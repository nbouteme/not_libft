/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:55:37 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 19:03:49 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *a;
	const unsigned char *b;
	size_t				i;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (i < n && a[i] && b[i])
		if (a[i] != b[i])
			return (a[i] - b[i]);
		else
			++i;
	i -= i == n;
	return (a[i] - b[i]);
}
