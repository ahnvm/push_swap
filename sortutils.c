/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:48:49 by acan              #+#    #+#             */
/*   Updated: 2023/09/30 17:06:21 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getaverage (t_stack **a)
{
	int		sum;
	int		average;
	int		maxindex;
	t_stack *tmp;

	maxindex = 0;
	sum = 0;
	tmp = (*a);
	while (tmp)
	{
		maxindex++;
		sum += tmp ->content;
		tmp = tmp ->next;
	}
	average = sum / maxindex;
	return (average);
}

int	fifthbiggest(t_stack **a, int five)
{
	int		biggest;
	long	secondbiggest;
	t_stack	*tmp;

	tmp = (*a);
	biggest = tmp -> content;
	while (tmp)
	{
		if (biggest < tmp ->content)
			biggest = tmp ->content;
		tmp = tmp->next;
	}
	while (--five > 0)
	{
		tmp = (*a);
		secondbiggest = -2147483648;
		while (tmp)
		{
			if (tmp->content < biggest && tmp->content > secondbiggest)
				secondbiggest = tmp->content;
			tmp = tmp->next;
		}
		biggest = secondbiggest;
	}
	return (biggest);
}

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

void	sorttry(t_stack **b)
{
	if ((*b)->next == NULL)
		return ;
	if ((*b)->content < getaverage(b))
		rb(b,0);
}