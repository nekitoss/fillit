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
/*
One good way to implement algorithm X is to represent each 1 in the
matrix A as a data object x with five fields  . Rows of the matrix
are doubly linked as circular lists via the L and R fields (“left” and “right”); columns are
doubly linked as circular lists via the U and D fields (“up” and “down”). Each column
list also includes a special data object called its list header.

The list headers are part of a larger object called a column object. Each column object
y contains the fields L[y], R[y], U[y], D[y], and C[y] of a data object and two additional
fields, S[y] (“size”) and N[y] (“name”); the size is the number of 1s in the column, and the
name is a symbolic identifier for printing the answers. The C field of each object points
to the column object at the head of the relevant column.

The L and R fields of the list headers link together all columns that still need to be
covered. This circular list also includes a special column object called the root, h, which
serves as a master  header for all the active headers. The fields U[h], D[h], C[h], S[h], and
N[h] are not used.
*/
typedef struct	Node
{
	struct Node	*left;
	struct Node	*right;
	struct Node	*up;
	struct Node	*down;
	struct Row *row;
	struct Col *col;
}				Node;

typedef struct	Row
{
	struct Node	*up;
	struct Node	*down;
	struct Node	*head;
	int			length;
	int			name;
}				Row;

typedef struct	Col
{
	struct Node	*left;
	struct Node	*right;
	struct Node *head;
	int 		length;
	int			name;
}				Col;

typedef struct	figure
{
	int		arr[4][4];
	int		x[4];
	int 	y[4];
	int 	width;
	int 	height;
	char	id;
	//int		
}				fig;

#endif