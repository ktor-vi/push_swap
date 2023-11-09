/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:10:13 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/08 18:12:41 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_node *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("node %d : %d\n", i, list->value);
		i++;
		list = list->next;
	}
}

void	ft_print_list_reverse(t_node *list)
{
	int		i;
	t_node	*last;

	i = lstlen(list);
	last = lastnode(list);
	while (last)
	{
		printf("node %d : %d\n", i, last->value);
		i--;
		last = last->prev;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char *b_values[4] = {NULL, "3", "2", "1"};
	a = NULL;
	b = NULL;
	a = init_stack(argc, argv, a);
	b = init_stack(4, b_values, b);
	printf("a :\n");
	ft_print_list(a);
	printf("b :\n");
	ft_print_list(b);
	write(1, "\n", 1);
	rra(&a);
	rrb(&b);
	printf("a :\n");
	ft_print_list(a);
	printf("b :\n");
	ft_print_list(b);
	// system("leaks push_swap");
	exit(0);
}
