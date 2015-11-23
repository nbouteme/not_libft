/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:33:11 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 18:43:06 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void    ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void    ft_putstr_fd(char const *s, int fd)
{
	size_t len;

	len = ft_strlen(s);
	write(fd, s, len);
}

void    ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s);
	ft_putchar_fd(' ', fd);
}

void    ft_putnbr_fd(int n, int fd)
{
	char *m;

	m = ft_itoa(n);
	ft_putstr_fd(m, fd);
	ft_strdel(&m);
}
