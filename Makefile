# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eraad <eraad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:33:34 by eraad             #+#    #+#              #
#    Updated: 2025/03/17 17:07:56 by eraad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#* ------------------ Variables ---------------------- *
NAME		= pipex
NAME_BONUS	= pipex_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -ggdb3
INCLUDE		= -I./include
RM = rm -rf
INCLUDE_BONUS	= -I./bonus/include_bonus

#* ------------------ Colors-------------------------- *
DEF = \033[0m
Y = \033[0;93m
G = \033[0;92m
R = \033[0;91m
ORANGE = \033[38;5;208m
LIGHT_GREEN = \033[38;5;120m
NEON_GREEN = \033[38;5;82m

#* ------------------ Sources------------------------- *
SRCS_DIR		=	sources/
SRC_FILES		=	cleanup/cleanup.c \
					error/print_error.c \
					init/init_pipex_struct.c \
					parse/check_args.c parse/check_envp.c parse/handle_files.c parse/parse_cmd_args.c parse/parse_cmd_paths.c \
					pipex_logic.c \
					main.c \

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))

SRCS_DIR_BONUS	=	bonus/sources_bonus/
SRC_FILES_BONUS	=	cleanup/cleanup.c \
					error/print_error.c \
					init/init_pipex_struct.c \
					parse/check_args.c parse/check_envp.c parse/handle_files.c parse/parse_cmd_args.c parse/parse_cmd_paths.c \
					pipex_logic.c \
					main.c \

SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS), $(SRC_FILES_BONUS))

#* ------------------ Objects ------------------------ *
OBJS_DIR		=	objects/
OBJS			=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
OBJS_DIR_BONUS	=	bonus/objects_bonus/
OBJS_BONUS		=	$(patsubst $(SRCS_DIR_BONUS)%.c, $(OBJS_DIR_BONUS)%.o, $(SRCS_BONUS))

#* ------------------ Rules -------------------------- *
all: $(NAME)

$(NAME): $(OBJS)
				@echo "_________________________________________________"
					@echo "$(G)\n--- Creating libft...\n$(DEF)"
				@$(MAKE) -C libft --no-print-directory
				@echo "_________________________________________________"
				@echo "$(G)\n--- Creating $(NAME)...\n $(DEF)"
				@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
				@echo "$(NEON_GREEN)      .-------------------------------. $(DEF)"
				@echo "$(NEON_GREEN)     (   $(NAME) compiled succesfully!   ) $(DEF)"
				@echo "$(NEON_GREEN)      '-------------------------------' $(DEF)"
				@echo "_________________________________________________\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@echo "$(Y)- Compiling $<...$(DEF)"
				@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
				@echo "_________________________________________________"
				@echo "$(G)\n--- Creating libft...\n$(DEF)"
				@$(MAKE) -C libft --no-print-directory
				@echo "_________________________________________________"
				@echo "$(G)\n--- Creating $(NAME_BONUS)...\n$(DEF)"
				@$(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a -o $(NAME_BONUS)
				@echo "$(NEON_GREEN)      .-------------------------------------. $(DEF)"
				@echo "$(NEON_GREEN)     (   $(NAME_BONUS) compiled succesfully!   ) $(DEF)"
				@echo "$(NEON_GREEN)      '-------------------------------------' $(DEF)"
				@echo "_________________________________________________\n"

$(OBJS_DIR_BONUS)%.o: $(SRCS_DIR_BONUS)%.c
				@mkdir -p $(dir $@)
				@echo "$(Y)- Compiling $<...$(DEF)"
				@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c -o $@ $<

clean:
				@$(MAKE) -C libft --no-print-directory clean
				@echo "_________________________________________________"
				@echo "$(ORANGE)\n--- Cleaning objects files...\n$(DEF)"
				@$(RM) $(OBJS_DIR)
				@$(RM) $(OBJS_DIR_BONUS)
				@echo "$(R)            * Objects files cleaned!$(DEF)"
				@echo "_________________________________________________\n"

fclean: clean
				@$(MAKE) -C libft --no-print-directory fclean
				@echo "_________________________________________________"
				@echo "$(ORANGE)\n--- Cleaning programs...\n$(DEF)"
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)
				@echo "$(R)            * Programs Cleaned!$(DEF)"
				@echo "_________________________________________________\n"

re: fclean $(NAME)

re_bonus: fclean $(NAME_BONUS)

.PHONY: all clean fclean re bonus re_bonus