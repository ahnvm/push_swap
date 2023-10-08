/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:59:03 by acan              #+#    #+#             */
/*   Updated: 2023/10/08 18:27:50 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_stack
{
	int				index;
	int				content;
	int				isrr;
	int				cost;
	struct s_stack	*next;
	struct s_stack	*target_node;
}					t_stack;

void				print_error(char *error);
void				isvalid1(int ac, char **av);
int					countword_onearg(const char *s, char c);
int					arglen(char **args);
char				**argjoin(char **seperated, char *raw);
char				**seperate_all(char **av);
int					myatoi(char *str);
t_stack				*stacknew(int index, int content);
t_stack				*ft_stacklast(t_stack *stack);
void				stackadd_back(t_stack **stack, t_stack *new);
void				addtostack(char **last, t_stack **a);
void				indexstack(t_stack *stack);
void				sa(t_stack **a, int flag);
void				sb(t_stack **b, int flag);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a, int flag);
void				rb(t_stack **b, int flag);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, int flag);
void				rrb(t_stack **b, int flag);
void				rrr(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				sortcheck(t_stack **a, t_stack **b, int len);
int					islistsorted(t_stack **stack);
void				basicsort(t_stack **a, t_stack **b);
int					getbiggest(t_stack **stack);
int					getsmallest(t_stack **stack);
void				setrr(t_stack **stack);
void				settarget(t_stack **a, t_stack **b);
void				setcost(t_stack **a, t_stack **b);
t_stack				*calculatecost(t_stack **a);
t_stack				*nodeofindex(int index, t_stack **stack);
t_stack				*recheckcost(t_stack **a, t_stack *node, t_stack *target);

#endif