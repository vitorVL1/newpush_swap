/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:08:04 by vlima             #+#    #+#             */
/*   Updated: 2023/03/30 15:44:45 by vlima            ###   ########.fr       */
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
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
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
	i = 0;
	sort_array(array, ft_lstsize((*stack1)));
	i = 0;
}

void	printstack(t_node **stack1, t_node **stack2)
{
	t_node	*current;
	t_node	*current2;

	if (stack1 == NULL || stack2 == NULL)
	{
		printf("Error: One or both stacks are NULL.\n");
		return ;
	}
	current = *stack1;
	current2 = *stack2;
	printf("--------------\n");
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
	while (current2 != NULL)
	{
		printf("\t%d\n", current2->content);
		current2 = current2->next;
	}
	printf("--------------\n");
}
