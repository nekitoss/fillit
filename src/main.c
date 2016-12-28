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
	// else if (n == )
	// 	ft_putstr("");
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
		if (buf[i] == '.')
		{
			cnt++;
			fig->arr[line % 4][i] = 0;
		}
		else if (buf[i] == '#')
		{
			cnt--;
			fig->arr[line][i] = 1;
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
	int	read_len;
	char	*buf;
	fig		*fig1;

	fig1 = (fig *)malloc(sizeof(fig) * 1);
	buf = ft_strnew(BUF_SIZE);
	read_len = 0;
	if ((fd = open(addr, O_RDONLY)) > 2 && buf)
	{
		while (1)
		{
			ft_strclr(buf);
			read_len = read(fd, buf, BUF_SIZE);
			if (read_len == BUF_SIZE)
				save_line(buf, fig1);
			else  if (read_len == BUF_SIZE - 1 || read_len == BUF_SIZE - 2)
			{
				printf("read_len = %d\n", read_len);
				save_line(buf, fig1);
			}
			else if(read_len == 0)
				break ;
			else
				error(NOT_FULL_FIGURE);
		}
	}
	else
		error(FILE_OPEN);
	//return ();
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		read_file(argv[1]);
	else
		error(USAGE);
	return (0);
}