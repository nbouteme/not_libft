/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:20:53 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:14:00 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

void	ftext_lstsplit(t_dlisthead *head, t_dlisthead *a, t_dlisthead *b)
{
	int		i;
	t_dlist	*l;
	t_dlist	*p;

	ftext_lstinit(a);
	ftext_lstinit(b);
	l = head->next;
	p = l;
	i = 0;
	while ((void*)l != (void*)head)
	{
		if (i % 2)
			p = p->next;
		++i;
		l = l->next;
	}
	ftext_lstsplice(head->next, p, a->next);
	ftext_lstsplice(p, l, b->next);
}
