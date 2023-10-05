/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:27:30 by acan              #+#    #+#             */
/*   Updated: 2023/10/05 15:56:20 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*tmp;
	int		lastindex;

	tmp = ft_stacklast((*a));
	lastindex = ft_stacklast((*a))->index;
	ft_stacklast((*a))->next = *a;
	while ((*a))
	{
		if ((*a)->index == lastindex - 1)
		{
			(*a)->next = NULL;
			break ;
		}
		(*a) = (*a)->next;
	}
	(*a) = tmp;
	if (flag == 0)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*tmp;
	int		lastindex;

	tmp = ft_stacklast((*b));
	lastindex = ft_stacklast((*b))->index;
	ft_stacklast((*b))->next = *b;
	while ((*b))
	{
		if ((*b)->index == lastindex - 1)
		{
			(*b)->next = NULL;
			break ;
		}
		(*b) = (*b)->next;
	}
	(*b) = tmp;
	if (flag == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		rra(a, 1);
		rrb(b, 1);
		ft_putstr_fd("rrr\n", 1);
	}
}
