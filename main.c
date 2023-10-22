#include "ft.h"

int	main(int argc, char *argv[])
{
	char	**str_numb;
	t_node	*a;
	t_node	*b;

	str_numb = NULL;
	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	if (argc == 2)
		str_numb = ft_split(argv[1], ' ');
	else
		str_numb = ft_format(argc, argv);
	stack_init(&a, str_numb); //2 == argc
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
