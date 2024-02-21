/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:34:06 by jedurand          #+#    #+#             */
/*   Updated: 2024/02/21 04:34:08 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Swap the stack, aka (SA, SB).
 * These functions operate only if the stack contains
 * more than one node.
 *
 *	/===============\
 *	|	   tmp		|<----tmp
 *	|_______________|
 *	|	top->next	|<----top_next
 *	|				|
 *	\===============/
 *
 */
void	swap_stack(t_stack *stack, int flag)
{
	t_node	*tmp;
	t_node	*top_next;

	if (stack->size < 2)
		return ;
	top_next = stack->top->next;
	tmp = stack->top;
	if (stack->size > 2)
		top_next->next->prev = stack->top;
	tmp->next = top_next->next;
	stack->top = top_next;
	stack->top->prev = NULL;
	stack->top->next = tmp;
	tmp->prev = stack->top;
	if (stack->size == 2)
		stack->bottom = stack->top->next;
	if (flag == A)
		ft_putendl_fd("sa", 1);
	else if (flag == B)
		ft_putendl_fd("sb", 1);
}

// Apply the above function to both the stacks, aka (SS)
void	swap_both_stack(t_stack *a, t_stack *b, int flag)
{
	swap_stack(a, flag);
	swap_stack(b, flag);
	if (flag == ALL)
		ft_putendl_fd("ss", 1);
}
