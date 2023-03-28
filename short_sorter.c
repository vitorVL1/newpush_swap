/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:15:16 by vlima			   #+#    #+#            */
/*   Updated: 2023/03/22 16:15:16 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lowest(t_node *stack)
{
	int		lowest;
	t_node	*current;

	current = stack;
	lowest = INT_MAX;
	while (current)
	{
		if (current->content < lowest)
		{
			lowest = current->content;
		}
		current = current->next;
	}
	return (lowest);
}

void	short_sorter(t_node **stack)
{
	int	primeiro;
	int	segundo;
	int	terceiro;

	primeiro = (*stack)->content;
	segundo = (*stack)->next->content;
	terceiro = (*stack)->next->next->content;
	if (primeiro > segundo && segundo > terceiro)
	{
		sa(stack);
		rra(stack);
	}
	else if (primeiro < terceiro && segundo > terceiro && primeiro < segundo)
	{
		sa(stack);
		ra(stack);
	}
	else if (primeiro > segundo && primeiro > terceiro)
		ra(stack);
	else if (primeiro < segundo && segundo > terceiro)
		rra(stack);
	else if (primeiro > segundo && segundo < terceiro)
		sa(stack);
}

void	sorter5(t_node **stack1, t_node **stack2, int argc)
{
	push_lower(stack1, stack2);
	if (argc == 6)
		push_lower2(stack1, stack2);
	short_sorter(stack1);
	pa(stack1, stack2);
	if (argc == 6)
		pa(stack1, stack2);
}
