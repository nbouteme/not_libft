/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:54:07 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 18:12:10 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char *ft_strrev(char *str)
{
	char *r;
	char *s;
	char tmp;

	s = str;
	r = str + ft_strlen(str) - 1;
	while(s < r)
	{
		tmp = *s;
		*s++ = *r;
		*r++ = tmp;
	}

	return str;
}

char   *ft_itoa(int n)
{
	char *m;
	int neg;
	int i;

	if((unsigned)n == 0x80000000)
		return ft_strdup("-2147483648");
	m = ft_strnew(32);
	i = 0;
	neg = n < 0;
	if(neg)
		n = -n, m[0] = '-';
	while(1)
	{
		m[i] = n % 10;
		if(!n)
			break ;
		n /= 10;
	}
	return ft_strrev(m + neg) - neg;
}
