/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:57:29 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/13 11:04:06 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **lst)
{
	t_node	*temp;

	temp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	(*lst)->next->prev = *lst;
	prependnode(lst, temp);
	(*lst)->prev = NULL;
}

void	sa(t_node **a)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}
