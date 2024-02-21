/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:33:40 by jedurand          #+#    #+#             */
/*   Updated: 2024/02/21 04:33:41 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

//*************************Argument checks****************************
static int	check_args_length(char *args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (args[0] == '+' || args[0] == '-')
	{
		i++;
		len--;
	}
	while (args[i] == '0')
		i++;
	while (args[i++])
		len++;
	return (len);
}

// Check if the arguments content only digits
static int	is_numeric(char *arg)
{
	int	i;

	if (!arg)
		return (0);
	i = -1;
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
	}
	return (1);
}

// Check if the arguments are numbers, and the length of digits
// should not be bigger than 11, as well as not smaller than 0.
int	check_args(char *args)
{
	int	len;

	len = check_args_length(args);
	if (!is_numeric(args) || len > 11 || len < 0)
		return (0);
	else
		return (1);
}

void	check_duplicated(t_node *a)
{
	int		current_value;
	t_node	*tmp;

	while (a->next)
	{
		tmp = a->next;
		current_value = a->value;
		while (tmp)
		{
			if (tmp->value == current_value)
				print_error();
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
		a = a->next;
	}
	while (a->prev)
		a = a->prev;
}
