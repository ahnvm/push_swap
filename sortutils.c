/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:48:49 by acan              #+#    #+#             */
/*   Updated: 2023/10/05 16:56:49 by acan             ###   ########.fr       */
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
