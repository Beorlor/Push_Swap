#include "ft.h"

static int have_duplicate(t_node *stack)
{
    t_node *current = stack;
    t_node *check;
	int	dup;

	dup = 0;
    while (current)
    {
        check = current->next;
        while (check)
        {
            if (current->num == check->num)
                dup = 1;
            check = check->next;
        }
        current = current->next;
    }
    if (dup)
	{
		free_nodes(&stack);
		write(2, "Duplicate Detected\n", 19);
		exit (1);
	}
}


void	stack_init(t_node **a, char **str_numb)
{
	int	outOfRange;
	int	numb;
	char **temp = str_numb;

	outOfRange = 0;
	numb = 0;
	check_input(str_numb);
	while (*temp)
	{
		numb = ft_atoi(*temp, &outOfRange);
		if (outOfRange == 1)
		{
			free_str_numb(str_numb);
			free_nodes(a);
			write(2, "Not an Int\n", 11);
			exit (1);
		}
		append_node(a, numb);
		temp++;
	}
	free_str_numb(str_numb);
	have_duplicate(*a);
}
