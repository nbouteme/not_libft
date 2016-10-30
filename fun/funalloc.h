/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funalloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 04:48:31 by nbouteme          #+#    #+#             */
/*   Updated: 2016/10/30 05:23:16 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNALLOC_H
# define FUNALLOC_H

# include <stdbool.h>
# include <libft/curry.h>

void *funalloc();
void free_fun(void *fun);
void ex_set(int v);

#endif
