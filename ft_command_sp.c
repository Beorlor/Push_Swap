#include "ft.h"

void sa(t_node **a)
{
    t_node *tmp;

    write(1, "sa\n", 3);
    if (!*a || !(*a)->next)
        return;

    tmp = *a;
    *a = (*a)->next;
    tmp->next = (*a)->next;
    (*a)->next = tmp;
    tmp->prev = *a;
    if (tmp->next)
        tmp->next->prev = tmp;
}

void sb(t_node **b)
{
    t_node *tmp;

    write(1, "sb\n", 3);
    if (!*b || !(*b)->next)
        return;

    tmp = *b;
    *b = (*b)->next;
    tmp->next = (*b)->next;
    (*b)->next = tmp;
    tmp->prev = *b;
    if (tmp->next)
        tmp->next->prev = tmp;
}

void ss(t_node **a, t_node **b)
{
    write(1, "ss\n", 3);
    sa(a);
    sb(b);
}

void pa(t_node **a, t_node **b)
{
    t_node *tmp;

    write(1, "pa\n", 3);
    if (!*b)
        return;

    tmp = *b;
    *b = (*b)->next;
    if (*b)
        (*b)->prev = NULL;

    tmp->next = *a;
    if (*a)
        (*a)->prev = tmp;
    *a = tmp;
}

void pb(t_node **a, t_node **b)
{
    t_node *tmp;

    write(1, "pb\n", 3);
    if (!*a)
        return;

    tmp = *a;
    *a = (*a)->next;
    if (*a)
        (*a)->prev = NULL;

    tmp->next = *b;
    if (*b)
        (*b)->prev = tmp;
    *b = tmp;
}
