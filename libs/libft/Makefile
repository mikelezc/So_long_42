# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 17:33:48 by mlezcano          #+#    #+#              #
#    Updated: 2023/11/24 17:44:48 by mlezcano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SHELL		=	/bin/bash

#Standard

NAME		=	libft.a
INCLUDE		=	inc/
SRC_DIR 	=	src/
OBJ_DIR		=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs
ECHO		=	echo -e

#Colors

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#Sources

LIBFT_DIR	=	libft/
LIBFT		=	ft_bzero ft_isalnum ft_isalpha ft_isascii \
	   		  ft_isdigit ft_isprint ft_memcpy ft_memmove \
	  		  ft_memset ft_strlen ft_tolower ft_toupper \
	   		  ft_strlcpy ft_strlcat ft_strchr ft_strrchr \
	   		  ft_strncmp ft_memchr ft_memcmp ft_strnstr \
	   		  ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
	   		  ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
			  ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
			  ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus \
			  ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus \
			  ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus

GNL_DIR		=	gnl/
GNL			=	get_next_line get_next_line_utils

FTPRINTF_DIR	= ft_printf/
FTPRINTF	=	ft_printf ft_alpha ft_numeric

SRC_FILES+=$(addprefix $(LIBFT_DIR),$(LIBFT))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL))
SRC_FILES+=$(addprefix $(FTPRINTF_DIR),$(FTPRINTF))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

start:
			@echo -e -n "$(YELLOW)[LIBFT]:\t$(DEF_COLOR)"
			@echo -e -n "$(RED)[$(DEF_COLOR)"
			@make all

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo -e -n "$(RED)]$(DEF_COLOR)"
			@$(ECHO) "$(GREEN) => 100%$(DEF_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@echo -e -n "$(ORANGE)=$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(LIBFT_DIR)
			@mkdir -p $(OBJ_DIR)$(GNL_DIR)
			@mkdir -p $(OBJ_DIR)$(FTPRINTF_DIR)
			@touch $(OBJF)

clean:
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@echo -e -n "$(BLUE)[LIBFT]:\tobject files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

fclean:		clean
			@$(RM) $(NAME)
			@echo -e -n "$(CYAN)[LIBFT]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

re:			fclean all
			@echo -e -n "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)\n"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
