/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:57:47 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 19:42:41 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_isdigit(int c)
{
	return '0' <= c && c <= '9';
}

static int ft_isspace(int c)
{
	const static char *sp = " \t\n\v\f\r";
	int i;

	i = 0;
	while(i < 6)
		if(c == sp[i++])
			return 1;
	return 0;
}

int     ft_atoi(const char *str)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	while(ft_isspace(*str))
		++str;
	if(*str == '+' || *str == '-')
		neg = *str++ == '-';
	while(ft_isdigit(*str))
	{
		i += *str++ - '0';
		if(!ft_isdigit(*str))
			break;
		i *= 10;
	}
	return neg ? -i : i;
}
