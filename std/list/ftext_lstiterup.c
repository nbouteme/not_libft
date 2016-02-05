/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstiterup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:44:18 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:54:51 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

void	ftext_lstiterup(t_dlisthead *head, t_diterup f, void *up)
{
	t_dlist	*first;
	void	*tmp;

	first = (void *)head->next;
	while ((void *)first != (void *)head)
	{
		tmp = first->next;
		f(first, up);
		first = tmp;
	}
}
