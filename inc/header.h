#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

# define BUF_SIZE 21


# define USAGE 1
# define FILE_OPEN 2
# define NOT_FULL_FIGURE 3
# define INCORRECT_FIGURE 4
# define WRONG_NUMBER_OF_BLOCKS 5
# define WRONG_TOUCHES 6

typedef struct	figure
{
	int		arr[4][4];
	int		x[4];
	int 	y[4];
	int		*map_size;		
	//int 	width;
	//int 	height;
	char	id;
	//int		
}				fig;

#endif