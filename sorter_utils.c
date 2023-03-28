/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:41:05 by vlima             #+#    #+#             */
/*   Updated: 2023/03/28 22:53:21 by vlima            ###   ########.fr       */
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
	//printf("maxpos:%d\n",posmax);
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
	//printf("minpos:%d\n",possmal);
	return (possmal);
}
