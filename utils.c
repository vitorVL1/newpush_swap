/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:08:04 by vlima             #+#    #+#             */
/*   Updated: 2023/03/26 23:40:45 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long		result;
	int			sign;
	const char	*p;

	result = 0;
	sign = 1;
	p = str;
	if (*p == '-')
	{
		sign = -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		result = (result * 10) + (*p - '0');
		p++;
	}
	return (sign * result);
}

void	error(t_node **stack_a, t_node **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	write(2, "Error\n", 6);
	exit(0);
}

void	sort_array(int *array, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i++ < size - 1)
	{
		j = i + 1;
		while (j++ < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void	list2array(t_node **stack1, int *array)
{
	t_node	*current;
	int		i;
	int		temp;
	int		j;

	current = *stack1;
	i = 0;
	while (current)
	{
		array[i++] = current->content;
		current = current->next;
	}
	sort_array(array, ft_lstsize((*stack1)));
}
