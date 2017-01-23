//#######################
#include <stdio.h>
//#######################




#include "header.h"

static void		error(int n)
{
	if (n == USAGE)
		ft_putstr("usage: fillit source_file");
	else if (n == FILE_OPEN)
		ft_putstr("error opening file");
	else if (n == NOT_FULL_FIGURE)
		ft_putstr("figure is wrong");
	else if (n == INCORRECT_FIGURE)
		ft_putstr("figure is incorrect");
	else if (n == WRONG_NUMBER_OF_BLOCKS)
		ft_putstr("wring_nuber_of_blocks_in_figure");
	else if (n == WRONG_TOUCHES)
	 	ft_putstr("wrong_number_of_touches_in_figure");
	// else if (n == )
	// 	ft_putstr("");
	else
	{
		ft_putstr("unknown error number = ");
		ft_putchar(n + '0');
	}
	ft_putchar('\n');
	exit(0);
}

void			print_fig_list(fig **fig_arr)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (fig_arr[k])
	{
		printf("\nFigure id = %d\n", (fig_arr[k])->id);
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				printf("%d", (fig_arr[k])->arr[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		j = 0;
		while (j < 4)
		{
			printf("x[j]=%d; y[j]=%d\n", (fig_arr[k])->x[j],(fig_arr[k])->y[j]);
			j++;
		}
		k++;
	}
}

void			insert_figure(fig figure, int i, int j)
{
	int z;

	z = -1;
	create_row(figure->id);
	while(++z < 4)
	{
		put_node(i + figure->y[z], j + figure->x[z]);
	}
}

void			make_matrix(fig **fig_arr, int map_size)
{
	int i;
	int j;
	int k;
	int z;

	k = -1;
	while(fig_arr[++k])
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while(++j < 4)
			{
				z = -1;
				while(++z < 4)
					if (!(i + fig_arr[k]->y[z] < map_size &&
						j + fig_arr[k]->x[z] >= 0 &&
							j + fig_arr[k]->x[z] < map_size))
						break ;
				if (z == 4)
					insert_figure(fig_arr[k], i, j);
			}
		}
	}
}

void cut_figures(fig **fig_arr)
{
	int i;
	int j;
	int k;
	int z;

	k = -1;
	while(fig_arr[++k])
	{
		i = -1;
		z = 0;
		fig_arr[k]->x[0] = 0;
		fig_arr[k]->y[0] = 0;
		while (++i < 4)
		{
			j = -1;
			while(++j < 4)
			{
				if (fig_arr[k]->arr[i][j])
				{
					fig_arr[k]->y[z] = i - fig_arr[k]->y[0];
					fig_arr[k]->x[z++] = j - fig_arr[k]->x[0];
				}
			}
		}
	}
}

static void		check_figures(fig **fig_arr)
{
	int i;
	int j;
	int k;
	int touch;

	k = -1;
	while(fig_arr[++k])
	{
		i = 0;
		touch = 0;
		while (i < 4)
		{
			j =0;
			while(j < 4)
			{

				if (fig_arr[k]->arr[i][j])
				{
					if (j > 0 && fig_arr[k]->arr[i][j - 1])
						touch++;
					if (i > 0 && fig_arr[k]->arr[i - 1][j])
						touch++;
					if (j < 3 && fig_arr[k]->arr[i][j + 1])
						touch++;
					if (i < 3 && fig_arr[k]->arr[i + 1][j])
						touch++;
				}
				j++;
			}
			i++;
		}
		if (touch == 6 || touch == 8)
			continue ;
		else
			error(WRONG_TOUCHES);
	}
}

static void		save_line(char *buf, fig *fig)
{
	int			i;
	int			cnt;
	int 		line;

	line = 0;
	i = 0;
	cnt = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '.' && i < 20)
		{
			cnt++;
			fig->arr[line][i % 5] = 0;
		}
		else if (buf[i] == '#' && i < 20)
		{
			cnt--;
			fig->arr[line][i % 5] = 1;
		}
		else if (i == 19 && buf[19] == '\n' && buf[20] == '\n')
			break ;
		else if (buf[i] == '\n' && (i + 1) % 5 == 0)
			line++;
		else
			error(INCORRECT_FIGURE);
		i++;
	}
	if (cnt != 8)
		error(WRONG_NUMBER_OF_BLOCKS);
}

static void		read_file(char *addr)
{
	int		fd;
	int		read_len;
	char	*buf;
	fig		**fig_arr;
	int 	i;

	i = 0;
	fig_arr = (fig **)malloc(sizeof(fig*) * 26);
	buf = ft_strnew(BUF_SIZE);
	read_len = 0;
	if ((fd = open(addr, O_RDONLY)) > 2 && buf)
	{
		while ((read_len = read(fd, buf, BUF_SIZE)) == BUF_SIZE && i < 26)
		{
			fig_arr[i] = (fig *)malloc(sizeof(fig) * 1);
			(fig_arr[i])->id = i;
			save_line(buf, fig_arr[i]);
			ft_strclr(buf);
			i++;
		}
		if (i > 0 && i < 26 && read_len  == BUF_SIZE - 1)
		{
			fig_arr[i] = (fig *)malloc(sizeof(fig) * 1);
			(fig_arr[i])->id = i;
			save_line(buf, fig_arr[i++]);
		}
		else
			error(NOT_FULL_FIGURE);
	}
	else
		error(FILE_OPEN);
	while (i < 26)
		fig_arr[i++] = NULL;

	check_figures(fig_arr);
	cut_figures(fig_arr);
	make_matrix(fig_arr);
	print_fig_list(fig_arr);
	//return ();
}

int				main(int argc, char **argv)
{
    //printf("test");
	//add usage
	if (argc == 2)
	{
		read_file(argv[1]);
	}
	else
		error(USAGE);
	return (0);
}