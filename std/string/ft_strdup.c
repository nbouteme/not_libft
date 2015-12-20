/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:09:16 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 19:21:09 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/std.h>

char	*ft_strdup(const char *s)
{
	size_t len;

	len = ft_strlen(s) + 1;
	return (ft_memcpy(malloc(sizeof(char) * len), s, len));
}
