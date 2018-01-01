/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:25:00 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/01 17:25:22 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	tetromino_set(t_liist *head, char **map, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (x + head->x[i] < *(head->map_s) && y + head->y[i] >= 0
				&& y + head->y[i] < *(head->map_s)
				&& map[x + head->x[i]][y + head->y[i]] == '.')
		{
			map[x + head->x[i]][y + head->y[i]] = head->tag;
		}
		else
			return (0);
	}
	return (1);
}
