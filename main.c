/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:29:48 by jedurand          #+#    #+#             */
/*   Updated: 2024/02/21 04:29:50 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

/*
 * Check if stack a is sorted or not yet.
 * While there is a next node, if the value of
 * current node is bigger than the value of the
 * next node, return zero, if next node exists,
 * then move the current node to the next node.
 */
int	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
		{
			if (node->value > node->next->value)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->value == a->bottom->value)
		return (1);
	else
		return (0);
}

/*
 * Declare the stacks and take the arguments,
 * if no argument is given return an error message.
 * while there is an argument left init the stack a,
 * and fill it with the arguments.
 */
#include <stdio.h>
void display_stack(t_stack *a)
{
    t_node *current_node;

    if (!a)
    {
        printf("Stack is NULL\n");
        return;
    }

    current_node = a->top;
    printf("Stack A contents:\n");
    while (current_node)
    {
        printf("%d\n", current_node->value);
        current_node = current_node->next;
    }
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = init_stack();
		a->top = fill_stack(argc, argv, &a);
		check_duplicated(a->top);
		b = init_stack();
		if (is_sorted(a))
		{
			free_all(a, b);
			return (0);
		}
		push_swap(a, b);
		//display_stack(a);
		//display_stack(b);
		if (is_sorted(a))
		  printf("is sorted\n");
		else
		  printf("is not sorted\n");
		free_all(a, b);
	}
}
