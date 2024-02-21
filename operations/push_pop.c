/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:30:46 by jedurand          #+#    #+#             */
/*   Updated: 2024/02/21 04:30:48 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * If from contains only one node.
 * If the to stack is empty, we simply put the from->top
 * into the to->top and assign to->bottom to, to->top.
 */
static void	from_size_one(t_stack *from, t_stack *to)
{
	if (to->size == 0)
	{
		to->top = from->top;
		to->bottom = to->top;
	}
	else
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = to->top->prev;
	}
	from->top = NULL;
	from->bottom = NULL;
}

/*
 * We handle the case if from contains only one node.
 * If from is more than one node, then we handle if,
 * to is empty, and if it's not.
 */
static void	push_pop(t_stack *from, t_stack *to)
{
	if (from->size == 1)
		from_size_one(from, to);
	else
	{
		if (to->size == 0)
		{
			to->top = from->top;
			to->bottom = to->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->next = NULL;
		}
		else
		{
			to->top->prev = from->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->prev->next = to->top;
			to->top = to->top->prev;
		}
	}
	to->size++;
	from->size--;
}

/*
 * The push_stack function takes two argument, stack a and stack b,
 * For the sake of name conventions we call them "from" and "to"".
 * If the size of the from stack is zero, do nothing.
 * We add a flag so we can determine what operation to output.
 */

void	push_stack(t_stack *from, t_stack *to, int flag)
{
	if (from->size == 0)
		return ;
	push_pop(from, to);
	if (flag == A)
		ft_putendl_fd("pa", 1);
	else if (flag == B)
		ft_putendl_fd("pb", 1);
}
