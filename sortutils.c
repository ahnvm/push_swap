/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:48:49 by acan              #+#    #+#             */
/*   Updated: 2023/10/08 15:00:35 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getbiggest(t_stack **b)
{
	t_stack	*tmp;
	int		retindex;
	int		tmpbiggest;

	tmp = (*b);
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

int	getsmallest(t_stack **b)
{
	t_stack	*tmp;
	int		retindex;
	int		tmpsmallest;

	tmp = (*b);
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

void	firstsendsmall(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tosend;

	tmp = *a;
	tosend = *a;
	while (tmp->index < 20)
	{
		if (tmp->content < tosend->content)
			tosend = tmp;
		tmp = tmp->next;
	}
	tmp = nodeofindex(ft_stacklast(*a)->index - 20, a);
	while (tmp)
	{
		if (tmp->content < tosend->content)
			tosend = tmp;
		tmp = tmp->next;
	}
	while (tosend->isrr == 0 && (tosend->cost) > 0)
	{
		ra(a, 0);
		tosend->cost--;
	}
	while (tosend->isrr == 1 && (tosend->cost) > 0)
	{
		rra(a, 0);
		tosend->cost--;
	}
	pb(a, b);
}

static void	firstsendbig(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tosend;

	tmp = *a;
	tosend = *a;
	while (tmp->index < 10)
	{
		if (tmp->content > tosend->content)
			tosend = tmp;
		tmp = tmp->next;
	}
	tmp = nodeofindex(ft_stacklast(*a)->index - 10, a);
	while (tmp)
	{
		if (tmp->content > tosend->content)
			tosend = tmp;
		tmp = tmp->next;
	}
	while (tosend->isrr == 0 && (tosend->cost) > 0)
	{
		ra(a, 0);
		tosend->cost--;
	}
	while (tosend->isrr == 1 && (tosend->cost) > 0)
	{
		rra(a, 0);
		tosend->cost--;
	}
	pb(a, b);
}

void	firstsends(t_stack **a, t_stack **b, int first, int second)
{
	if (getaverage(a, first, second) > getaverage(a, 0, first) && getaverage(a,
			second, ft_stacklast(*a)->index) < getaverage(a, first,second))
		{
			pb(a,b);
			pb(a,b);
		}
	else if (getaverage(a, 0, first) > getaverage(a, first, second)
			&& getaverage(a, second, ft_stacklast(*a)->index) < getaverage(a,
				first, second))
		{
			pb(a,b);
			pb(a,b);
		}
	else
		{
			firstsendsmall(a, b);
			firstsendsmall(a, b);
		}
}
