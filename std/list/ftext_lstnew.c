/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:33:14 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:56:33 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include <stdlib.h>

t_dlisthead			*ftext_lstnew(void)
{
	t_dlisthead *head;

	head = malloc(sizeof(*head));
	head->next = (void*)head;
	head->prev = (void*)head;
	return (head);
}
