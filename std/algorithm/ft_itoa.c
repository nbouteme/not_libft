/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:54:07 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/30 14:34:03 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char		*ft_itoa(int n)
{
	char	*m;
	int		neg;
	int		i;

	if ((unsigned)n == 0x80000000)
		return (ft_strdup("-2147483648"));
	m = ft_strnew(32);
	if (!m)
		return (m);
	neg = n < 0;
	i = neg;
	n = neg ? -n : n;
	m[0] = neg ? '-' : 0;
	while (1)
	{
		m[i++] = n % 10 + '0';
		n /= 10;
		if (!n)
			break ;
	}
	return (ft_strrev(m + neg) - neg);
}
