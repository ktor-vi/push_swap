/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:11:02 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/08 18:12:35 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_numeric(char **s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = -1;
	while (s[i] != NULL)
	{
		while (s[i][j])
		{
			if (!c_is_numeric(*s[i]) || check_limit(s[i])
				|| ft_strlen(s[i]) >= 20)
			{
				while (s[k++] != NULL)
					free(s[k]);
				free(s);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	handle_duplicates(char **s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = -1;
	while (s[i] != NULL)
	{
		while (s[j] != NULL)
		{
			if (ft_strncmp(s[i], s[j], ft_strlen((const char *)s[i])) == 0)
			{
				while (s[k++] != NULL)
					free(s[k]);
				free(s);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

t_node	*init_stack(int argc, char **argv, t_node *lst)
{
	int		i;
	int		k;
	char	*total;
	char	**splitted;

	total = NULL;
	i = 0;
	k = -1;
	while (++i < argc)
	{
		total = strjoin(total, argv[i]);
		total = strjoin(total, " ");
	}
	splitted = ft_split(total, ' ');
	free(total);
	handle_numeric(splitted);
	handle_duplicates(splitted);
	i = -1;
	while (splitted[++i] != NULL)
		appendnode(&lst, newnode(ft_atoi(splitted[i])));
	while (splitted[k++] != NULL)
		free(splitted[k]);
	free(splitted);
	return (lst);
}
