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

#define LIBFT_EXT
#include <libft/std.h>

t_listhead			*ftext_lstnew()
{
	t_listhead *head;

	head = malloc(sizeof(*head));
	head->next = head;
	head->prev = head;
	return (head);
}
