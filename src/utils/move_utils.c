/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:09:15 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/13 15:09:16 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	top_rrr(t_node **a, t_node **b, int n)
{
	while (n > 0)
	{
		rrr(a, b);
		n--;
	}
}

void	top_rr(t_node **a, t_node **b, int n)
{
	while (n > 0)
	{
		rr(a, b);
		n--;
	}
}

void	rr_bmedian(t_node **a, t_node **b, t_node *cheapest)
{
	if (cheapest->index > cheapest->target_node->index)
	{
		top_rr(a, b, cheapest->target_node->index);
		w_rb(b, cheapest->index - cheapest->target_node->index);
	}
	else if (cheapest->index <= cheapest->target_node->index)
	{
		top_rr(a, b, cheapest->index);
		w_ra(a, cheapest->target_node->index - cheapest->index);
	}
}

void	rrr_amedian(t_node **a, t_node **b, t_node *cheapest)
{
	int	la;
	int	lb;

	la = lstlen(*a);
	lb = lstlen(*b);
	if (lb - cheapest->index > la - cheapest->target_node->index)
	{
		top_rrr(a, b, la - cheapest->target_node->index);
		w_rrb(b, (lb - cheapest->index) - (la - cheapest->target_node->index));
	}
	else if (lb - cheapest->index <= la - cheapest->target_node->index)
	{
		top_rrr(a, b, lb - cheapest->index);
		w_rra(a, (la - cheapest->target_node->index) - (lb - cheapest->index));
	}
}
