/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lang_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:21:09 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:59:20 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void			*gen_statement(int n, void **b)
{
	t_statement *stmt;

	if (n != 4)
		return (0);
	stmt = ft_memalloc(sizeof(*stmt));
	stmt->name = ft_strdup(b[0]);
	free(b[0]);
	stmt->gr = b[2];
	free(b[1]);
	free(b[3]);
	return (stmt);
}

void			init_lang(t_symtable **tg, t_parser *pa[])
{
	*tg = malloc(sizeof(**tg));
	(*tg)->syms = ftext_lstnew();
	assign_parser(get_parser(*tg, "name"), loc_ast_state(tag_p(apply_parser(
		tok_parser(cident_parser()), ast_putstr), "identifier")));
	assign_parser(get_parser(*tg, "string"), loc_ast_state(tag_p(apply_parser(
		tok_parser(cident_parser()), ast_putstr), "identifier")));
	pa[0] = init_parser(malloc(sizeof(t_parser) + 0x30), 0, do_nothing);
	pa[1] = init_parser(malloc(sizeof(t_parser) + 0x30), 0, do_nothing);
	pa[2] = init_parser(malloc(sizeof(t_parser) + 0x30), 0, do_nothing);
	pa[3] = init_parser(malloc(sizeof(t_parser) + 0x30), 0, do_nothing);
	pa[4] = init_parser(malloc(sizeof(t_parser) + 0x30), 0, do_nothing);
	pa[5] = init_parser(malloc(sizeof(t_parser) + 0x30), 0, do_nothing);
	assign_parser(pa[0], apply_up_parser(zom_parser(sm_fold, pa[1]),
		save_rule_to, *tg));
}

t_langparser	*lang_parser(char *il)
{
	t_parser	*pa[6];
	t_symtable	*tg;
	void		*ret;

	init_lang(&tg, pa);
	assign_parser(pa[1], and_parser(delete_parser, gen_statement, 4,
		(t_parser*[]){tok_parser(cident_parser()), string_parser(":="), pa[2],
		char_parser(';')}));
	assign_parser(pa[2], and_parser(delete_parser, fold_or, 2, (t_parser*[]){
		pa[3], maybe_parser(and_parser(delete_parser, eval_second, 2,
		(t_parser*[]) {char_parser('|'), pa[2]}))}));
	assign_parser(pa[3], oom_parser(fold_anda, pa[4]));
	assign_parser(pa[4], and_parser(delete_parser, fold_repa, 2, (t_parser*[]){
pa[5], or_parser(2, (t_parser*[]){oneof_parser("*+?!"), nothing_parser()})}));
	assign_parser(pa[5], or_parser(5, (t_parser*[]){
		apply_parser(tok_parser(strlit_parser()), ast_genstring),
		apply_parser(tok_parser(charlit_parser()), ast_genchar),
		apply_parser(tok_parser(reglit_parser()), ast_genregex),
apply_up_parser(tok_parser(tokbra_parser(cident_parser())), ast_genpref, tg),
		paren_parser(pa[2])}));
	run_parser(pa[0], il, &ret);
	delete_parser(pa[0]);
	delete_parsers();
	return (tg);
}
