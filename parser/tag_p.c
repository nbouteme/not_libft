/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:29:19 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:29:20 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_parser	*tag_p(t_parser *p, char *s)
{
	return (apply_up_parser(p, ast_set_tag, s));
}

t_parser	*atag_p(t_parser *p, char *s)
{
	return (apply_up_parser(p, ast_add_tag, s));
}
