/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:30:18 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 03:27:39 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <libft/parser.h>

char	*file2buf(const char *file)
{
	char		*ret;
	unsigned	f;
	int			r;
	int			fd;

	ret = ft_memalloc(512);
	f = 0;
	fd = open(file, O_RDONLY);
	while ((r = read(fd, &ret[f], 512)) > 0)
	{
		f += r;
		ret = mrealloc(ret, f, f + 512);
	}
	close(fd);
	return (ret);
}
