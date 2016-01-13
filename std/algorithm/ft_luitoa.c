/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_luitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:54:07 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 16:51:27 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char		*ft_luitoa(unsigned long n, char *base)
{
	char	*m;
	int		i;
	int		bl;

	bl = ft_strlen(base);
	m = ft_strnew(65);
	if (!m)
		return (m);
	i = 0;
	while (1)
	{
		m[i++] = base[n % bl];
		n /= bl;
		if (!n)
			break ;
	}
	return (ft_strrev(m));
}
