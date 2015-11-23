/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:13:19 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 19:50:31 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	const unsigned char *s;
	size_t i;

	d = dst;
	s = src;
	i = 0;

	while(i != n)
		d[i] = s[i], ++i;

	return d;
}

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	const unsigned char *s;
	unsigned char v;
	size_t i;

	d = dst;
	s = src;
	v = (unsigned char) c;
	i = 0;

	while(i != n)
		if(s[i] == v)
			return d[i] = s[i], &d[++i];
		else
			d[i] = s[i], ++i;

	return 0;
}
