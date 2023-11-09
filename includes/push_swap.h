/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:12:15 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/08 18:12:17 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

// node utils

t_node				*lastnode(t_node *lst);
void				appendnode(t_node **lst, t_node *new);
t_node				*newnode(int value);
void				prependnode(t_node **lst, t_node *new);
int					lstlen(t_node *lst);
t_node				*init_stack(int argc, char **argv, t_node *lst);

char				*strjoin(char *s1, char *s2);
int					ft_atoi(const char *str);
int					c_is_numeric(char c);
int					check_limit(const char *str);
void				swap(t_node **lst);
void				sa(t_node **a);
void				sb(t_node **b);
void				push(t_node **src, t_node **dest);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				rotate(t_node **lst);
void				ft_print_list(t_node *list);
void				ft_print_list_reverse(t_node *list);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				r_rotate(t_node **lst);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

