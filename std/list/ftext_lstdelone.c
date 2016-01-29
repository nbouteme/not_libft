/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstdelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 20:03:27 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 20:12:44 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include <stdlib.h>

void				ftext_lstdelone(t_dlist *alst, t_destructor del)
{
	alst->next->prev = alst->prev;
	alst->prev->next = alst->next;
	del(alst->content, alst->content_size);
	free(alst);
}
