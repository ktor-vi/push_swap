#include "../includes/push_swap.h"

void r_rotate(t_node **lst)
{
    t_node *last;

    last = lastnode(*lst);
    last->prev->next = NULL;
    last->prev = NULL;
    prependnode(lst, last);
}

void rra(t_node **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void rrb(t_node **b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
}

void rrr(t_node **a, t_node **b)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rrr\n", 4);
}
