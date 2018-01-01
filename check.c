/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:14:36 by nekitoss          #+#    #+#             */
/*   Updated: 2017/03/01 20:14:38 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		error(int n)
{
	if (n == USAGE)
		ft_putstr("usage: fillit source_file");
	else
		ft_putstr("error");
	ft_putchar('\n');
	exit(0);
}

void		calculate(t_liist **fig_arr, int *i, int *k, int *z)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (fig_arr[*k]->arr[*i][j] && !*z)
		{
			fig_arr[*k]->x[4] = *i;
			fig_arr[*k]->y[4] = j;
		}
		if (fig_arr[*k]->arr[*i][j])
		{
			fig_arr[*k]->x[*z] = *i - fig_arr[*k]->x[4];
			fig_arr[*k]->y[(*z)++] = j - fig_arr[*k]->y[4];
		}
	}
}

void		cut_figures(t_liist **fig_arr)
{
	int i;
	int k;
	int z;

	k = -1;
	while (fig_arr[++k])
	{
		i = -1;
		z = 0;
		while (++i < 4)
			calculate(fig_arr, &i, &k, &z);
	}
}

void		check_touch(t_liist *fig_arr, int *touch)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (fig_arr->arr[i][j])
			{
				if (j > 0 && fig_arr->arr[i][j - 1])
					(*touch)++;
				if (i > 0 && fig_arr->arr[i - 1][j])
					(*touch)++;
				if (j < 3 && fig_arr->arr[i][j + 1])
					(*touch)++;
				if (i < 3 && fig_arr->arr[i + 1][j])
					(*touch)++;
			}
		}
	}
}

void		check_figures(t_liist **fig_arr)
{
	int k;
	int touch;

	k = -1;
	while (fig_arr[++k])
	{
		touch = 0;
		check_touch(fig_arr[k], &touch);
		if (touch == 6 || touch == 8)
			continue ;
		else
			error(WRONG_TOUCHES);
	}
}
