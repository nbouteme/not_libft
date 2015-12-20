/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:02:28 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 20:09:32 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

static void	ft_lst_pushback(t_list *l, t_list *to_add)
{
	if (l->next)
		return (ft_lst_pushback(l->next, to_add));
	l->next = ft_lstnew(to_add->content, to_add->content_size);
}

void		ft_lstpush(t_list **lst, t_list *to_add)
{
	if (*lst)
		return (ft_lst_pushback(*lst, to_add));
	*lst = ft_lstnew(to_add->content, to_add->content_size);
}
