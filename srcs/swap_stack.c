/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:02:46 by acan              #+#    #+#             */
/*   Updated: 2024/08/30 18:03:29 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack **a, int flag)
{
	int	tmp;
	int	tmp2;

	if ((*a)->next == NULL)
		return ;
	tmp = (*a)->content;
	tmp2 = (*a)->next->content;
	(*a)->content = tmp2;
	(*a)->next->content = tmp;
	if (flag == 0)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int flag)
{
	int	tmp;
	int	tmp2;

	if ((*b)->next == NULL)
		return ;
	tmp = (*b)->content;
	tmp2 = (*b)->next->content;
	(*b)->content = tmp2;
	(*b)->next->content = tmp;
	if (flag == 0)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		sa(a, 1);
		sb(b, 1);
		ft_putstr_fd("ss\n", 1);
	}
}
