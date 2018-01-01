/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:33:12 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/01 18:03:06 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	map_size(t_liist *head)
{
	int		n_nodes;
	int		sqr;
	int		len;

	n_nodes = 4;
	sqr = 2;
	len = 1;
	while (head->next)
	{
		head = head->next;
		len++;
	}
	while ((sqr * sqr) < (len * n_nodes))
		sqr++;
	return (sqr);
}
