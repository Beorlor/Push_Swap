#include "ft.h"

static t_node	*find_highest(t_node *stack)
{
	int				highest;
	t_node	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->num > highest)
		{
			highest = stack->num;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	three_sort(t_node **a)
{
	t_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}
