/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:37:31 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 20:36:19 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_EXT
#include <libft/std.h>

t_list	*ftext_lstnewelem(const void* content, size_t size)
{
	t_list *newelem;

	newelem = malloc(sizeof(*newelem));
	newelem->next = 0;
	newelem->prev = 0;
	newelem->size = size;
	newelem->content = ft_memcpy(malloc(size), content, size);
	return (newelem);
}
