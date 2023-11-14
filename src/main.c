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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		lstclear(&a);
		return (0);
	}
	a = init_stack(argc, argv, a);
	if (is_sorted(a))
	{
		lstclear(&a);
		exit(0);
	}
	push_swap(&a, &b);
	lstclear(&a);
	return (0);
}
