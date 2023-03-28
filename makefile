# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlima <vlima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 16:40:56 by vlima             #+#    #+#              #
#    Updated: 2023/03/27 23:58:38 by vlima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -g++

RM = rm -f

SRC = operations1.c operations2.c operations3.c push_swap.c utils_lst.c pushlower.c checker.c short_sorter.c utils.c sorter_utils.c sorter_100.c
all:			$(NAME)

$(NAME):		
				$(CC) $(SRC) -o $(NAME) 

clean:
				$(RM) $(NAME)

fclean: 		clean
				

re:		fclean	$(NAME)
