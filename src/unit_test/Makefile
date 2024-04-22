# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nledent <nledent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 17:54:43 by nledent           #+#    #+#              #
#    Updated: 2024/04/15 15:15:43 by nledent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-LIBFT-#

LIBFT			= ../../lib/libft
LIBFT_A			= ../../lib/libft/libft.a

#-LIBMLX-#

LIBMLX			= ../../lib/MLX42
LIBMLX_A		= $(LIBMLX)/build/libmlx42.a 
HEADERS			= -I ./include -I $(LIBMLX)/include

#-SRC-#

SRC			= 		\
					main.c \
					exit_fct.c \
					free_functions.c \
					colors.c\

OBJS			= $(SRC:%.c=%.o)

#-UTILS-#

CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror -Wunreachable-code -g
NAME 			= unit_test
RM 				= rm -f
RMR				= rm -rf

#-RULES-#

all:			$(NAME)

$(LIBMLX_A):
				@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT_A) :
				@make -C $(LIBFT)

%.o: %.c
				$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): 		$(OBJS) $(LIBFT_A) $(LIBMLX_A)
				@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LIBMLX_A) -ldl -lglfw -pthread -lm $(HEADERS) -o $(NAME)
				
clean:
			 	$(OBJS)
				@$(RMR) $(LIBMLX)/build
				@make -C $(LIBFT) clean

fclean: 		clean
				@$(RM) $(NAME)
				@make -C $(LIBFT) fclean

re:				fclean all

.PHONY : 		all clean fclean re bonus