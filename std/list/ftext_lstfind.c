/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstfind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:41:54 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/31 22:49:25 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

t_dlist	*ftext_lstfind(t_dlisthead *head, t_dkeepup f, void *up)
{
	t_dlist *first;

	first = head->next;
	while ((void*)first != (void*)head)
	{
		if (f(first, up))
			return (first);
		first = first->next;
	}
	return (0);
}
