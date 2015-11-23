/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:57:59 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 18:27:48 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char *ft_strnew(size_t size)
{
	char *p;

	p = malloc(size);
	if(p)
		ft_memset(p, 0, size);
	return p;
}

void ft_strdel(char **ap)
{
	ft_memdel((void**)ap);
}

void ft_strclr(char *s)
{
	ft_memset(s, 0, ft_strlen(s));
}
