# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 15:21:59 by lottavi           #+#    #+#              #
#    Updated: 2024/11/21 15:42:07 by lottavi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = build/Jez

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:%.cpp=build/bin/%.o)

all: build_dir $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

build/bin/%.o: %.cpp | build_dir
	$(CXX) $(CXXFLAGS) -c $< -o $@

build_dir:
	mkdir -p build/bin

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re build_dir
