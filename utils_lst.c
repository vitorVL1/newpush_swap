/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:05:02 by vlima             #+#    #+#             */
/*   Updated: 2023/03/28 16:56:11 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_node *stack1)
{
	t_node	*current;
	int		i;

	current = stack1;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	while (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_node	*ft_addstack(long value, int argc)
{
	t_node	*newlst;

	newlst = malloc(sizeof(t_node));
	if (newlst == NULL)
		return (NULL);
	newlst->content = value;
	newlst->next = NULL;
	return (newlst);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
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
