#include "ft.h"

void free_str_numb(char **str_numb)
{
	char **temp = str_numb;

	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(str_numb);
}

void	free_nodes(t_node **lst)
{
	t_node	*head;
	t_node	*tmp;

	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*lst = NULL;
}
