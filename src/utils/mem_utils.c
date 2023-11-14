/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:03:23 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/13 11:03:26 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	lstclear(t_node **lst)
{
	t_node	*tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	free_total(char *s) {
	free(s);
	write(2, "Error\n", 6);
	exit(0);
}

void	free_err(char **s)
{
	int	k;

	k = -1;
	if (s || *s)
	{
	while (s[++k] != NULL)
		free(s[k]);
	free(s);
	write(2, "Error\n", 6);
	}
	exit(0);
}


