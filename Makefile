# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 10:34:03 by soelalou          #+#    #+#              #
#    Updated: 2023/11/13 10:08:02 by soelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME	=	libftprintf.a
EXEC	=	ft_print
CC	=	gcc
CCFLAGS	=	-Wall -Wextra -Werror

BIN	=	bin
SRC	=	ft_printf.c ft_putaddr.c ft_putchar.c ft_putnbr.c \
		ft_putstr.c ft_putunbr.c ft_strlen.c
OBJ	=	$(addprefix $(BIN)/, $(SRC:.c=.o))


# **************************************************************************** #
# COLORS

GREEN		= \033[0;32m
GREY		= \033[1;30m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
CYAN		= \033[0;36m
END_COLOR	= \033[0;39m


# **************************************************************************** #
# RULES

all: $(NAME)

$(BIN)/%.o: src/%.c | $(BIN)
	@echo "$(BLUE)[Compiling]$(END_COLOR) $<"
	@$(CC) $(CCFLAGS) -c $< -o $@

$(BIN):
	@echo "$(YELLOW)[BIN]$(END_COLOR) Creating bin folder"
	@mkdir -p $(BIN)

$(NAME): $(BIN) $(OBJ)
	@echo "$(CYAN)[Library]$(END_COLOR) Creating libftprintf.a"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)[Success]$(END_COLOR) Libftprintf is ready !"

clean:
	@rm -rf $(BIN)
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted !"

fclean:	clean
	@rm -rf $(NAME) $(EXEC)
	@echo "$(GREY)[Clean]$(END_COLOR) Libftprintf.a & executable has been deleted !"

re: fclean all

.PHONY: all clean fclean re