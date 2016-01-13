/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:44:14 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:14:24 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

int	ft_strindexof(const char *str, char c)
{
	char *s;

	s = ft_strchr(str, c);
	if (s)
		return (s - str);
	return (-1);
}
