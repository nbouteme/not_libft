/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:37:31 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 20:03:38 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_EXT
#include <libft/std.h>

static void wrapper(t_list *l, t_destructor del)
{
	ftext_lstdelone(&l, del);
}

void ftext_lstdel(t_listhead **head, t_destructor del)
{
	ftext_lstiterup(*head, wrapper, del);
	free(*head);
	*head = 0;
}
