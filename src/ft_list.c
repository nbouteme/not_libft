/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:40:37 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/24 15:40:47 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->content = content ? malloc(content_size) : 0;
	content ? ft_memcpy(list->content, content, content_size) : 0;
	list->content_size = content ? content_size : 0;
	list->next = 0;
	return (list);
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del(*alst, (*alst)->content_size);
	free(*alst);
	*alst = 0;
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
