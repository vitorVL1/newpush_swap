/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:35:06 by vlima             #+#    #+#             */
/*   Updated: 2023/03/30 15:44:20 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (i <= tam)
	{
		if ((*stack_a)->content >= chunk[tam - 1])
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
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

void	best_path(t_node **stack_a, t_node **stack_b)
{
	int	pos_big;
	int	pos_smal;
	int	count_b;
	int	count_s;
	int	move;

	count_b = 0;
	count_s = 0;
	pos_big = find_big(stack_b);
	pos_smal = find_low(stack_b);
	if (pos_big > ((ft_lstsize(*stack_b)) / 2))
	{
		while (pos_big++ < (ft_lstsize(*stack_b)))
			count_b++;
	}
	if (pos_smal > ((ft_lstsize(*stack_b)) / 2))
	{
		while (pos_smal++ < (ft_lstsize(*stack_b)))
			count_s++;
	}
	move = top_stackb(find_big(stack_b), count_b, find_low(stack_b), count_s);
	while (move++ <= -1)
		rrb(stack_b);
	while (move-- > 1)
		rb(stack_b);
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
	while (i++ < tam - 1)
		pb(stack_a, stack_b);
	while ((*stack_b) != NULL)
	{
		best_path(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	while (analise(stack_a) == 0)
		ra(stack_a);
}
