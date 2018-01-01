/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:22:00 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/01 17:22:45 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**map_generate(int map_s)
{
	char	**map;
	int		i;

	map = (char**)ft_memalloc(sizeof(char*) * (map_s + 1));
	if (map == NULL)
		exit(1);
	i = 0;
	while (i < map_s)
	{
		map[i] = (char*)ft_memalloc2(sizeof(char) * (map_s));
		map[i][map_s] = '\0';
		if (map[i] == NULL)
		{
			while (i > 0)
			{
				ft_strdel(&map[i]);
				i--;
			}
			ft_strdel(&map[i]);
			ft_strdel(map);
			exit(1);
		}
		i++;
	}
	return (map);
}
