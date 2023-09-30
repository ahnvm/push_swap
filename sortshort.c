/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortshort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:32:32 by acan              #+#    #+#             */
/*   Updated: 2023/09/30 14:18:25 by acan             ###   ########.fr       */
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
		rra(a, 0);
	}
	else if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content > (*a)->next ->next->content)
		{
			sa (a, 0);
			rra (a, 0);
		}
		else if ((*a)->content < (*a)->next->next->content)
			sa (a, 0);
		else if ((*a)->content > (*a)->next->next->content)
			ra (a, 0);
	}
	else
		rra (a, 0);
}

static void	sortfour(t_stack **a, t_stack **b)
{
	int		smallest;
	int		min;
	t_stack	*tmp;

	tmp = (*a);
	min = (*a)->content + 1;
	smallest = (*a)->index;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			smallest = tmp->index + 1;
		}
		tmp = tmp->next;
	}
	while (--smallest)
		ra(a, 0);
	pb (a, b);
	sortthree(a);
	pa (a, b);
}

static void	sortfive(t_stack **a, t_stack **b)
{
	int		smallest;
	int		min;
	t_stack	*tmp;

	tmp = (*a);
	min = (*a)->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			smallest = tmp->index + 1;
		}
		tmp = tmp->next;
	}
	if (smallest > 3)
		while (smallest++ < ft_stacklast((*a))->index + 2)
			rra (a, 0);
	else
		while (smallest--)
			ra (a, 0);
	pb (a, b);
	sortfour (a, b);
	pa (a, b);
}

void	sortcheck(t_stack **a, t_stack **b, int len)
{
	if (len == 1)
		sa (a, 0);
	if (len == 2)
		sortthree (a);
	if (len == 3)
		sortfour (a, b);
	if (len == 4)
		sortfive (a, b);
}
