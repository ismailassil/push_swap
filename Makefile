# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassil <iassil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 22:20:16 by iassil            #+#    #+#              #
#    Updated: 2025/01/27 20:20:52 by iassil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########### Source files
SRC=	./mandatory/_utils/ft_atoi.c		./mandatory/_utils/ft_lstadd_back.c		./mandatory/_utils/ft_strdup.c		\
		./mandatory/_utils/ft_isalpha.c		./mandatory/_utils/ft_lstnew.c			./mandatory/_utils/ft_strlcpy.c		\
		./mandatory/_utils/ft_split.c		./mandatory/_utils/ft_strlen.c			./mandatory/_utils/ft_substr.c		\
		./mandatory/_instructions/push.c	./mandatory/_instructions/rotate.c		./mandatory/_utils/ft_isdigit.c		\
		./mandatory/_instructions/swap.c	./mandatory/_utils/ft_lstadd_front.c	./mandatory/_src/push_swap.c		\
		./mandatory/_src/parse.c			./mandatory/_sort_algorithm/sort.c		./mandatory/_instructions/reverse_rotate.c	\
		./mandatory/_sort_algorithm/check_sorting.c	./mandatory/_sort_algorithm/algorithm.c

SRC_BONUS=	./bonus/parse_bonus.c				./bonus/_instructions/push_bonus.c		./bonus/lib/ft_lstadd_back_bonus.c		\
			./bonus/lib/ft_atoi_bonus.c			./bonus/lib/ft_split_bonus.c		./bonus/lib/ft_lstadd_front_bonus.c		\
			./bonus/lib/ft_substr_bonus.c		./bonus/lib/ft_isalpha_bonus.c		./bonus/lib/ft_strdup_bonus.c  			\
			./bonus/lib/ft_isdigit_bonus.c		./bonus/lib/ft_lstnew_bonus.c		./bonus/lib/ft_strlcpy_bonus.c			\
			./bonus/_instructions/rotate_bonus.c		./bonus/_instructions/swap_bonus.c		./bonus/_instructions/reverse_rotate_bonus.c	\
			./bonus/get_next_line/get_next_line_bonus.c							./bonus/get_next_line/get_next_line_utils_bonus.c	\
			./bonus/lib/ft_cmp_bonus.c			./bonus/checker_utils_bonus.c	./bonus/checker_bonus.c ./bonus/utils/push_back.c

OBJ=		$(SRC:.c=.o)
OBJ_BONUS=	$(SRC_BONUS:.c=.o)

########### Variables
CC=			cc
CC+=		-Wall -Wextra -Werror -fsanitize=address -g
NAME=		push_swap
NAME_BONUS=	checker
RM=			rm
RM+=		-f

########### HeaderFile
HEADER=			./_header/push_swap.h
HEADER_BONUS=	./_header/checker_bonus.h	./bonus/get_next_line/get_next_line_bonus.h

########### Goal Target
all: $(NAME)

bonus: $(NAME_BONUS)

########### Built Functions
mandatory/%.o: mandatory/%.c
	@$(CC) -c -o $@ $<

bonus/%.o: bonus/%.c
	@$(CC) -c -o $@ $<

$(NAME): $(OBJ) $(HEADER)
	@echo "$(YELLOW)Compilation of the Objects files...$(RESET)"
	@$(CC) -o $@ $(OBJ)
	@echo "$(GREEN)[====Executable file Compiled Successfully!====]$(RESET)"

$(NAME_BONUS): $(OBJ_BONUS) $(HEADER_BONUS)
	@echo "$(YELLOW)Compilation of the Objects files...$(RESET)"
	@$(CC) -o $(NAME_BONUS) $(OBJ_BONUS)
	@echo "$(GREEN)[====Executable file Compiled Successfully!====]$(RESET)"

########### OTHER
re: clean all

clean:
	@echo "$(YELLOW)Removing Object files...$(RESET)"
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "$(GREEN)[====Object files removed successfully!====]$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing Executable files...$(RESET)"
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)[====Executable files removed successfully!====]$(RESET)"

.PHONY: re all clean fclean bonus

########## Define ANSI escape codes for colors
GREEN=	\033[32m
YELLOW=	\033[0;33m
RESET=	\033[0m		# No Color
