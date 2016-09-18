/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:30:44 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:29:33 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

static void	print_ast_frag(t_ast *a)
{
	ft_putstr(a->tag);
	ft_putstr(" -> ");
	ft_putnbr(a->loc.line);
	ft_putchar(':');
	ft_putnbr(a->loc.col);
	ft_putchar(' ');
	ft_putendl(a->value);
}

static void	ast_printr(t_ast *a, int d)
{
	int i;

	i = 0;
	if (!a)
		return ;
	while (i++ < d)
		ft_putstr("   ");
	i = 0;
	if (ft_strlen(a->value))
		print_ast_frag(a);
	else
		ft_putendl(a->tag);
	while (i < a->n_children)
		ast_printr(a->children[i++], d + 1);
}

void		ast_print(t_ast *a)
{
	ast_printr(a, 0);
}
