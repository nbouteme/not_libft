/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:37:31 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:58:09 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include <stdlib.h>

static void	default_dtor(void *c, size_t n)
{
	(void)n;
	free(c);
}

static void	wrapper(t_dlist *l, t_destructor del)
{
	ftext_lstdelone(l, del);
}

void		ftext_lstdel(t_dlisthead **head, t_destructor del)
{
	ftext_lstiterup(*head, (void*)wrapper, del ? del : default_dtor);
	free(*head);
	*head = 0;
}
