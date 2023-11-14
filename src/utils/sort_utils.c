/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:03:34 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/13 11:03:37 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	index_list(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->index = i;
		i++;
		lst = lst->next;
	}
}

void	set_median(t_node *lst)
{
	int	median;

	median = lstlen(lst) / 2;
	while (lst)
	{
		if (lst->index <= median - 1)
			lst->above_median = 0;
		else
			lst->above_median = 1;
		lst = lst->next;
	}
}

int	is_sorted(t_node *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_node	*find_smallest(t_node **lst)
{
	t_node	*smallest;
	t_node	*tick_lst;

	tick_lst = *lst;
	smallest = *lst;
	while (tick_lst)
	{
		if ((tick_lst)->value < smallest->value)
			smallest = tick_lst;
		tick_lst = (tick_lst)->next;
	}
	return (smallest);
}

t_node	*find_highest(t_node **lst)
{
	t_node	*highest;

	highest = *lst;
	while (*lst)
	{
		if ((*lst)->value > highest->value)
			highest = *lst;
		*lst = (*lst)->next;
	}
	return (highest);
}
