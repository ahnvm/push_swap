/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:15:36 by acan              #+#    #+#             */
/*   Updated: 2023/10/08 18:30:15 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mixedrotate(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost && node->isrr == 1)
	{
		rra(a, 0);
		node->cost--;
	}
	while (node->cost && node->isrr == 0)
	{
		ra(a, 0);
		node->cost--;
	}
	while (node->target_node->cost && node->target_node->isrr == 1)
	{
		rrb(b, 0);
		node->target_node->cost--;
	}
	while (node->target_node->cost && node->target_node->isrr == 0)
	{
		rb(b, 0);
		node->target_node->cost--;
	}
}

void	revrotatestack(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost && node->target_node->cost)
	{
		rrr(a, b);
		node->cost--;
		node->target_node->cost--;
	}
	while (node->cost)
	{
		rra(a, 0);
		node->cost--;
	}
	while (node->target_node->cost)
	{
		rrb(b, 0);
		node->target_node->cost--;
	}
}

void	rotatestack(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost && node->target_node->cost)
	{
		rr(a, b);
		node->cost--;
		node->target_node->cost--;
	}
	while (node->cost)
	{
		ra(a, 0);
		node->cost--;
	}
	while (node->target_node->cost)
	{
		rb(b, 0);
		node->target_node->cost--;
	}
}

void	lastsort(t_stack **a, t_stack **b)
{
	while (nodeofindex(getbiggest(b), b)->cost)
	{
		if (nodeofindex(getbiggest(b), b)->isrr == 1)
			rrb(b, 0);
		else
			rb(b, 0);
		nodeofindex(getbiggest(b), b)->cost--;
	}
	while (*b)
		pa(a, b);
}

void	basicsort(t_stack **a, t_stack **b)
{
	t_stack	*ret;

	pb (a,b);
	pb (a,b);
	while (*a)
	{
		settarget(a, b);
		ret = calculatecost(a);
		if (ret->isrr != ret->target_node->isrr)
		{
			if (ret->isrr != ret->target_node->isrr)
				mixedrotate(a, b, ret);
		}
		if (ret->isrr == ret->target_node->isrr)
		{
			if (ret->isrr == 0)
				rotatestack(a, b, ret);
			else
				revrotatestack(a, b, ret);
		}
		pb(a, b);
	}
	lastsort(a, b);
}
