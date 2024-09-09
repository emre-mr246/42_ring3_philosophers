# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 07:09:36 by emgul             #+#    #+#              #
#    Updated: 2024/08/31 07:16:15 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES				= main utils init input dinner get_and_set time threads dinner_utils watch clean

BONUS_NAME			= philo_bonus

CC					= gcc
CCFLAGS				=  -fsanitize=thread -Wall -Wextra -Werror
MAKEFLAGS			= --no-print-directory
RM					= rm -rf

BONUS_FILES_PATH	= ./
OBJ_DIR				= .obj/

BONUS_SRCS			= $(addprefix $(BONUS_FILES_PATH), $(addsuffix _bonus.c, $(FILES)))
BONUS_OBJS			= $(addprefix $(OBJ_DIR), $(notdir $(BONUS_SRCS:.c=.o)))

vpath %.c $(BONUS_FILES_PATH)

all: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_DIR) $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(CCFLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)-== $(BONUS_NAME) created! ==-$(DEFAULT)"

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
clean:
	@$(RM) $(BONUS_OBJS)
	@echo "$(YELLOW)-== all object files deleted! ==-$(DEFAULT)"

fclean: clean
	@$(RM) $(BONUS_NAME)
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)-== all files deleted! ==-$(DEFAULT)"

re: fclean all

.PHONY: all bonus clean fclean re

# ANSI COLOR CODES
DEFAULT = \033[0m
RED     = \033[1;31m
YELLOW  = \033[1;33m
GREEN   = \033[1;32m
BLUE    = \033[1;36m
ORANGE  = \033[38;5;208m