/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:01 by acan              #+#    #+#             */
/*   Updated: 2023/09/28 16:13:56 by acan             ###   ########.fr       */
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
		if (((result * sign) > 2147483647) || ((result * sign) < -2147483648))
		{
			print_error("Value is not inside integer limits\n");
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
