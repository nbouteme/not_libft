/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:33:14 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:56:33 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>

t_dlisthead			*ftext_lstinit(t_dlisthead *this)
{
	this->next = (void*)this;
	this->prev = (void*)this;
	return (this);
}
