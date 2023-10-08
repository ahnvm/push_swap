/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costoptimizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:56:52 by acan              #+#    #+#             */
/*   Updated: 2023/10/07 17:47:28 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void anoderr(t_stack *anode, t_stack *bnode, int totalcost)
{
	int	newcost;
	int	tmp;
	int	newanodecost;
	
	newanodecost = ft_stacklast(anode)->index - anode->index + 1;
	if (newanodecost > bnode->cost)
	{
		tmp = newanodecost - bnode->cost;
		newcost = newanodecost + tmp;
	}
	else
	{
		tmp = bnode->cost - newanodecost;
		newcost = bnode->cost + tmp;
	}
	if (newcost < totalcost)
	{
		anode->isrr = 1;
		anode->cost = ft_stacklast(anode)->index - anode->index + 1;
	}
}

static void anoder(t_stack *anode, t_stack *bnode, int totalcost)
{
	int	newcost;
	int	tmp;
	int	newanodecost;
	
	newanodecost = anode->index;
	if (newanodecost > bnode->cost)
	{
		tmp = newanodecost - bnode->cost;
		newcost = newanodecost + tmp;
	}
	else
	{
		tmp = bnode->cost - newanodecost;
		newcost = bnode->cost + tmp;
	}
	if (newcost < totalcost)
	{
		anode->isrr = 0;
		anode->cost = anode->index;
	}

}

static void	bnoderr(t_stack *anode, t_stack *bnode, int totalcost)
{
	int	newcost;
	int	tmp;
	int	bnodecost;
	
	bnodecost = ft_stacklast(bnode)->index - bnode->index + 1;
	if (bnodecost > anode->cost)
	{
		tmp = bnodecost - anode->cost;
		newcost = bnodecost + tmp;
	}
	else
	{
		tmp = anode->cost - bnodecost;
		newcost = anode->cost + tmp;
	}
	if (newcost < totalcost)
	{
		bnode->isrr = 1;
		bnode->cost = ft_stacklast(bnode)->index - bnode->index + 1;
	}
}

static void bnoder(t_stack *anode, t_stack *bnode, int totalcost)
{
	int	newcost;
	int	tmp;
	int	newbnodecost;
	
	newbnodecost = bnode->index;
	if (newbnodecost > anode->cost)
	{
		tmp = newbnodecost - anode->cost;
		newcost = newbnodecost + tmp;
	}
	else
	{
		tmp = anode->cost - newbnodecost;
		newcost = anode->cost + tmp;
	}
	if (newcost < totalcost)
	{
		bnode->isrr = 0;
		bnode->cost = bnode->index;
	}	
}

void	changepath(t_stack *anode, t_stack *bnode)
{
	
	int	totalcost;

	totalcost = anode->cost + bnode->cost;
	if (anode->isrr == 0 && anode->cost > bnode->cost)
		bnoder(anode, bnode, totalcost);
	else if (anode->isrr == 1 && anode->cost > bnode->cost)
		bnoderr(anode, bnode, totalcost);
	else if (bnode->isrr == 0 && bnode->cost > anode->cost)
		anoder(anode, bnode, totalcost);
	else if (bnode->isrr == 1 && bnode->cost > anode->cost)
		anoderr(anode, bnode, totalcost);
}
