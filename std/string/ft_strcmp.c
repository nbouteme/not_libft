/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:55:13 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 18:55:22 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	int a;
	int b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	return (ft_memcmp(s1, s2, (a < b ? a : b) + 1));
}
