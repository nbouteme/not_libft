/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 04:44:03 by nbouteme          #+#    #+#             */
/*   Updated: 2016/11/04 11:54:05 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/syscall.h>
#include "funalloc.h"

#define PAGE_SIZE 4096
#define FUN_NBR 64
#define FUN_SIZE 64
#define MSTB_PSIZE (((64 / 8) / PAGE_SIZE) + 1)
#define FUNB_PSIZE (((64 * 64) / PAGE_SIZE) + (((64 * 64) % PAGE_SIZE) != 0))
#define MSTB_SIZE (MSTB_PSIZE * PAGE_SIZE)
#define FUNB_SIZE (FUNB_PSIZE * PAGE_SIZE)

void	**get_master_block(void)
{
	static void *mb = 0;

	return (&mb);
}

void	init_master_block(void)
{
	int		i;
	char	*mb;

	mb = (void*)ft_syscall(SYS_mmap, 0l, MSTB_SIZE + FUNB_SIZE,
						PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
						-1l, 0l);
	i = 0;
	while (i < (FUN_NBR / 8))
		mb[i++] = 0;
	*get_master_block() = mb;
}

void	*funalloc(void)
{
	int				i;
	unsigned char	*mb;
	int				n;
	int				j;

	mb = *get_master_block();
	if (!mb)
		init_master_block();
	mb = *get_master_block();
	i = 0;
	n = 0;
	while (i < (FUN_NBR / 8))
		if (mb[i] != 0xff)
		{
			j = mb[i];
			while ((j >> n) & 1)
				n++;
			mb[i] |= 1 << n;
			mb += MSTB_SIZE;
			return (mb + (64 * n));
		}
		else
			++i;
	return (0);
}

void	free_fun(void *fun)
{
	char	*f;
	char	*fb;
	char	*m;
	int		i;
	void	**v;

	f = fun;
	v = get_master_block();
	m = *v;
	fb = m + MSTB_SIZE;
	m += ((f - fb) / 64) / 8;
	m[0] &= ~((1 << (f - fb) / 64) - 1);
	i = 0;
	while (i < (FUN_NBR / 8) && !m[i])
		++i;
	if (i != (FUN_NBR / 8))
		return ;
	ft_syscall(SYS_munmap, *v, MSTB_SIZE + FUNB_SIZE);
	*v = 0;
}

void	ex_set(int v)
{
	char *fb;

	fb = *get_master_block();
	fb += MSTB_SIZE;
	if (v)
		ft_syscall(SYS_mprotect, fb, FUNB_SIZE, PROT_READ | PROT_EXEC);
	else
		ft_syscall(SYS_mprotect, fb, FUNB_SIZE, PROT_READ | PROT_WRITE);
}
