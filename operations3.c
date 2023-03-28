/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:10:26 by vlima             #+#    #+#             */
/*   Updated: 2023/03/22 16:10:36 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack1)
{
	ft_swap(stack1);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack2)
{
	ft_swap(stack2);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack1, t_node **stack2)
{
	ft_swap(stack1);
	ft_swap(stack2);
	write(1, "ss\n", 3);
}

void	rra(t_node **stack1)
{
	ft_reverse(stack1);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack2)
{
	ft_reverse(stack2);
	write(1, "rrb\n", 4);
}
