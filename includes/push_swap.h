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
#include <string.h>
#include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				above_median;
	int				price;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

// Node utils

t_node				*lastnode(t_node *lst);
void				appendnode(t_node **lst, t_node *new);
t_node				*newnode(int value);
void				prependnode(t_node **lst, t_node *new);
void				lstclear(t_node **lst);
int					lstlen(t_node *lst);
t_node				*init_stack(int argc, char **argv, t_node *lst);

// String Utils
char				*strjoin(char *s1, char *s2);
int					ft_atoi(const char *str);
int					c_is_numeric(char c);
int					invalid_number(char *s);
int					check_limit(const char *str);

// Moves
void				swap(t_node **lst);
void				sa(t_node **a);
void				sb(t_node **b);
void				push(t_node **src, t_node **dest);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				rotate(t_node **lst);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				r_rotate(t_node **lst);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

// Moves utils
void				w_rb(t_node **b, int n);
void				w_ra(t_node **a, int n);
void				w_rrb(t_node **b, int n);
void				w_rra(t_node **a, int n);
void				top_rrr(t_node **a, t_node **b, int n);
void				top_rr(t_node **a, t_node **b, int n);
void				rr_bmedian(t_node **a, t_node **b, t_node *cheapest);
void				rrr_amedian(t_node **a, t_node **b, t_node *cheapest);

// Sort Logic
void				index_list(t_node *list);
void				set_median(t_node *lst);
int					is_sorted(t_node *lst);
void				tiny_sort(t_node **a);
void				fill_b(t_node **a, t_node **b);
t_node				*find_smallest(t_node **lst);
t_node				*find_highest(t_node **lst);
void				set_target(t_node **a, t_node **b);
void				set_price(t_node **a, t_node **b);
void				prepare_push(t_node **a, t_node **b, t_node *cheapest);
t_node				*find_cheapest(t_node **b);
void				push_swap(t_node **a, t_node **b);
