/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:10:17 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/08 18:10:57 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*newnode(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*lastnode(t_node *lst)
{
	t_node	*ptr;

	ptr = lst;
	if (ptr == NULL)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	appendnode(t_node **lst, t_node *new)
{
	t_node	*last;

	if (new == NULL)
		return ;
	last = lastnode(*lst);
	if (last != NULL)
	{
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
}

void	prependnode(t_node **lst, t_node *new)
{
	if (new == NULL)
		return ;
	if (*lst != NULL)
	{
		(*lst)->prev = new;
		new->next = *lst;
	}
	*lst = new;
	(*lst)->prev = NULL;
}

int	lstlen(t_node *lst)
{
	struct s_node	*ptr;
	int				i;

	if (lst == NULL)
		return (0);
	ptr = lst->next;
	i = 1;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
