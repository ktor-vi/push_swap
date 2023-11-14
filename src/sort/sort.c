/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:03:43 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/13 15:08:51 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	tiny_sort(t_node **a)
{
	t_node	*last;

	last = lastnode(*a);
	if ((*a)->value > (*a)->next->value && (*a)->value > last->value)
		ra(a);
	else if ((*a)->next->value > (*a)->value && (*a)->next->value > last->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	fill_b(t_node **a, t_node **b)
{
	while (lstlen(*a) > 3)
	{
		pb(a, b);
	}
}

void	set_target(t_node **a, t_node **b)
{
	t_node	*tick_a;
	t_node	*tick_b;
	long		target_val;

	tick_b = *b;
	while (tick_b)
	{
		target_val = LONG_MAX;
		tick_a = *a;
		while (tick_a)
		{
			if (tick_a->value > tick_b->value && tick_a->value < target_val)
			{
				target_val = (long)tick_a->value;
				tick_b->target_node = tick_a;
			}
			tick_a = tick_a->next;
		}
		if (target_val == LONG_MAX)
			tick_b->target_node = find_smallest(a);
		tick_b = tick_b->next;
	}
}

void	set_price(t_node **a, t_node **b)
{
	int		la;
	int		lb;
	t_node	*tick_b;

	la = lstlen(*a);
	lb = lstlen(*b);
	tick_b = *b;
	while (tick_b)
	{
		if (tick_b->above_median && tick_b->target_node->above_median)
			tick_b->price = lb - tick_b->index + la
				- tick_b->target_node->index;
		else if (!tick_b->above_median && !tick_b->target_node->above_median)
			tick_b->price = tick_b->index + tick_b->target_node->index;
		else if (!tick_b->above_median && tick_b->target_node->above_median)
			tick_b->price = tick_b->index + (la - tick_b->target_node->index);
		else if (tick_b->above_median && !tick_b->target_node->above_median)
			tick_b->price = (lb - tick_b->index) + tick_b->target_node->index;
		tick_b = tick_b->next;
	}
}

void	five_sort(t_node**a, t_node **b)
{
	while (lstlen(*a) > 3)
	{
		t_node *top;

		index_list(*a);
		index_list(*b);
		set_median(*a);
		set_median(*b);

		top = find_smallest(a);
		while ((*a)->value != top->value)
		{
				if (top->above_median)
					rra(a);
				else
					ra(a);
		}
		pb(a, b);
	}
}
