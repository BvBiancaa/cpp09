# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bianca <bianca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 19:50:58 by bmuni             #+#    #+#              #
#    Updated: 2023/04/16 21:20:32 by bianca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=PmergeMe

all: $(NAME)

$(NAME):
	c++ -g -Wall -Wextra -Werror main.cpp -std=c++98 PmergeMe.cpp -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean $(NAME)

.PHONY: all, clean, fclean, re
