/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:06:51 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 19:07:02 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/std.h>

char	*ft_strnew(size_t size)
{
	char *p;

	p = malloc(size);
	if (p)
		ft_memset(p, 0, size);
	return (p);
}
