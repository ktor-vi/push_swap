/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:11:47 by vphilipp          #+#    #+#             */
/*   Updated: 2023/11/08 18:11:49 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;
	size_t	l1;
	size_t	l2;

	i = -1;
	j = -1;
	l1 = ft_strlen((const char *)s1);
	l2 = ft_strlen((const char *)s2);
	res = malloc(l1 + l2 + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while (++i < l1)
		res[i] = s1[i];
	while (++j < l2)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	if (s1)
		free(s1);
	return (res);
}

int	c_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	check_limit(const char *str)
{
	long long int	result;
	int				i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!c_is_numeric(str[i]))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result > INT_MAX || result < INT_MIN)
			return (1);
	}
	return (0);
}
