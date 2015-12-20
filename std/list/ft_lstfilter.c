/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:47:01 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 20:09:07 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

t_list	*ft_lstfilter(t_list *lst, int (*f)(t_list *elem))
{
	t_list *l;

	l = 0;
	while (lst)
	{
		if (f(lst))
			ft_lstpush(&l, lst);
		lst = lst->next;
	}
	return (l);
}
