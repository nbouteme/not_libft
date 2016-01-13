/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_any.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <nbouteme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:52:33 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:12:07 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/std.h>

void	ft_swap_any(void *a, void *b, size_t size)
{
	unsigned char t[size];

	ft_memcpy(t, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, t, size);
}
