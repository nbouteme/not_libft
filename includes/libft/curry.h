/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curry.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 04:43:02 by nbouteme          #+#    #+#             */
/*   Updated: 2016/10/30 05:26:21 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURRY_H
# define CURRY_H

union	u_value
{
	void	*p;
	long	v;
};

typedef union u_value	t_value __attribute__((transparent_union));

typedef t_value(*t_4)(t_value, t_value, t_value, t_value);
typedef t_value(*t_3)(t_value, t_value, t_value);
typedef t_value(*t_2)(t_value, t_value);
typedef t_value(*t_1)(t_value);
typedef t_value(*t_0)(void);
typedef t_value(*t_curryg)(t_value);

t_value	curry(void *f, t_value arg);
void	*funalloc();
void	free_fun(void *fun);
long	ft_syscall();

#endif
