/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstpush_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:50:24 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 19:51:27 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_EXT
#include <libft/std.h>

void	ftext_lstpush_front(t_listhead *head, t_list *new)
{
	new->prev = head;
	new->next = head->next;
	head->next->prev = (void*)new;
	head->next = (void*)new;
}
