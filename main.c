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
	else if (n == )
		ft_putstr("");
	else if (n == )
		ft_putstr("");
	else if (n == )
		ft_putstr("");
	else
	{
		ft_putstr("unknown error number = ");
		ft_putchar(n + '0');
	}
	ft_putchar('\n');
	exit();
}

static void		save_figure(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '.')
			asd
		else if (buf[i] == '#')
		{

		}
		else if (i == 19 && buf[19] == '\n' && buf[20] == '\n')
			break ;
		else if (buf[i] == '\n' && (i + 1) % 5 == 0)

		else
			eror(INCORRECT_FIGURE);
		i++;
	}
}

static void		read_file(char *addr)
{
	int		fd;
	size_t	read_len;
	char	*buf;

	buf = ft_strnew(BUF_SIZE);
	read_len = 0;
	if ((fd = open(addr, ORDONLY)) > 2 && buf)
	{
		while ()
		{
			read_len = read(fd, buf, BUF_SIZE);
			if (read_len == BUF_SIZE)
				save_figure(buf);
			else  if (read_len == BUF_SIZE - 1 || read_len == EOF)
			{
				printf("read_len = %d\n", read_len);
				save_figure(buf);
			}
			else
				eror(NOT_FULL_FIGURE);
			read_len = read(fd, buf, BUF_SIZE);
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