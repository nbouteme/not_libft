/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <nbouteme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:39:17 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:53:03 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

static void	lst_merge(t_dlisthead *a, t_dlisthead *b, t_dlstcmp cmp)
{
	t_dlist *f1;
	t_dlist *l1;
	t_dlist *f2;
	t_dlist *l2;
	t_dlist *tmp;

	f1 = a->next;
	l1 = (void *)a;
	f2 = b->next;
	l2 = (void *)b;
	while (f1 != l1 && f2 != l2)
		if (cmp(f2, f1) < 0)
		{
			tmp = f2->next;
			ftext_lstsplice(f2, tmp, f1);
			f2 = tmp;
		}
		else
			f1 = f1->next;
	if (f2 != l2)
		ftext_lstsplice(f2, l2, l1);
}

/*
** todo: Refaire sans recursive
** todo: utiliser dtor dans objet
*/

void		ftext_lstsort(t_dlisthead *head, t_dlstcmp cmp)
{
	t_dlisthead a;
	t_dlisthead b;

	if (!head || head->next == head->prev)
		return ;
	ftext_lstsplit(head, &a, &b);
	ftext_lstsort(&a, cmp);
	ftext_lstsort(&b, cmp);
	lst_merge(&a, &b, cmp);
	ftext_lstsplice(a.next, a.next->prev, head->next);
}
