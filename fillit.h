/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:13:48 by nekitoss          #+#    #+#             */
/*   Updated: 2017/02/23 17:13:52 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include "libft.h"
# include <stdio.h>
# define BUF_SIZE 21
# define USAGE 1
# define FILE_OPEN 2
# define NOT_FULL_FIGURE 3
# define INCORRECT_FIGURE 4
# define WRONG_NUMBER_OF_BLOCKS 5
# define WRONG_TOUCHES 6
# define MAX_MAP_SIZE 14

typedef struct	s_liist
{
	int				arr[4][4];
	int				x[5];
	int				y[5];
	char			tag;
	int				line;
	int				*map_s;
	struct s_liist	*next;
}				t_liist;

int				map_size(t_liist *head);
char			**map_generate(int map_s);
void			map_delete(char **map);
void			map_print(char **map);
void			map_control(t_liist *head);
char			**fillit_core(t_liist *head, char **map, int x, int y);
void			fillit_find_dot(t_liist *head, char **map, int *x, int *y);
int				tetromino_set(t_liist *head, char **map, int x, int y);
void			tetromino_delete(t_liist *head, char **map, int x, int y);
void			*ft_memalloc2(size_t size);
void			ft_bzero2(void *s, size_t n);
int				check_char(t_liist *fig, char *buf, int i, int *cnt);
void			save_line(char *buf, t_liist *fig);
void			make_list(t_liist **fig_arr);
void			init_list(t_liist **fig_arr, int *m_size, int *i, char *buf);
void			call_exec(t_liist **fig_arr);
void			error(int n);
void			calculate(t_liist **fig_arr, int *i, int *k, int *z);
void			cut_figures(t_liist **fig_arr);
void			check_touch(t_liist *fig_arr, int *touch);
void			check_figures(t_liist **fig_arr);

#endif
