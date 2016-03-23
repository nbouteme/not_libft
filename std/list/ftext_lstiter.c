/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:41:54 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:54:43 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

void	ftext_lstiter(t_dlisthead *head, t_diter f)
{
	t_dlist	*first;
	void	*tmp;

	first = head->next;
	while ((void*)first != (void*)head)
	{
		tmp = first->next;
		f(first);
		first = tmp;
	}
}
