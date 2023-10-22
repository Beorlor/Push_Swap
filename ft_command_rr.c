#include "ft.h"

void rra(t_node **a)
{
    t_node *tmp;

    write(1, "rra\n", 4);
    if (!*a || !(*a)->next)
        return;

    tmp = *a;
    while (tmp->next)
        tmp = tmp->next;

    tmp->prev->next = NULL;
    tmp->next = *a;
    (*a)->prev = tmp;
    *a = tmp;
    tmp->prev = NULL;
}

void rrb(t_node **b)
{
    t_node *tmp;

    write(1, "rrb\n", 4);
    if (!*b || !(*b)->next)
        return;

    tmp = *b;
    while (tmp->next)
        tmp = tmp->next;

    tmp->prev->next = NULL;
    tmp->next = *b;
    (*b)->prev = tmp;
    *b = tmp;
    tmp->prev = NULL;
}

void rrr(t_node **a, t_node **b)
{
    write(1, "rrr\n", 4);
    rra(a);
    rrb(b);
}
