# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anri <anri@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 22:23:36 by anri              #+#    #+#              #
#    Updated: 2019/10/28 16:26:27 by anri             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++ -std=c++14

FLAGS = -Wall -Wextra -Wconversion -Werror

NAME = avm

SRC =	main.cpp Operand.cpp MyExceptions.cpp Factory.cpp Lexer.cpp Program.cpp Parser.cpp

HEAD =	Operand.hpp IOperand.hpp Factory.hpp MyExceptions.hpp Lexer.hpp Program.hpp Parser.hpp

HEADERS = $(addprefix $(SRC_DIR), $(HEAD))

SRC_DIR = ./src/

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

UNAME_S := $(shell uname -s)

LINKS :=

INCLUDES :=

all: obj_dir $(NAME)
	echo "Compilated"

obj_dir:
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
