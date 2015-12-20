/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:50:25 by nbouteme          #+#    #+#             */
/*   Updated: 2015/12/09 12:56:03 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

t_list	*ft_lstmapup(t_list *l, t_list *(*f)(t_list *elem, void *up), void *up)
{
	t_list *lst;

	if (!l->next)
		return (f(l, up));
	lst = ft_lstmapup(l->next, f, up);
	if (lst)
		ft_lstadd(&lst, f(l, up));
	return (lst);
}
