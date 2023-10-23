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
		if (list_size(a) == 2)
			sa(&a);
		else if (list_size(a) == 3)
			three_sort(&a);
		else if (list_size(a) <= 5)
			five_sort(&a, &b);
		else
			radix_sort(&a, &b);
	}
	while (a)
	{
		printf("%d ", a->index);
		a = a->next;
	}
	free_nodes(&a);
}
