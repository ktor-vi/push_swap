/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:04:00 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/13 11:04:01 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_node **lst)
{
	t_node	*temp;
	t_node	*last;
	int		ll;

	ll = lstlen(*lst);
	temp = *lst;
	*lst = (*lst)->next;
	last = lastnode(*lst);
	if (ll == 1)
		return ;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	(*lst)->prev = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
