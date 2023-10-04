/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:15:36 by acan              #+#    #+#             */
/*   Updated: 2023/10/04 15:25:58 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	movecounter(t_stack **a)
{
	t_stack	*tmp;
	long	firstmvcount;
	int		secondmvcount;

	firstmvcount = 2147483648;
	secondmvcount = -1;
	tmp = (*a);
	while (tmp)
	{
		if (tmp ->index <= ft_stacklast (*a)->index / 2 && tmp->content < getaverage(a))
			if (tmp->content < fifthbiggest(a,5))
				if (firstmvcount > tmp->index)
					firstmvcount = tmp->index;
		if (tmp ->index > ft_stacklast (*a)->index / 2 && tmp->content < getaverage(a))
			if (tmp->content < fifthbiggest(a,5))
				if (secondmvcount < tmp->index)
					secondmvcount = tmp->index;
		tmp = tmp->next;
	}
	if (firstmvcount == 2147483648)
		return (secondmvcount);
	if (firstmvcount > ft_stacklast(*a)->index-secondmvcount + 1)
		return (secondmvcount);
	else
		return (firstmvcount);
}

static int	checkmore(t_stack **a)
{
	t_stack *tmp;
	int		i;
	int		temp;

	tmp = (*a);
	i = movecounter(a);
	while (tmp)
	{
		if (tmp->index == i)
		{
			temp = tmp->content;
			if (tmp->next != NULL)
				tmp = tmp ->next;
			if (temp > tmp->content)
				i = tmp->index;
			return(i);
		}
		tmp = tmp->next;
	}
	return(i);
}

void	pushback(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		biggestindex;
	
	tmp = (*b);
	while (ft_stacklast(*b)->index >0)
	{
		biggestindex = getbiggest(b);
		if (biggestindex >= ft_stacklast(*b)->index/2)
		{
			biggestindex = ft_stacklast(*b)->index - biggestindex + 1;
			while(biggestindex--)
				rrb(b,0);
			pa(a,b);
		}
		else
		{
			while(biggestindex--)
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
		movecount = checkmore(a);
		if (movecount >= ((ft_stacklast((*a))->index) / 2))
			{
				movecount = ft_stacklast((*a))->index - checkmore(a) + 1;
				while (movecount-- > 0)
					rra(a,0);
				pb(a,b);
				sorttry(b);
			}
		else
		{
			while (movecount-- > 0)
				ra(a,0);
			pb(a,b);
			sorttry(b);
		}
	}
	sortcheck(a, b, ft_stacklast(*a)->index);
	pushback(a,b);
}
