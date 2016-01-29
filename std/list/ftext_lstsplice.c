/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:20:53 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:14:00 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

void	ftext_lstsplice(t_dlist *first, t_dlist *last, t_dlist *pos)
{
	t_dlist *tmp;

	if (first == last || last == pos)
		return ;
	last->prev->next = pos;
	first->prev->next = last;
	pos->prev->next = first;
	tmp = pos->prev;
	pos->prev = last->prev;
	last->prev = first->prev;
	first->prev = tmp;
}
