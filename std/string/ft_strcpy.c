/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:09:37 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 19:09:43 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

char	*ft_strcpy(char *dst, const char *src)
{
	ft_memccpy(dst, src, 0, ft_strlen(src));
	return (dst);
}
