#include "../includes/push_swap.h"

void	rotate(t_node **lst)
{
	t_node	*temp;
	t_node	*last;

	temp = *lst;
	*lst = (*lst)->next;
	last = lastnode(*lst);
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	(*lst)->prev = NULL;
}

void ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
