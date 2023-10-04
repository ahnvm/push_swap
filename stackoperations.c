/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackoperations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:49:19 by acan              #+#    #+#             */
/*   Updated: 2023/10/05 00:28:23 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int index, int content)
{
	t_stack	*node;

	node = (t_stack *)malloc (sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> index = index;
	node -> next = NULL;
	node -> isrr = -1;
	node -> cost = -1;
	node -> target_node = NULL;
	return (node);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
	{
		return (NULL);
	}
	tmp = stack;
	while (tmp->next != 0)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

static t_stack	*ft_stacklast_control(t_stack *stack, int content, int index)
{
	if (!stack)
	{
		return (NULL);
	}
	while (stack->next != NULL)
	{
		if (content == stack->content && index != stack->index)
			return (NULL);
		stack = stack->next;
	}
	if (content == stack->content && index != stack->index)
		return (NULL);
	return (stack);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	if (ft_stacklast_control (*stack, new->content, new->index) == NULL)
		print_error("Duplicate error\n");
	else
	{
		ft_stacklast_control (*stack, new->content, new->index)->next = new;
	}
}

void	addtostack(char **last, t_stack **a)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	*a = stacknew (i, myatoi (last[i]));
	i++;
	while (last[i])
	{
		tmp = stacknew (i, myatoi (last[i]));
		stackadd_back(a, tmp);
		i++;
	}
}
