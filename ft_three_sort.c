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

static t_node *find_smallest(t_node *stack)
{
    int smallest = INT_MAX;
    t_node *smallest_node = NULL;

    while (stack) {
        if (stack->num < smallest)
		{
            smallest = stack->num;
            smallest_node = stack;
        }
        stack = stack->next;
    }
    return smallest_node;
}

void five_sort(t_node **a, t_node **b)
{
	t_node *smallest_node;
	int count;
	int	stack_size;

	count = 0;
	stack_size = list_size(*a);
	while (count < (stack_size - 3))
	{
		smallest_node = find_smallest(*a);
		while (*a != smallest_node)
			ra(a);
		pb(a, b);
		count++;
	}
	three_sort(a);
	if (stack_size == 5)
	{
		smallest_node = find_smallest(*b);
		if (*b == smallest_node)
			rb(b);
		pa(a, b);
	}
	pa(a, b);
}
