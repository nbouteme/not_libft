/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:37:31 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:53:42 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include <stdlib.h>

t_dlist	*ftext_lstnewelem(const void *content, size_t size)
{
	t_dlist *newelem;

	newelem = malloc(sizeof(*newelem));
	newelem->next = 0;
	newelem->prev = 0;
	newelem->content_size = size;
	newelem->content = ft_memcpy(malloc(size), content, size);
	return (newelem);
}
