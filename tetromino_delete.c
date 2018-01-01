/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:24:24 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/01 17:24:44 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetromino_delete(t_liist *head, char **map, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (x + head->x[i] < *(head->map_s) && y + head->y[i] >= 0
			&& y + head->y[i] < *(head->map_s)
			&& map[x + head->x[i]][y + head->y[i]] == head->tag)
		{
			map[x + head->x[i]][y + head->y[i]] = '.';
		}
	}
}
