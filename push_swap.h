/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:06:06 by vlima             #+#    #+#             */
/*   Updated: 2023/03/30 11:39:27 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node_a
{
	struct node_a	*head;
	int				content;
	struct node_a	*next;
}					t_node;

//utils
long				ft_atol(const char *str);
int					ft_atoi(const char *str);
void				printstack(t_node **stack1, t_node **stack2);
void				error(t_node **stack_a, t_node **stack_b);
void				sort_array(int *array, int size);
//operations

void				ft_swap(t_node **stack);
void				ft_rotate(t_node **stack);
void				ft_reverse(t_node **stack);
void				ft_push(t_node **stack1, t_node **stack2);
void				ra(t_node **stack1);
void				rb(t_node **stack2);
void				rr(t_node **stack1, t_node **stack2);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				rra(t_node **stack1);
void				rrb(t_node **stack2);
void				rrr(t_node **stack1, t_node **stack2);
void				sa(t_node **stack1);
void				sb(t_node **stack2);
void				ss(t_node **stack1, t_node **stack2);

//sorters
void				push_lower2(t_node **stack1, t_node **stack2);
void				push_lower(t_node **stack1, t_node **stack2);
void				short_sorter(t_node **stack);
void				sorter5(t_node **stack1, t_node **stack2, int num);
int					find_lowest(t_node *stack);
void				sorter_100(t_node **stack_a, t_node **stack_b, int tam);
void				sorter_500(t_node **stack_a, t_node **stack_b, int tam);

//lst
void				ft_lstadd_back(t_node **lst, t_node *new);
t_node				*ft_lstlast(t_node *lst);
t_node				*ft_addstack(long value, int argc);
void				ft_lstclear(t_node **lst);
int					ft_lstsize(t_node *stack1);
void				list2array(t_node **stack1, int *array);

//sorter utils
int					find_big(t_node **stack);
int					find_low(t_node **stack);
void				make_chunck100(t_node **stack_a, t_node **stack_b, int tam);
void				best_path(t_node **stack_a, t_node **stack_b);
int					top_stackb(int rrb_big, int rb_big, int rrb_smal,
						int rb_smal);
void				push_a(t_node **stack_a, t_node **stack_b);
void				stacka_organizer(t_node **stack_a, int *chunk, int tam);
//idk
int					checker(int argc, char **argv);
int					analise(t_node **stack);

#endif