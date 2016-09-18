/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 03:19:09 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:23:52 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	*mrealloc(void *b, int os, int ns)
{
	void *ret;

	ret = ft_memalloc(ns);
	ft_memcpy(ret, b, os);
	free(b);
	return (ret);
}
