# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 18:52:37 by mlezcano          #+#    #+#              #
#    Updated: 2023/12/14 16:51:42 by mlezcano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SHELL		=	/bin/bash

#compiler

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra #-fsanitize=address -g3
RM			= rm -f
ECHO		= echo -e
MINILIBXCC	= -I mlx -L lib/minilibx -lmlx
OPENGL		= -framework OpenGL -framework AppKit

#directories

LIBFT		= lib/libft/
MINILIBX	= lib/minilibx/
SRC_DIR		= src/
OBJ_DIR		= obj/
INC			= inc
HEADER		= -I inc

#output 

NAME		= so_long
BNAME		= so_long_bonus

#colors

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

#src directories

SL_DIR		=	so_long/
MAND_FILES	=	so_long map_ok check_limits window window_fill \
				keyhook itinerary_ok utils
BONUS_DIR	=	bonus/
BONUS_FILES	=	so_long_bonus map_ok_bonus check_limits_bonus itinerary_ok_bonus \
				window_bonus window_fill_bonus keyhook_bonus extra_bonus utils_bonus
				
#src files combination 

SRC_FILES	=	$(addprefix $(SL_DIR), $(MAND_FILES))
SRC_BFILES	=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

BSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BFILES)))
BOBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BFILES)))

#Cache flag 

OBJF		=	.cache_exists

#Target list

start:
			@$(ECHO) -n "$(GREEN)[Dependencies]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(DEF_COLOR)[$(DEF_COLOR)"
			@make all

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJF)
			@$(ECHO) -n "$(WHITE)]$(DEF_COLOR)"
			@$(ECHO) -n "$(GREEN) => OK! $(DEF_COLOR)\n"
			@make -C $(LIBFT)
			@cp lib/libft/libft.a .
			@make -s -C $(MINILIBX)
			@$(ECHO) -n "$(GREEN)[MINILIBX]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(DEF_COLOR)[$(DEF_COLOR)"
			@$(ECHO) -n "$(DEF_COLOR)=======$(DEF_COLOR)"
			@$(ECHO) -n "$(DEF_COLOR)]$(DEF_COLOR)"
			@$(ECHO) "$(GREEN) => OK!$(DEF_COLOR)"
			@$(ECHO) -n "$(GREEN)[$(NAME)]:\t$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(OBJ) $(HEADER) libft.a $(MINILIBXCC) $(OPENGL) -o $(NAME)
			@$(ECHO) "$(GREEN) => OK!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@$(ECHO) -n "$(DEF_COLOR)=$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(SL_DIR)
			@mkdir -p $(OBJ_DIR)$(BONUS_DIR)
			@touch $(OBJF)

clean:
			@$(RM) -r $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@$(RM) $(OBJF)
			@make clean -C $(MINILIBX)
			@$(ECHO) -n "$(RED)[so_long]:\tobject files$(DEF_COLOR)$(ORANGE)  => Clean$(DEF_COLOR)\n"
			@$(ECHO) -n "$(RED)[minilibx]:\tobject files$(DEF_COLOR)$(ORANGE)  => Clean$(DEF_COLOR)\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(BNAME)
			@$(RM) libft.a
			@$(RM) $(LIBFT)/libft.a
			@rm -rf *.dSYM
			@find . -name ".DS_Store" -delete
			@$(ECHO) -n "$(RED)[LIBFT]:\texec. files$(DEF_COLOR)$(ORANGE)  => Clean$(DEF_COLOR)\n"
			@$(ECHO) -n "$(RED)[so_long]:\texec. files$(DEF_COLOR)$(ORANGE)  => Clean$(DEF_COLOR)\n"
			@$(ECHO) -n "$(RED)[minilibx]:\texec. files$(DEF_COLOR)$(ORANGE)  => Clean$(DEF_COLOR)\n"


re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [so_long]!$(DEF_COLOR)\n"

bonus:
			@$(ECHO) -n "$(GREEN)[Dependencies]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(DEF_COLOR)[$(DEF_COLOR)"
			@make allbonus

allbonus:	$(BNAME)

$(BNAME):	$(BOBJ)
			@$(ECHO) -n "$(DEF_COLOR)]$(DEF_COLOR)"
			@$(ECHO) -n "$(GREEN) => 100%$(DEF_COLOR)\n"
			@make -C $(LIBFT)
			@cp lib/libft/libft.a .
			@make -s -C $(MINILIBX)
			@$(ECHO) -n "$(GREEN)[MINILIBX]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(DEF_COLOR)[$(DEF_COLOR)"
			@$(ECHO) -n "$(DEF_COLOR)=$(DEF_COLOR)"
			@$(ECHO) -n "$(DEF_COLOR)]$(DEF_COLOR)"
			@$(ECHO) "$(GREEN) => OK!$(DEF_COLOR)"
			@$(ECHO) -n "$(GREEN)[$(BNAME)]:$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(BSRC) $(HEADER) libft.a  $(MINILIBXCC) $(OPENGL) -o $(BNAME)
			@$(ECHO) "$(GREEN) => OK!$(DEF_COLOR)"

#phony rules

.PHONY:		all clean fclean re 
