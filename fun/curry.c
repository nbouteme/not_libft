/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 05:20:36 by nbouteme          #+#    #+#             */
/*   Updated: 2016/10/30 05:20:46 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include <libft/curry.h>
#include "funalloc.h"

t_value	curry(void *f, t_value arg)
{
	char *sp;

	sp = funalloc();
	ex_set(false);
	ft_memcpy(sp,
			"\x41\x51"
			"\x4d\x89\xc1"
			"\x49\x89\xc8"
			"\x48\x89\xd1"
			"\x48\x89\xf2"
			"\x48\x89\xfe"
			"\x48\x8b\x3d\x0F\x00\x00\x00"
			"\x4c\x8b\x15\x10\x00\x00\x00"
			"\x41\xff\xd2"
			"\x48\x83\xc4\x08"
			"\xc3",
			39);
	ft_memcpy(sp + 39, &arg, sizeof(arg));
	ft_memcpy(sp + 47, &f, sizeof(f));
	ex_set(true);
	return ((t_value){sp});
}
