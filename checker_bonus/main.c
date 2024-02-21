/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:32:44 by jedurand          #+#    #+#             */
/*   Updated: 2024/02/21 04:32:46 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

/*
 * Declare the stacks and take the arguments,
 * if no argument is given return an error message.
 * while there is an argument left init the stack a,
 * and fill it with the arguments.
 */

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
		checker(a, b);
		free_all(a, b);
	}
}
