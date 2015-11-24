/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:33:11 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/24 13:28:19 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

void	ft_putstr(char const *s)
{
	ft_putstr_fd(s, 1);
}

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
