/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:09:42 by acan              #+#    #+#             */
/*   Updated: 2023/10/05 00:31:37 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	isvalid1(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			print_error ("Invalid argument\n");
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && (av[i][j] != ' ')
			&& av[i][j] != '-' && av[i][j] != '+')
				print_error ("Invalid argumet\n");
			if (av[i][j] == '-' || av[i][j] == '+')
				if ((av[i][j + 1] < '0' || av[i][j + 1] > '9')
				|| (av[i][j - 1] >= '0' && av[i][j - 1] <= '9'))
					print_error ("Invalid argumet\n");
			j++;
		}
		i++;
		j = 0;
	}
}

int	islistsorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
