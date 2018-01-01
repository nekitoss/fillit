/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_find_dot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:16:51 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/01 17:17:39 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_find_dot(t_liist *head, char **map, int *x, int *y)
{
	while (*x < *(head->map_s) && map[*x][*y] != '.')
	{
		while (*y < *(head->map_s) && map[*x][*y] != '.')
			(*y)++;
		if (map[*x][*y] == '.')
			return ;
		*y = 0;
		(*x)++;
	}
}
