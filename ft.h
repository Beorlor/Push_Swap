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
char	**ft_format(int ac, char *av[]);

int	check_input(char *str_numb[]);
int	ft_atoi(char *s, int *outOfRange);

void free_str_numb(char **str_numb);
void	free_nodes(t_node **lst);

t_node	*new_node(int num);
void	append_node(t_node **head, int num);
t_node	*get_last_node(t_node *head);
int	list_size(t_node *head);
int	stack_sorted(t_node *head);

void	stack_init(t_node **a, char **str_numb);

void sa(t_node **a);
void sb(t_node **b);
void ss(t_node **a, t_node **b);
void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);
void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **a, t_node **b);
void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);

void	three_sort(t_node **a);
void	five_sort(t_node **a, t_node **b);

#endif
