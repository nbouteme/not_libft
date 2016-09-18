/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 03:47:21 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:47:31 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	print_error(t_error *e, const char *i)
{
	t_fpos s;

	s = (t_fpos){0, 0, 0};
	s.line = 1;
	while (s.line != e->loc.line)
		if (*i++ == '\n')
			++s.line;
	while (*i && *i != '\n')
	{
		ft_putchar((*i == '\t' ? ' ' : *i));
		++i;
	}
	ft_putchar('\n');
	while (s.col++ != e->loc.col)
		ft_putchar(' ');
	ft_putchar('^');
	ft_putchar('\n');
}
