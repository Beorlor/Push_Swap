#include "ft.h"

void ra(t_node **a)
{
    t_node *tmp;

    write(1, "ra\n", 3);
    if (!*a || !(*a)->next)
        return;

    tmp = *a;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = *a;
    (*a)->prev = tmp;
    *a = (*a)->next;
    (*a)->prev->next = NULL;
    (*a)->prev = NULL;
}

void rb(t_node **b)
{
    t_node *tmp;

    write(1, "rb\n", 3);
    if (!*b || !(*b)->next)
        return;

    tmp = *b;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = *b;
    (*b)->prev = tmp;
    *b = (*b)->next;
    (*b)->prev->next = NULL;
    (*b)->prev = NULL;
}

void rr(t_node **a, t_node **b)
{
    write(1, "rr\n", 3);
    ra(a);
    rb(b);
}
