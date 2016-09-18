/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_add_root_tag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:29:07 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:24:31 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_ast	*ast_add_root_tag(t_ast *a, const char *t)
{
	if (a)
	{
		a->tag = mrealloc(a->tag, ft_strlen(a->tag), ft_strlen(t)
						+ ft_strlen(a->tag) + 1);
		ft_memmove(a->tag + ft_strlen(t), a->tag, ft_strlen(a->tag) + 1);
		ft_memmove(a->tag, t, ft_strlen(t));
	}
	return (a);
}
