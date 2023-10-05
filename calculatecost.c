/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatecost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:54:48 by acan              #+#    #+#             */
/*   Updated: 2023/10/05 14:23:29 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setrr(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index <= ft_stacklast(*stack)->index / 2)
		{
			tmp->isrr = 0;
		}
		else
		{
			tmp->isrr = 1;
		}
		tmp = tmp->next;
	}
}

t_stack	*nodeofindex(int index, t_stack **stack)
{
	t_stack	*ret;

	ret = (*stack);
	while (ret)
	{
		if (ret->index == index)
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}

void	settarget(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *a;
	tmpb = *b;
	while (tmpa)
	{
		tmpa->target_node = nodeofindex(getsmallest(b), b);
		while (tmpb)
		{
			if (tmpa->content > tmpb->content
				&& tmpa->target_node->content < tmpb->content)
				tmpa->target_node = tmpb;
			tmpb = tmpb->next;
		}
		if (tmpa->target_node->content > tmpa->content)
			tmpa->target_node = nodeofindex(getbiggest(b), b);
		tmpb = *b;
		tmpa = tmpa->next;
	}
}

void	setcost(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *a;
	tmpb = *b;
	while (tmpa)
	{
		if (tmpa->isrr == 0)
			tmpa->cost = tmpa->index;
		else
			tmpa->cost = ft_stacklast(tmpa)->index - tmpa->index + 1;
		tmpa = tmpa->next;
	}
	if (!tmpb)
		return ;
	while (tmpb)
	{
		if (tmpb->isrr == 0)
			tmpb->cost = tmpb->index;
		else
			tmpb->cost = ft_stacklast(tmpb)->index - tmpb->index + 1;
		tmpb = tmpb->next;
	}
}

t_stack	*calculatecost(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*ret;

	tmp = *a;
	ret = tmp;
	while (tmp)
	{
		if ((tmp->cost + tmp->target_node->cost) < (ret->cost
				+ ret->target_node->cost))
			ret = tmp;
		else if ((tmp->cost + tmp->target_node->cost) == (ret->cost
				+ ret->target_node->cost))
			if (tmp->isrr == tmp->target_node->isrr)
				ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}
