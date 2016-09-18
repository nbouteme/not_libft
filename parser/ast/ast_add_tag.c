/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_add_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:29:29 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:53:20 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	*ast_add_tag(void *s, void *t)
{
	t_ast	*ret;
	char	*str;

	ret = s;
	str = ft_memalloc(ft_strlen(ret->tag) + 1 + ft_strlen(t) + 1);
	ft_strcat(str, ret->tag);
	ft_strcat(str, "|");
	ft_strcat(str, t);
	free(ret->tag);
	ret->tag = str;
	return (ret);
}
