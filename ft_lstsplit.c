/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:20:53 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/09 15:55:25 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void ft_lstsplit(t_list *head, t_list **a, t_list **b)
{
	int i;
	t_list *l;
	t_list *p;

	i = 0;
	*a = head;
	l = *a;
	*b = l;
	p = l;
	while (l)
	{
		if (i % 2)
		{
			p = *b;
			*b = (*b)->next;
		}
		l = l->next;
		++i;
	}
	p->next = 0;
}
