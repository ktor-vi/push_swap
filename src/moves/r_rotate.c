/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:03:54 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/13 11:03:57 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r_rotate(t_node **lst)
{
	t_node	*last;
	int		ll;

	ll = lstlen(*lst);
	last = lastnode(*lst);
	if (ll == 1)
		return ;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	prependnode(lst, last);
}

void	rra(t_node **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rrr\n", 4);
}
