/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:33:14 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 19:36:42 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include <stdlib.h>

t_dlisthead			*ftext_lstnew()
{
	t_dlisthead *head;

	head = malloc(sizeof(*head));
	head->next = (void*)head;
	head->prev = (void*)head;
	return (head);
}
