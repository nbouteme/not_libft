/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:43:20 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/30 14:44:33 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstnewown(void *content, size_t content_size)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->content = content;
	list->content_size = content ? content_size : 0;
	list->next = 0;
	return (list);
}
