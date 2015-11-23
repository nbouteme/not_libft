/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:48:25 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 13:56:29 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int     ft_isalpha(int c)
{
	return ft_islower(c) || ft_isupper(c);
}

int     ft_isascii(int c)
{
	return c <= '~';
}

int     ft_isprint(int c)
{
	return ft_isascii(c) && c >= ' ';
}

int     ft_isupper(int c)
{
	return c >= 'A' && c <= 'Z';
}

int     ft_islower(int c)
{
	return c >= 'a' && c <= 'z';
}
