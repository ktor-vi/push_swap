/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:08:46 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/13 15:08:48 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*find_cheapest(t_node **b)
{
	t_node	*tick_b;
	t_node	*cheapest;

	tick_b = *b;
	cheapest = tick_b;
	while (tick_b)
	{
		if (tick_b->price < cheapest->price)
			cheapest = tick_b;
		tick_b = tick_b->next;
	}
	return (cheapest);
}

void	prepare_push(t_node **a, t_node **b, t_node *cheapest)
{
	int	la;
	int	lb;

	la = lstlen(*a);
	lb = lstlen(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rrr_amedian(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		rr_bmedian(a, b, cheapest);
	else if (!cheapest->above_median && cheapest->target_node->above_median)
	{
		w_rb(b, cheapest->index);
		w_rra(a, la - cheapest->target_node->index);
	}
	else if (cheapest->above_median && !cheapest->target_node->above_median)
	{
		w_rrb(b, lb - cheapest->index);
		w_ra(a, cheapest->target_node->index);
	}
}

void	hoist(t_node **a)
{
	t_node	*smallest;
	int		la;

	la = lstlen(*a);
	index_list(*a);
	set_median(*a);
	smallest = find_smallest(a);
	if (smallest->index == 0)
		return ;
	else
	{
		if (smallest->above_median)
			w_rra(a, la - smallest->index);
		else
			w_ra(a, smallest->index);
	}
}

void	push_swap(t_node **a, t_node **b)
{
	int	i;
	int	lb;
	int	la;

	i = 0;
	fill_b(a, b);
	lb = lstlen(*b);
	la = lstlen(*a);
	if (la == 1)
		return ;
	tiny_sort(a);
	while (i < lb)
	{
		index_list(*a);
		index_list(*b);
		set_median(*a);
		set_median(*b);
		set_target(a, b);
		set_price(a, b);
		prepare_push(a, b, find_cheapest(b));
		pa(a, b);
		i++;
	}
	hoist(a);
}
