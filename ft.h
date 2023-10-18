#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

#include <stdio.h>

typedef struct s_node
{
	int	num;
	struct s_node	*next;
}		t_node;

#endif
