/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:10:36 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 19:10:43 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *a;

	a = s1 + ft_strlen(s1);
	*(a + ft_strlen(s2)) = 0;
	ft_strncpy(a, s2, n);
	return (s1);
}
