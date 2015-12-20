/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:50:13 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/25 18:50:14 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

void	ft_lstiterup(t_list *lst, void (*f)(t_list *elem, void *up), void *up)
{
	f(lst, up);
	while (lst->next)
		f(lst = lst->next, up);
}
