/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:33:11 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/30 14:33:26 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft/std.h>

void	ft_putnbr_fd(int n, int fd)
{
	char *m;

	m = ft_itoa(n);
	if (!m)
		return ;
	ft_putstr_fd(m, fd);
	ft_strdel(&m);
}
