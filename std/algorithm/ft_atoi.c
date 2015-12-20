/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:57:47 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 18:40:18 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

int			ft_atoi(const char *str)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		neg = *str++ == '-';
	while (ft_isdigit(*str))
	{
		i += *str++ - '0';
		if (!ft_isdigit(*str))
			break ;
		i *= 10;
	}
	return (neg ? -i : i);
}
