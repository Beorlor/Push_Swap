/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:30:13 by jedurand          #+#    #+#             */
/*   Updated: 2024/02/21 04:30:17 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* I use a special kind of atoi, therefore I'll implement
 * my_atoi function which will handle some error cases.
 */
int	my_atoi(char *args)
{
	int			i;
	int			sign;
	long long	value;

	if (!check_args(args))
		print_error();
	i = 0;
	sign = 1;
	value = 0;
	if (args[i] == '+' || args[i] == '-')
	{
		if (args[i++] == '-')
			sign = -1;
	}
	while (args[i])
		value = value * 10 + (args[i++] - '0');
	value = value * sign;
	if (value > MAX_INT || value < MIN_INT)
		print_error();
	return (value);
}
