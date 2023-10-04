/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:08:59 by acan              #+#    #+#             */
/*   Updated: 2023/10/04 23:53:54 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack **mystack)
{
	t_stack	*tmp;

	tmp = (*mystack);
	while (tmp)
	{
		printf ("%d -->%d\n", tmp -> index, tmp ->content);
		tmp = tmp ->next;
	}
}

void	print_lists(t_stack **mystack)
{
	t_stack	*tmp;

	tmp = (*mystack);
	while (tmp)
	{
		printf ("%d -->%d\n", tmp -> index, tmp->cost);
		tmp = tmp ->next;
	}
}

int	main(int ac, char **av)
{
	char		**last;
	t_stack		**a;
	t_stack		**b;

	a = malloc (sizeof (t_stack *));
	b = malloc (sizeof (t_stack *));
	if (ac < 2)
		print_error ("Not enough arguments\n");
	isvalid1(ac, av);
	last = seperate_all(av);
	if (arglen(last) < 2)
		print_error ("Not enough arguments\n");
	addtostack(last, a);
	if (!(islistsorted(a)))
		exit(0);
	else
	{
		setrr(a);
		basicsort(a,b);
	}
}
