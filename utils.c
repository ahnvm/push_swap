/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:01 by acan              #+#    #+#             */
/*   Updated: 2023/10/08 14:07:16 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countword_onearg(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

void	print_error(char *error)
{
	int	i;

	i = 0;
	while (error[i])
		write (2, &error[i++], 1);
	exit(1);
}

int	myatoi(char *str)
{
	int			count;
	int			sign;
	long long	result;
	long long	tmpcontrol;

	count = 0;
	result = 0;
	sign = 1;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		result = (result * 10) + str[count] - '0';
		tmpcontrol = result * sign;
		if ((tmpcontrol > 2147483647) || (tmpcontrol < -2147483648))
		{
			print_error("Error\n");
		}
		count++;
	}
	return (sign * result);
}

void	indexstack(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

int	getaverage(t_stack **a, int start, int end)
{
	t_stack *tmp;
	int		sum;
	
	sum = 0;
	tmp = nodeofindex(start, a);
	while (tmp->index < ft_stacklast(*a)->index && tmp->index < end)
	{
		sum += tmp->content;
		tmp = tmp->next;
	}
	return (sum/(end-start));
}