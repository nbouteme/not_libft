/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsertypes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:49:59 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:51:57 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERTYPES_H
# define PARSERTYPES_H

typedef struct s_parser		t_parser;
typedef struct s_input		t_input;
typedef struct s_symtable	t_symtable;
typedef t_symtable			t_langparser;

typedef int		(*t_match_f)(t_parser *, t_input *, void**);
typedef void	(*t_pdtor)(t_parser *);
typedef void	*(*t_folder)(int, void **);
typedef void	(*t_dtor)(void *);
typedef void	*(*t_apply_fun)(void*);
typedef void	*(*t_apply_fun_up)(void*, void*);

#endif
