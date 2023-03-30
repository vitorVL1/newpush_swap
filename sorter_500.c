/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:41:05 by vlima             #+#    #+#             */
/*   Updated: 2023/03/30 15:43:21 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big(t_node **stack)
{
	int		max;
	int		pos;
	int		posmax;
	t_node	*current;

	current = *stack;
	max = INT_MIN;
	pos = 0;
	while (current)
	{
		if (current->content > max)
		{
			max = current->content;
			posmax = pos;
		}
		if (current->next == NULL)
			break ;
		current = current->next;
		pos++;
	}
	return (posmax);
}

int	find_low(t_node **stack)
{
	int		smal;
	int		pos;
	int		possmal;
	t_node	*current;

	current = *stack;
	smal = INT_MAX;
	pos = 0;
	while (current)
	{
		if (current->content < smal)
		{
			smal = current->content;
			possmal = pos;
		}
		pos++;
		current = current->next;
	}
	return (possmal);
}

void	stacka_organizer(t_node **stack_a, int *chunk, int index)
{
	if (index == 0)
		return ;
	while ((*stack_a)->content != chunk[index - 1])
		ra(stack_a);
	ra(stack_a);
}

void	make_chunck500(t_node **stack_a, t_node **stack_b, int tam, int index)
{
	int		*chunk;
	t_node	**current;
	int		size;
	int		i;

	i = 0;
	current = stack_a;
	chunk = malloc((ft_lstsize((*stack_a))) * sizeof(int));
	if (chunk == NULL)
	{
		free(chunk);
		error(stack_a, stack_b);
	}
	list2array(stack_a, chunk);
	while (i <= tam - 1)
	{
		if ((*stack_a)->content >= chunk[0 + index]
			&& (*stack_a)->content <= chunk[tam - 1 + index] && ++i)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	stacka_organizer(stack_a, chunk, index);
	free(chunk);
}

void	sorter_500(t_node **stack_a, t_node **stack_b, int tam)
{
	int	i;
	int	pos_big;
	int	index;

	index = 0;
	i = 0;
	while (i <= 5)
	{
		make_chunck500(stack_a, stack_b, tam, index);
		while ((*stack_b) != NULL)
		{
			best_path(stack_a, stack_b);
			push_a(stack_a, stack_b);
		}
		index = tam + index;
		i++;
	}
	make_chunck500(stack_a, stack_b, 50, 450);
	while ((*stack_b) != NULL)
	{
		best_path(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	while (analise(stack_a) == 0)
		ra(stack_a);
}
