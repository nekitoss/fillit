/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:49:42 by nekitoss          #+#    #+#             */
/*   Updated: 2017/02/24 16:49:46 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		read_file(char *addr, int *m_size)
{
	int		fd;
	int		read_len;
	char	*buf;
	t_liist	**fig_arr;
	int		i;

	i = 0;
	fig_arr = (t_liist **)malloc(sizeof(t_liist*) * 27);
	buf = ft_strnew(BUF_SIZE);
	read_len = 0;
	if ((fd = open(addr, O_RDONLY)) > -1 && buf)
	{
		while ((read_len = read(fd, buf, BUF_SIZE)) == BUF_SIZE && i < 26)
			init_list(fig_arr, m_size, &i, buf);
		if (i >= 0 && i < 26 && read_len == BUF_SIZE - 1)
			init_list(fig_arr, m_size, &i, buf);
		else
			error(NOT_FULL_FIGURE);
	}
	else
		error(FILE_OPEN);
	while (i < 27)
		fig_arr[i++] = NULL;
	call_exec(fig_arr);
}

int				main(int argc, char **argv)
{
	int	*m_size;

	m_size = (int *)malloc(sizeof(int));
	if (argc == 2)
	{
		read_file(argv[1], m_size);
	}
	else
		error(USAGE);
	return (0);
}
