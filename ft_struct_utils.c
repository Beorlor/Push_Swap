#include "ft.h"

t_node	*new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_node(t_node **head, int num)
{
	t_node	*new = new_node(num);
	t_node	*curr = *head;

	if (!new)
		return;
	if (!*head)
	{
		*head = new;
		return;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	new->prev = curr;
}

t_node	*get_last_node(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	list_size(t_node *head)
{
	int	size = 0;

	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

int	stack_sorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->num > head->next->num)
			return (0);
		head = head->next;
	}
	return (1);
}
