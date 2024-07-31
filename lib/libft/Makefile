# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 09:44:14 by emgul             #+#    #+#              #
#    Updated: 2024/07/07 14:58:38 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_itoa \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_split \
			ft_strchr \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtrim \
			ft_substr \
			ft_tolower \
			ft_toupper	\
			ft_lstadd_back \
			ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstlast \
			ft_lstmap \
			ft_lstnew \
			ft_lstsize \
			gnl/get_next_line	\
			gnl/get_next_line_utils	\
			printf/ft_printf	\
			printf/ft_format_utilities	\
			printf/ft_puthex	\
			printf/ft_putnbr	\
			printf/ft_putstr	\
			printf/ft_putptr	\
			printf/ft_putunsigned
		
NAME			=	libft.a

CC				=	gcc
CFLAGS			=	-I $(LIBFT_PATH) -Wall -Wextra -Werror
MFLAGS			=	-s -C
AR				=	ar rcs
RM				=	rm -rf

FILES_PATH		=	src/

SRCS            =   $(addprefix $(FILES_PATH), $(addsuffix .c, $(FILES)))
OBJS            =   $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)-== all object files deleted! -==$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)-== all files deleted! -==$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re

# ANSI COLOR CODES
DEFAULT = \033[0m
RED = \033[1;31m
YELLOW = \033[1;33m
GREEN = \033[1;32m
BLUE = \033[1;36m
ORANGE = \033[38;5;208m