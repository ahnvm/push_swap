/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:15:36 by acan              #+#    #+#             */
/*   Updated: 2023/09/30 13:46:16 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	movecounter(t_stack **a)
{
	t_stack	*tmp;
	int		firstmvcount;
	int		secondmvcount;

	firstmvcount = -1;
	secondmvcount = -1;
	tmp = (*a);
	while (tmp)
	{
		if (tmp ->index <= ft_stacklast (*a)->index / 2)
			if (tmp->content < fifthbiggest(a,5))
				if (firstmvcount > tmp->index)
					firstmvcount = tmp->index;
		if (tmp ->index > ft_stacklast (*a)->index / 2)
			if (tmp->content < fifthbiggest(a,5))
				if (secondmvcount < tmp->index)
					secondmvcount = tmp->index;
		tmp = tmp->next;
	}
	if (firstmvcount == -1)
		return (secondmvcount);
	if (firstmvcount > secondmvcount-(ft_stacklast((*a))->index) + 1)
		return (secondmvcount);
	else
		return (firstmvcount);
}

void	pushback(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		biggestindex;
	
	tmp = (*b);
	while (ft_stacklast(*b)->index >0)
	{
		biggestindex = getbiggest(b) + 1;
		if (biggestindex > ft_stacklast(*b)->index/2)
		{
			while(--biggestindex)
				rrb(b,0);
			pa(a,b);
		}
		else
		{
			while(--biggestindex)
				rb(b,0);
			pa(a,b);
		}
	}
	pa(a,b);
}

void	basicsort(t_stack **a, t_stack **b)
{
	int	movecount;

	while (ft_stacklast(*a) -> index >4)
	{
		movecount = movecounter(a) + 1;
		if (movecount > ((ft_stacklast((*a))->index) / 2))
			{
				movecount = ft_stacklast((*a))->index - movecounter(a) + 2;
				while (--movecount > 0)
					rra(a,0);
				pb(a,b);
			}
		else
		{
			while (--movecount > 0)
				ra(a,0);
			pb(a,b);
		}
	}
	sortcheck(a, b, ft_stacklast(*a)->index);
	pushback(a,b);
}
