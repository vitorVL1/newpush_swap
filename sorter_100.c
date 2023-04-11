/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:35:06 by vlima             #+#    #+#             */
/*   Updated: 2023/04/03 13:32:15 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_node **stack_a, t_node **stack_b, int *chunk, int tam)
{
	int	i;

	i = 0;
	if (ft_lstsize((*stack_a)) % 2 != 0)
		tam++;
	while (i <= ft_lstsize((*stack_a)))
	{
		if ((*stack_a)->content >= chunk[tam - 1])
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	return ;
}

void	make_chunck100(t_node **stack_a, t_node **stack_b, int tam)
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
	push_b(stack_a, stack_b, chunk, tam);
	free(chunk);
}

int	top_stackb(int rrb_big, int rb_big, int rrb_smal, int rb_smal)
{
	int	rotation;

	if (rb_big == 0)
		rb_big = INT_MAX;
	if (rb_smal == 0)
		rb_smal = INT_MAX;
	if (rrb_big < rb_big && rrb_big < rrb_smal && rrb_big < rb_smal)
		rotation = rrb_big;
	else if (rb_big < rrb_smal && rb_big < rb_smal)
		rotation = rb_big * -1;
	else if (rrb_smal < rb_smal)
		rotation = rrb_smal;
	else
		rotation = rb_smal * -1;
	return (rotation);
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	pa(stack_a, stack_b);
	if ((*stack_a)->content < find_lowest((*stack_b)))
		ra(stack_a);
}

void	sorter_100(t_node **stack_a, t_node **stack_b, int tam)
{
	int	i;
	int	pos_big;

	i = 0;
	make_chunck100(stack_a, stack_b, tam);
	while ((*stack_b) != NULL)
	{
		best_path(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	pos_big = find_big(stack_a);
	while (i++ <= pos_big)
		ra(stack_a);
	i = 0;
	while (i++ < tam + 1)
		pb(stack_a, stack_b);
	while ((*stack_b) != NULL)
	{
		best_path(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	while (analise(stack_a) == 0)
		rra(stack_a);
}
