/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:16:57 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/24 13:38:15 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = malloc(size);
	if (mem)
		ft_memset(mem, 0, size);
	return (mem);
}

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = 0;
}
