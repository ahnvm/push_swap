/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:08:59 by acan              #+#    #+#             */
/*   Updated: 2023/10/08 14:54:19 by acan             ###   ########.fr       */
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
	addtostack(last, a);
	if (!(islistsorted(a)))
		exit (0);
	else if (ft_stacklast(*a)->index < 5)
		sortcheck(a, b, ft_stacklast(*a)->index);
	else
	{
		// printf("%d -> %d -> %d\n",getaverage(a,0,150), getaverage(a,150,350), getaverage(a,350,500));
		setrr(a);
		basicsort(a, b);
	}
}
