/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:32:53 by jedurand          #+#    #+#             */
/*   Updated: 2024/02/21 06:02:20 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "push_swap.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

void	checker(t_stack *a, t_stack *b);

t_stack	*init_stack(void);
t_node	*make_stack(int argc, char **argv, t_stack **stack);

void	print_error(void);
int		check_args(char *arg);
void	check_duplicated(t_node *a);
int		my_atoi(char *arg);

void	swap_stack(t_stack *stack, int flag);
void	swap_both_stack(t_stack *a, t_stack *b, int flag);
void	push_stack(t_stack *from, t_stack *to, int flag);
void	rotate_stack(t_stack *stack, int flag);
void	rotate_both_stack(t_stack *a, t_stack *b, int flag);
void	reverse_rotate_stack(t_stack *stack, int flag);
void	reverse_rotate_both_stack(t_stack *a, t_stack *b, int flag);
t_node	*fill_stack(int argc, char **argv, t_stack **stack);

void	do_push(char *buf, t_stack *a, t_stack *b);
void	do_swap(char *buf, t_stack *a, t_stack *b);
void	do_rotate(char *buf, t_stack *a, t_stack *b);
void	do_reverse_rotate(char *buf, t_stack *a, t_stack *b);

void	free_all(t_stack *a, t_stack *b);

#endif
