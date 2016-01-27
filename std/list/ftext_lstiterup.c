/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstiterup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:44:18 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 19:44:30 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_EXT
#include <libft/std.h>

void	ftext_lstiterup(t_listhead *head, t_iter f, void *up)
{
	t_list *first;

	first = (void *)head->next;
	while (first != head)
	{
		f(first, up);
		first = first->next;
	}
}
