/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:11:30 by vlima             #+#    #+#             */
/*   Updated: 2023/03/22 16:12:11 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	ft_rotate(t_node **stack)
{
	t_node	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstlast(*stack)->next = tmp;
	tmp->next = NULL;
}

void	ft_reverse(t_node **stack)
{
	t_node	*tmp;
	t_node	*final;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
		return ;
	while ((*stack)->next->next)
	{
		*stack = (*stack)->next;
	}
	final = (*stack)->next;
	final->next = tmp;
	(*stack)->next = NULL;
	*stack = final;
}

void	ft_push(t_node **stack1, t_node **stack2)
{
	t_node	*top_a;
	t_node	*top_b;

	top_b = *stack2;
	top_a = *stack1;
	if (*stack1 == NULL)
	{
		return ;
	}
	*stack1 = (*stack1)->next;
	top_a->next = top_b;
	*stack2 = top_a;
}

void	rrr(t_node **stack1, t_node **stack2)
{
	ft_reverse(stack1);
	ft_reverse(stack2);
	write(1, "rrr\n", 4);
}
