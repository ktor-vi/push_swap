/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:08:58 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/13 15:08:59 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	w_rb(t_node **b, int n)
{
	while (n > 0)
	{
		rb(b);
		n--;
	}
}

void	w_ra(t_node **a, int n)
{
	while (n > 0)
	{
		ra(a);
		n--;
	}
}

void	w_rrb(t_node **b, int n)
{
	while (n > 0)
	{
		rrb(b);
		n--;
	}
}

void	w_rra(t_node **a, int n)
{
	while (n > 0)
	{
		rra(a);
		n--;
	}
}
