/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:32:12 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:32:13 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_dlisthead	**get_plist(void)
{
	static t_dlisthead *p = 0;

	return (&p);
}

int			find_ptr(t_dlist *a, void *b)
{
	return (a->content == b);
}
