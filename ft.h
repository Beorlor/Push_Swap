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
	struct s_node	*prev;
}		t_node;

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c);
char	**format(int ac, char *av[]);

#endif
