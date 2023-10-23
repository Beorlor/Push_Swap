#include "ft.h"

// Fonction d'échange pour le tri
static void	swap_nodes(t_node **a, t_node **b)
{
	t_node *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// Fonction de tri par insertion
static void	sort_node_array(t_node **array, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && array[j - 1]->num > array[j]->num)
		{
			swap_nodes(&array[j], &array[j - 1]);
			j--;
		}
		i++;
	}
}

static void	assign_indexes(t_node *head)
{
	int		size;
	t_node	*current;
	t_node	**node_array;
	int		i;

	size = list_size(head);
	node_array = (t_node **)malloc(sizeof(t_node *) * size);
	if (!node_array)
		return ;
	current = head;
	i = 0;
	while (current)
	{
		node_array[i] = current;
		current = current->next;
		i++;
	}
	sort_node_array(node_array, size);
	i = 0;
	while (i < size)
	{
		node_array[i]->index = i;
		i++;
	}
	free(node_array);
}

static void have_duplicate(t_node *stack)
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
	assign_indexes(*a);
}
