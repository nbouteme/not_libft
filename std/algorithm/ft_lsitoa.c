/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:54:07 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:14:51 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include <stdlib.h>

char		*ft_lsitoa(long n, char *base)
{
	char			*m;
	char			*l;
	int				bl;
	int				neg;
	unsigned long	p;

	m = ft_strnew(35);
	bl = ft_strlen(base);
	neg = bl == 10 && n < 0;
	m[0] = neg ? '-' : 0;
	p = ((n >= 0) ? (unsigned long)n : ((~(unsigned long)n) + 1));
	l = ft_luitoa(p, base);
	ft_strcpy(m + neg, l);
	free(l);
	return (m);
}
