/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:54:33 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/24 15:41:37 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	f(lst);
	if (lst->next)
		ft_lstiter(lst->next, f);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *l;

	if (!lst->next)
		return (f(lst));
	l = ft_lstmap(lst->next, f);
	ft_lstadd(&l, f(lst));
	return (l);
}
