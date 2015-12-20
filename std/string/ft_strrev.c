/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:49:35 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 18:49:52 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char	*ft_strrev(char *str)
{
	char *r;
	char *s;
	char tmp;

	s = str;
	r = str + ft_strlen(str) - 1;
	while (s < r)
	{
		tmp = *s;
		*s++ = *r;
		*r-- = tmp;
	}
	return (str);
}
