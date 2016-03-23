/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstnewelemown.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 20:36:30 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:53:52 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include <stdlib.h>

t_dlist	*ftext_lstnewelemown(void *content, size_t size)
{
	t_dlist *newelem;

	newelem = malloc(sizeof(*newelem));
	newelem->next = 0;
	newelem->prev = 0;
	newelem->content_size = size;
	newelem->content = content;
	return (newelem);
}
