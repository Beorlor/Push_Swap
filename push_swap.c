/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:29:43 by jedurand          #+#    #+#             */
/*   Updated: 2024/02/21 06:14:39 by jedurand         ###   ########.fr       */
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

void	push_swap(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	if (a->size == 5)
		five_handler(a, b);
	else
		a_to_b(a->size, a, b, &count);
}
