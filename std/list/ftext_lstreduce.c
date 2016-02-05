/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstreduce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:37:31 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:53:17 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

void	*ftext_lstreduce(t_dlisthead *h, void *init, t_daf f)
{
	t_dlist *first;

	first = h->next;
	while ((void*)first != (void*)h)
	{
		init = f(init, first);
		first = first->next;
	}
	return (init);
}
