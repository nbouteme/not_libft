/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:54:07 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/30 14:34:03 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char		*ft_lsitoa(long n, char *base)
{
	char	*m;
	char	*l;
	int				bl;
	int				neg;
	unsigned long	p;

	m = ft_strnew(35);
	neg = ((bl = ft_strlen(base)) == 10 && n < 0);
	m[0] = neg ? '-' : 0;
	p = ((n >= 0) ? n : ((~(unsigned long)n) + 1));
	l = ft_luitoa(p, base);
	return (ft_strcpy(m + neg, l) - neg);
}
