#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
One good way to implement algorithm X is to represent each 1 in the
matrix A as a data object x with five fields L[x], R[x], U[x], D[x], C[x]. Rows of the matrix
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
	struct Node	*left
	struct Node	*right;
	struct Node	*up;
	struct Node	*down;
	struct Row *row;
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
	struct Node	*left
	struct Node	*right;
	struct Node	*up;
	struct Node	*down;
	struct Node *head;
	int 		length;
	int			name;
}				Col;


/*
typedef struct	Node
{
	struct Node	*left
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
	struct Node	*left
	struct Node	*right;
	struct Node *head;
	int 		length;
	int			name;
}				Col;
*/
#endif