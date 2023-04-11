/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:02:07 by vlima             #+#    #+#             */
/*   Updated: 2023/04/03 13:33:00 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	analise(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

t_node	*push_swap(int argc, char **argv)
{
	int		i;
	t_node	*node;
	t_node	*start;

	start = NULL;
	i = 1;
	while (i != argc)
	{
		node = ft_addstack(ft_atol(argv[i]), argc);
		if (start == NULL)
		{
			start = node;
		}
		else
		{
			ft_lstadd_back(&start, node);
		}
		i++;
	}
	return (start);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (checker(argc, argv) == 0)
		return (0);
	stack_a = push_swap(argc, argv);
	stack_b = NULL;
	if (argc == 3 && analise(&stack_a) == 0)
		sa(&stack_a);
	else if (argc == 4 && analise(&stack_a) == 0)
		short_sorter(&stack_a);
	else if (argc == 5 || argc == 6)
		sorter5(&stack_a, &stack_b, argc);
	else if (argc > 6 && argc <= 451 && analise(&stack_a) == 0)
		sorter_100(&stack_a, &stack_b, (ft_lstsize(stack_a) / 2));
	else if (argc > 451 && analise(&stack_a) == 0)
		sorter_500(&stack_a, &stack_b, 75);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
