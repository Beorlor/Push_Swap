/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:29:43 by jedurand          #+#    #+#             */
/*   Updated: 2024/02/21 04:29:45 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ############# Initialize the values ##############
void	init_values(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}

void	select_pivots(int stack_size, t_stack *stack, t_value *var)
{
	long	min;
	long	max;

	min = get_min_value(stack->top, stack_size);
	max = get_max_value(stack->top, stack_size);
	var->big_pivot = (min + max) / 2;
	var->small_pivot = (min + var->big_pivot) / 2;
}

static void	prep_b(t_stack *a, t_stack *b, t_value *var)
{
	if (a->top->value > var->big_pivot)
	{
		rotate_stack(a, A);
		var->ra++;
	}
	else
	{
		push_stack(a, b, B);
		var->pb++;
		if (b->top->value < var->small_pivot)
		{
			rotate_stack(b, B);
			var->rb++;
		}
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	if (a->size == 5)
		five_handler(a, b);
	else
	{
	        int		tmp = a->size;
	        t_value	test;
	        init_values(&test);
	        select_pivots(a->size, a, &test);
	        while (tmp--)
	        {
		  prep_b(a, b, &test);
		}
	        a_to_b(test.ra, a, b, &count);
	        test.rb += 2;
	        b_to_a(test.rb, a, b, &count);
	        b_to_a(test.pb - test.rb, a, b, &count);
	}
}
