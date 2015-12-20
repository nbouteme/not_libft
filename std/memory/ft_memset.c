/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:04:00 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 18:56:18 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

void	*ft_memset(void *b, int c, size_t size)
{
	unsigned char v;
	unsigned char *m;

	m = b;
	v = (unsigned char)c;
	while (size--)
		*m++ = v;
	return (b);
}
