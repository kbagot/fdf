# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 18:09:03 by kbagot            #+#    #+#              #
#    Updated: 2017/01/16 18:11:24 by kbagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror -Wextra
O_FILES = main.o fdfill.o stock_map.o
OPEN_GL = -lmlx -framework OpenGL -framework AppKit
HEADER_LIBFT = -I libft/includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
		make -C libft/ fclean && make -C libft/
		gcc $(FLAGS) $(HEADER_LIBFT) -o main.o -c main.c
		gcc $(HEADER_LIBFT) -o fdfill.o -c fdfill.c
		gcc $(HEADER_LIBFT) -o stock_map.o -c stock_map.c
		gcc $(OPEN_GL) -o $(NAME) $(O_FILES) $(HEADER_LIBFT) -L libft/ -lft
clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
