# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 09:30:37 by aben-ham          #+#    #+#              #
#    Updated: 2022/04/19 22:05:29 by hbourkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTIL_FILES = \
	utils/ft_arrlen.c \
	utils/ft_isalnum.c \
	utils/ft_isalpha.c \
	utils/ft_substr.c \
	utils/ft_atoi.c \
	utils/is_int.c \
	utils/ft_memchr.c \
	utils/ft_memcmp.c \
	utils/ft_memcpy.c \
	utils/ft_memmove.c \
	utils/ft_memset.c \
	utils/ft_putstr.c \
	utils/ft_putstr_fd.c \
	utils/ft_split.c \
	utils/ft_isdigit.c \
	utils/msk_split.c \
	utils/ft_strchr.c \
	utils/ft_strdup.c \
	utils/ft_strjoin.c \
	utils/ft_strlcpy.c \
	utils/ft_strlen.c \
	utils/ft_strncmp.c \
	utils/ft_strnstr.c \
	utils/ft_strrchr.c \
	utils/ft_error.c \
	utils/ft_error_exit.c \
	utils/ft_malloc.c \
	utils/ft_strcmp.c \
	utils/queue_c/q_clear.c \
	utils/queue_c/q_dequeue.c \
	utils/queue_c/q_enqueue.c \
	utils/queue_c/q_init.c \
	utils/ft_itoa.c \
	utils/file_error.c

EXECUTION_FILES = \
	execution/set_exit_status.c \
	execution/exec_cmd.c \
	execution/exec_utils.c \
	execution/builtins_utils.c \
	execution/other_utils.c \
	execution/io_operations.c \
	execution/builtins/ft_cd.c \
	execution/builtins/ft_echo.c \
	execution/builtins/ft_exit.c \
	execution/builtins/ft_export.c \
	execution/builtins/ft_pwd.c \
	execution/builtins/ft_unset.c \
	execution/builtins/ft_env.c \
	

PARSING_FILES = \
	parser/parser.c \
	parser/expansion.c \
	parser/check_sysntax.c \
	parser/get_structure.c \
	parser/expand.c \
	parser/signals.c \
	parser/ft_getenv.c \
	parser/redirection_type.c \
	parser/io_files/close_files.c \
	parser/io_files/open_files_utils.c \
	parser/io_files/open_files.c

FILES = \
	$(UTIL_FILES) \
	$(EXECUTION_FILES) \
	$(PARSING_FILES) \
	main.c

#-Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror  -I includes/
FLAGS = -lreadline -L ~/homebrew/opt/readline/lib -I ~/homebrew/opt/readline/include
# -fsanitize=address
DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = minishell

OBJ_DIR = _OUT/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc  $(OBJ) $(FLAGS) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:_OUT/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
