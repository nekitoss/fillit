/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:04:11 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/01 18:05:34 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**fillit_core(t_liist *head, char **map, int x, int y)
{
	fillit_find_dot(head, map, &x, &y);
	if (x == *(head->map_s) && y == *(head->map_s))
		return (0);
	if (tetromino_set(head, map, x, y) == 1)
	{
		if ((head->next) && (!fillit_core(head->next, map, 0, 0)))
		{
			tetromino_delete(head, map, x, y);
			if (y < *(head->map_s))
				fillit_core(head, map, x, ++y);
			else if (x < *(head->map_s))
				fillit_core(head, map, ++x, 0);
		}
		else
			map_print(map);
	}
	else
	{
		tetromino_delete(head, map, x, y);
		if (y < *(head->map_s))
			fillit_core(head, map, x, ++y);
		else if (x < *(head->map_s))
			fillit_core(head, map, ++x, 0);
	}
	return (0);
}
