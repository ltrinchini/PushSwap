# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 10:45:40 by ltrinchini        #+#    #+#              #
#    Updated: 2023/05/01 11:01:43 by ltrinchini       ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_WITHOUT_PATH =	main.c \
					tool_functions.c \
					functions_init.c

ALGO_WITHOUT_PATH = ft_sort_big.c \
					ft_sort.c \
					ft_val.c \
					functions_check_1.c \
					functions_check_2.c 

INST_WITHOUT_PATH =	operations.c \
					pa.c \
					pb.c \
					ra.c \
					rb.c \
					rra.c \
					rrb.c \
					sa.c \
					sb.c
		
OBJS_SRCS_WITHOUT_PATH = $(SRCS_WITHOUT_PATH:.c=.o)
OBJS_ALGO_WITHOUT_PATH = $(ALGO_WITHOUT_PATH:.c=.o)
OBJS_INST_WITHOUT_PATH = $(INST_WITHOUT_PATH:.c=.o)

HEADER_WITHOUT_PATH = push_swap.h

PATH_TO_SRCS = ./srcs/
PATH_TO_ALGO = ./srcs/algo/
PATH_TO_INST = ./srcs/instructions/

SRCS = $(addprefix $(PATH_TO_SRCS), $(SRCS_WITHOUT_PATH))
ALGO = $(addprefix $(PATH_TO_ALGO), $(ALGO_WITHOUT_PATH))
INST = $(addprefix $(PATH_TO_INST), $(INST_WITHOUT_PATH))

OBJS_SRCS = $(addprefix $(PATH_TO_OBJS), $(OBJS_SRCS_WITHOUT_PATH))
OBJS_ALGO = $(addprefix $(PATH_TO_OBJS), $(OBJS_ALGO_WITHOUT_PATH))
OBJS_INST = $(addprefix $(PATH_TO_OBJS), $(OBJS_INST_WITHOUT_PATH))

OBJS =	$(OBJS_SRCS) \
		$(OBJS_ALGO) \
		$(OBJS_INST)

PATH_TO_HEADER = ./headers/
PATH_TO_OBJS = ./objs/

HEADER = $(addprefix $(PATH_TO_HEADER), $(HEADER_WITHOUT_PATH))

	######### COMMANDS ###########
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
	################################

	######### RESSOURCES ###########

		###### LIBFT ######
PATH_TO_LIBFT = ./libft/
LIBFT_A = $(PATH_TO_LIBFT)libft.a
		#################

	################################

	####### COLORS FOR PRINTF #######
GREEN 		= \033[0;32m
RED			= \033[0;91m
YELLOW      = \033[0;93m
WHITE       = \033[1;49;97m
	#################################


all: rsc $(PATH_TO_OBJS) $(NAME)
	printf "\n$(GREEN)✅ $(NAME) is up to date$(WHITE) 👏\n"

rsc:
	make -C $(PATH_TO_LIBFT)

$(PATH_TO_OBJS):
	mkdir -p $(PATH_TO_OBJS)

$(LIBFT_A): rsc

$(OBJS_SRCS):$(PATH_TO_OBJS)%.o	: $(PATH_TO_SRCS)%.c Makefile $(HEADER) $(LIBFT_A)
	printf "\033[2K\r$(YELLOW)⏳ Compiling:$(WHITE) $< 🤞"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_ALGO):$(PATH_TO_OBJS)%.o : $(PATH_TO_ALGO)%.c Makefile $(HEADER) $(LIBFT_A) $(LIBMLX_A)
	printf "\033[2K\r$(YELLOW)⏳ Compiling:$(WHITE) $< 🤞"
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJS_INST):$(PATH_TO_OBJS)%.o : $(PATH_TO_INST)%.c Makefile $(HEADER) $(LIBFT_A) $(LIBMLX_A)
	printf "\033[2K\r$(YELLOW)⏳ Compiling:$(WHITE) $< 🤞"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LIBMLX_A) -o $(NAME)

git: fclean
	git add *
	git add -u
	git commit

clean:
	make clean -C $(PATH_TO_LIBFT)
	$(RM) $(PATH_TO_OBJS)
	printf "$(RED)👌 Files has been deleted in $(PATH_TO_OBJS) ($(NAME))$(WHITE)\n"
	printf "$(GREEN)✅ Clean 👍$(WHITE)\n"

fclean: clean
	$(RM) $(LIBFT_A)
	$(RM) $(NAME)
	printf "$(RED)👌 libmlx.a has been deleted$(WHITE)\n"
	printf "$(RED)👌 libft.a has been deleted$(WHITE)\n"
	printf "$(RED)👌 $(NAME) has been deleted$(WHITE)\n"

re: fclean all
.PHONY: all rsc git clean fclean re
.SILENT:
