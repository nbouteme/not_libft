/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <nbouteme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:39:17 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/09 15:51:57 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void ft_lstsplit(t_list *head, t_list **a, t_list **b)
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

static t_list *lst_merge(t_list *a, t_list *b,
						int (*cmp)(const t_list *, const t_list *))
{
	t_list *l;
	t_list **ll;

	ll = &l;
	l = 0;
	if (!b)
		return (a);
	while (a)
	{
		if (cmp(a, b) > 0)
			ft_swap_any(&a, &b, sizeof(char *));
		*ll = a;
		ll = &a->next;
		a = *ll;
	}
	*ll = b;
	return (l);
}

void ft_lstsort(t_list **head, t_lstcmp cmp)
{
	t_list *a;
	t_list *b;

	if (!*head || !(*head)->next)
		return ;
	ft_lstsplit(*head, &a, &b);
	ft_lstsort(&a, cmp);
	ft_lstsort(&b, cmp);
	*head = lst_merge(a, b, cmp);
}
