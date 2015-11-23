/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:57:59 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 19:25:06 by nbouteme         ###   ########.fr       */
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

int ft_isdigit(int c)
{
	return '0' <= c && c <= '9';
}

int ft_isalnum(int c)
{
	return ft_isdigit(c) || ft_isalpha(c);
}
