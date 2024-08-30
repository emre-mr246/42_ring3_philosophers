# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 07:09:36 by emgul             #+#    #+#              #
#    Updated: 2024/08/30 06:23:10 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES				= main utils init input dinner get_and_set time threads dinner_utils monitor

NAME				= philo

CC					= gcc
CCFLAGS				= -O3 -march=native -Wall -Wextra -Werror
MAKEFLAGS			= --no-print-directory
RM					= rm -rf

LIBFT_PATH			= lib/libft/
LIBFT				= $(LIBFT_PATH)libft.a

FILES_PATH			= src/mandatory/
OBJ_DIR				= .obj/

SRCS				= $(addprefix $(FILES_PATH), $(addsuffix .c, $(FILES)))
OBJS				= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

vpath %.c $(FILES_PATH) $(BONUS_FILES_PATH)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(CCFLAGS) -o $(NAME)
	@echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make $(MAKEFLAGS) -C $(LIBFT_PATH)

check-norm: all
	@norminette src/ lib/libft inc/ | grep -B 1 "Error\|Warning" || echo "$(GREEN)Norme check passed!$(DEFAULT)"
	
clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)-== all object files deleted! ==-$(DEFAULT)"

fclean: clean libclean
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)-== all files deleted! ==-$(DEFAULT)"

libclean:
	@make $(MAKEFLAGS) -C $(LIBFT_PATH) fclean
	@echo "$(BLUE)-== all object files deleted in libraries! ==-$(DEFAULT)"

re: fclean all

.PHONY: all bonus clean fclean libclean re check-norm

# ANSI COLOR CODES
DEFAULT = \033[0m
RED     = \033[1;31m
YELLOW  = \033[1;33m
GREEN   = \033[1;32m
BLUE    = \033[1;36m
ORANGE  = \033[38;5;208m