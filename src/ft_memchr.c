/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:38:52 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 15:26:59 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *m;
	size_t i;

	i = 0;
	m = (unsigned char *) s;

	while(i != n)
		if(m[i] == c)
			return &m[i];
	return 0;
}
