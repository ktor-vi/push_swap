/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:11:02 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/14 13:02:47 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_numeric(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != NULL)
	{
		if (invalid_number(s[i]))
			free_err(s);
		while (s[i][j] != '\0')
		{
			if (!c_is_numeric(s[i][j]) || check_limit(s[i])
				|| ft_strlen(s[i]) >= 20)
				free_err(s);
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_empty(char **s)
{
	if (!s[0])
	{
		exit(0);
	}
}

void	handle_duplicates(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	check_empty(s);
	while (s[i] != NULL)
	{
		while (s[j] != NULL)
		{
			if (strncmp(s[i], s[j], INT_MAX) == 0)
				free_err(s);
			j++;
		}
		i++;
		j = i + 1;
	}
}
char *total_cat(int argc, int i, char **argv)
{
	char	*total;

	total = NULL;
	while (++i < argc)
	{
		total = strjoin(total, argv[i]);
		if(total == NULL)
			free_total(total);
		total = strjoin(total, " ");
		if(total == NULL)
			free_total(total);
	}
return (total);
}

t_node	*init_stack(int argc, char **argv, t_node *lst)
{
	int		i;
	int		k;
	char	**splitted;
	char	*total;

	i = 0;
	k = -1;

	total = total_cat(argc, i, argv);
	splitted = ft_split(total, ' ');
	free(total);
	handle_numeric(splitted);
	handle_duplicates(splitted);
	i = -1;
	while (splitted[++i] != NULL)
		appendnode(&lst, newnode(ft_atoi(splitted[i])));
	while (splitted[++k] != NULL)
		free(splitted[k]);
	free(splitted);
	return (lst);
}
