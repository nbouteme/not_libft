/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_set_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:31:50 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:58:35 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	*ast_set_tag(void *s, void *t)
{
	t_ast *ret;

	ret = s;
	free(ret->tag);
	ret->tag = ft_strdup(t);
	return (ret);
}
