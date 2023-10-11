/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortshort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:32:32 by acan              #+#    #+#             */
/*   Updated: 2023/10/11 16:12:41 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sortthree(t_stack **a)
{
	if (!(islistsorted(a)))
		return ;
	if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
	{
		ra(a, 0);
		sa(a, 0);
		indexstack(*a);
		rra(a, 0);
	}
	else if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content > (*a)->next->next->content)
		{
			sa(a, 0);
			rra(a, 0);
		}
		else if ((*a)->content < (*a)->next->next->content)
			sa(a, 0);
		else if ((*a)->content > (*a)->next->next->content)
			ra(a, 0);
	}
	else
		rra(a, 0);
}

static void	sortfour(t_stack **a, t_stack **b, int smallest)
{
	if (!(islistsorted(a)))
		return ;
	if (smallest > ft_stacklast(*a)->index / 2)
	{
		smallest = ft_stacklast(*a)->index - smallest + 1;
		while (smallest)
		{
			rra(a, 0);
			smallest--;
		}
	}
	else
	{
		while (smallest)
		{
			ra(a, 0);
			smallest--;
		}
	}
	pb(a, b);
	sortthree(a);
	pa(a, b);
}

static void	sortfive(t_stack **a, t_stack **b, int smallest)
{
	if (smallest > 3)
	{
		while (smallest++ < ft_stacklast((*a))->index + 1)
			rra(a, 0);
	}
	else
	{
		while (smallest)
		{
			ra(a, 0);
			smallest--;
		}
	}
	pb(a, b);
	sortfour(a, b, getsmallest(a));
	pa(a, b);
}

void	sortcheck(t_stack **a, t_stack **b, int len)
{
	if (len == 1)
		sa(a, 0);
	if (len == 2)
		sortthree(a);
	if (len == 3)
		sortfour(a, b, getsmallest(a));
	if (len == 4)
		sortfive(a, b, getsmallest(a));
}
