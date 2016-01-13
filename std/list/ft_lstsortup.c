/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <nbouteme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:39:17 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:13:37 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

static t_list	*lst_merge(t_list *a, t_list *b, t_lstcmpup cmp, void *up)
{
	t_list *l;
	t_list **ll;

	ll = &l;
	l = 0;
	if (!b)
		return (a);
	while (a)
	{
		if (cmp(a, b, up) > 0)
			ft_swap_any(&a, &b, sizeof(char *));
		*ll = a;
		ll = &a->next;
		a = *ll;
	}
	*ll = b;
	return (l);
}

void			ft_lstsortup(t_list **head, t_lstcmpup cmp, void *up)
{
	t_list *a;
	t_list *b;

	if (!*head || !(*head)->next)
		return ;
	ft_lstsplit(*head, &a, &b);
	ft_lstsortup(&a, cmp, up);
	ft_lstsortup(&b, cmp, up);
	*head = lst_merge(a, b, cmp, up);
}
