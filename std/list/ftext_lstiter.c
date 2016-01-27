/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:41:54 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 19:43:50 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_EXT
#include <libft/std.h>

void	ftext_lstiter(t_listhead *head, t_iter f)
{
	t_list *first;

	first = (void *)head->next;
	while (first != head)
	{
		f(first);
		first = first->next;
	}
}
