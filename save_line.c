/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:14:25 by nekitoss          #+#    #+#             */
/*   Updated: 2017/03/01 20:14:33 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_char(t_liist *fig, char *buf, int i, int *cnt)
{
	if (buf[i] == '.' && i < 20)
	{
		(*cnt)++;
		fig->arr[fig->line][i % 5] = 0;
	}
	else if (buf[i] == '#' && i < 20)
	{
		(*cnt)--;
		fig->arr[fig->line][i % 5] = 1;
	}
	else if (i == 19 && buf[19] == '\n' && buf[20] == '\n')
		return (0);
	else if (buf[i] == '\n' && (i + 1) % 5 == 0)
		(fig->line)++;
	else
		error(INCORRECT_FIGURE);
	return (1);
}

void		save_line(char *buf, t_liist *fig)
{
	int			i;
	int			cnt;

	i = 0;
	cnt = 0;
	while (buf[i] != '\0')
	{
		if (!check_char(fig, buf, i, &cnt))
			break ;
		i++;
	}
	if (cnt != 8)
		error(WRONG_NUMBER_OF_BLOCKS);
}

void		make_list(t_liist **fig_arr)
{
	int k;

	k = 0;
	while (fig_arr[++k])
	{
		fig_arr[k - 1]->next = fig_arr[k];
	}
	fig_arr[k - 1]->next = NULL;
}

void		init_list(t_liist **fig_arr, int *m_size, int *i, char *buf)
{
	fig_arr[*i] = (t_liist *)malloc(sizeof(t_liist) * 1);
	(fig_arr[*i])->map_s = m_size;
	(fig_arr[*i])->tag = *i + 'A';
	save_line(buf, fig_arr[*i]);
	ft_strclr(buf);
	(*i)++;
}

void		call_exec(t_liist **fig_arr)
{
	check_figures(fig_arr);
	cut_figures(fig_arr);
	make_list(fig_arr);
	map_control(fig_arr[0]);
}
