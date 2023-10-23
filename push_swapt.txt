#include "ft.h"

#include "ft.h"

int get_max_digit(t_node *list)
{
    int max;
    int count;

    max = 0;
    count = 0;
    while (list)
    {
        if (list->index > max)
            max = list->index;
        list = list->next;
    }
    while (max)
    {
        count++;
        max /= 10;
    }
    return (count);
}

int get_digit(int number, int position)
{
    while (position--)
        number /= 10;
    return (number % 10);
}

void move_from_a_to_b_based_on_digit(t_node **a, t_node **b, int position, int digit)
{
    int len = list_size(*a);
    for (int i = 0; i < len; i++)
    {
        if (get_digit((*a)->index, position) == digit)
            pb(a, b);
        else
            ra(a);
    }
}

void move_from_b_to_a_based_on_digit(t_node **a, t_node **b, int position, int digit)
{
    int len = list_size(*b);
    for (int i = 0; i < len; i++)
    {
        if (get_digit((*b)->index, position) == digit)
            pa(a, b);
        else
            rb(b);
    }
}

void radix_sort(t_node **a, t_node **b)
{
    int max_digit = get_max_digit(*a);

    for (int position = 0; position < max_digit; position++)
    {
        for (int d = 0; d < 10; d++)
        {
            if (position % 2 == 0)
                move_from_a_to_b_based_on_digit(a, b, position, d);
            else
                move_from_b_to_a_based_on_digit(a, b, position, d);
        }
    }

    // If at the end stack 'a' is empty, move everything back to 'a' from 'b'
    if (!*a)
    {
        while (*b)
        {
            rrb(b);  // Reverse rotate b.
            pa(a, b);
        }
    }
}

