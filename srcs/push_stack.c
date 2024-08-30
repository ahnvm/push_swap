/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:29 by acan              #+#    #+#             */
/*   Updated: 2024/08/30 18:03:13 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if ((*b) == NULL)
		return ;
	tmp2 = (*b);
	tmp = (*b)->next;
	tmp2->next = (*a);
	(*a) = tmp2;
	(*b) = tmp;
	indexstack((*a));
	indexstack((*b));
	setrr(a);
	setrr(b);
	setcost(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if ((*a) == NULL)
		return ;
	tmp2 = (*a);
	tmp = (*a)->next;
	tmp2->next = (*b);
	(*b) = tmp2;
	(*a) = tmp;
	indexstack((*a));
	indexstack((*b));
	setrr(a);
	setrr(b);
	setcost(a, b);
	ft_putstr_fd("pb\n", 1);
}
