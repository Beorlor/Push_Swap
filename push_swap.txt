#include "ft.h"

int	get_max_digit(t_node *list)
{
	int max;
	int count;

	max = 0;
	count = 0;
	while (list)
	{
		if (list->index > max)
			max = list->index;
		list = list->next;
	}
	while (max)
	{
		count++;
		max /= 10;
	}
	return (count);
}

int	get_digit(int number, int position)
{
	while (position--)
		number /= 10;
	return (number % 10);
}

void	move_to_b_based_on_digit(t_node **a, t_node **b, int position, int digit)
{
	int	len;
	int	i;

	len = list_size(*a);
	i = 0;
	while (i < len)
	{
		if (get_digit((*a)->index, position) == digit)
			pb(a, b); // Implement this function for pushing an element from stack a to stack b.
		else
			ra(a); // Implement this function for rotating stack a.
		i++;
	}
}

void	move_back_to_a(t_node **a, t_node **b)
{
	while (*b)
		pa(a, b); // Implement this function for pushing an element from stack b to stack a.
}

void	radix_sort(t_node **a, t_node **b)
{
	int	max_digit;
	int	position;
	int	d;

	max_digit = get_max_digit(*a);
	position = 0;
	while (position < max_digit)
	{
		d = 0;
		while (d < 10)
		{
			move_to_b_based_on_digit(a, b, position, d);
			d++;
		}
		move_back_to_a(a, b);
		position++;
	}
}
