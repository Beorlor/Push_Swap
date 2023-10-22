#include "ft.h"

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
}
