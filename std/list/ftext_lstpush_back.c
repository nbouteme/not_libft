/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstpush_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:47:52 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 19:49:35 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_EXT
#include <libft/std.h>

void	ftext_lstpush_back(t_listhead *head, t_list *new)
{
	new->next = head;
	new->prev = head->prev;
	head->prev->next = (void*)new;
	head->prev = (void*)new;
}
