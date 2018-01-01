/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:20:55 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/01 17:21:19 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_control(t_liist *head)
{
	int		x;
	int		y;
	char	**map;

	*(head->map_s) = map_size(head);
	while (*(head->map_s) < MAX_MAP_SIZE)
	{
		x = 0;
		map = map_generate(*(head->map_s));
		while (x < *(head->map_s))
		{
			y = 0;
			while (y < *(head->map_s))
			{
				map_delete(map);
				map = map_generate(*(head->map_s));
				fillit_core(head, map, x, y);
				y++;
			}
			x++;
		}
		map_delete(map);
		(*(head->map_s))++;
	}
}
