/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:24:20 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 18:55:33 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *a;
	const unsigned char *b;
	size_t				i;

	i = 0;
	a = s1;
	b = s2;
	while (i != n)
		if (a[i] != b[i])
			return (a[i] - b[i]);
		else
			++i;
	return (0);
}
