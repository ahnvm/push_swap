/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:08:59 by acan              #+#    #+#             */
/*   Updated: 2023/10/05 05:28:01 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**last;
	t_stack	**a;
	t_stack	**b;

	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	if (ac < 2)
		print_error("Error\n");
	isvalid1(ac, av);
	last = seperate_all(av);
	if (!last[0])
		print_error("Error\n");
	if (arglen(last) == 1)
		return (myatoi(last[0]) - myatoi(last[0]));
	isvalid1(arglen(last) - 1, av);
	addtostack(last, a);
	if (!(islistsorted(a)))
		print_error("Error\n");
	else if (ft_stacklast(*a)->index < 5)
		sortcheck(a, b, ft_stacklast(*a)->index);
	else
	{
		setrr(a);
		basicsort(a, b);
	}
}
