/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:48:49 by acan              #+#    #+#             */
/*   Updated: 2023/10/08 18:29:45 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getbiggest(t_stack **stack)
{
	t_stack	*tmp;
	int		retindex;
	int		tmpbiggest;

	tmp = (*stack);
	retindex = tmp->index;
	tmpbiggest = tmp->content;
	while (tmp)
	{
		if (tmp->content > tmpbiggest)
		{
			tmpbiggest = tmp->content;
			retindex = tmp->index;
		}
		tmp = tmp->next;
	}
	return (retindex);
}

int	getsmallest(t_stack **stack)
{
	t_stack	*tmp;
	int		retindex;
	int		tmpsmallest;

	tmp = (*stack);
	retindex = tmp->index;
	tmpsmallest = tmp->content;
	while (tmp)
	{
		if (tmp->content < tmpsmallest)
		{
			tmpsmallest = tmp->content;
			retindex = tmp->index;
		}
		tmp = tmp->next;
	}
	return (retindex);
}

t_stack	*recheckcost(t_stack **a, t_stack *node, t_stack *target)
{
	int totalmove;
	t_stack *tmp;
	int newmove;

	totalmove = node->cost + target->cost;
	tmp = *a;
	newmove = 0;
	while (tmp)
	{
		if (tmp->isrr == node->isrr && tmp->content < node->content
			&& tmp->content > target->content)
		{
			if (tmp->cost > target->cost)
				newmove = tmp->cost;
			else
				newmove = target->cost;
			if (newmove < totalmove)
			{
				tmp->target_node = target;
				return (tmp);
			}
		}
		tmp = tmp->next;
	}
	return (node);
}
