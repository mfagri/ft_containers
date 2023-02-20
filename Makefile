# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 21:09:13 by mfagri            #+#    #+#              #
#    Updated: 2023/02/20 18:49:58 by mfagri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

SRC	= main.cpp

# CFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++ #-fsanitize=address -fsanitize=undefined -g 

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp vector.hpp vector_iterator.hpp stack.hpp enable_if.hpp equal.hpp reverse_iterator.hpp is_integral.hpp map.hpp red_black_tree.hpp red_black_iterator.hpp set.hpp
	$(CXX) $(CFLAGS) -c -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS)  $(SRC) -o $(NAME)


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all