# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkacie <mkacie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 22:50:41 by mkacie            #+#    #+#              #
#    Updated: 2021/01/30 15:48:22 by mkacie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libftprintf.a

DIR = file/

SRC =	ft_helper.c\
		ft_libft.c\
		ft_printf.c\
		ft_type_c.c\
		ft_type_i_d.c\
		ft_type_s.c\
		ft_type_u.c\
		ft_type_p.c\
		ft_type_x.c


SOURCE = $(addprefix $(DIR), $(SRC))

OBJECT = $(patsubst %.c, %.o, $(SOURCE))

D_FILE = $(patsubst %.c, %.d, $(SOURCE))

HEADER = -I ./incl/

FLAGS = -Wall -Werror


all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $?
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) $(HEADER) -c $< -o $@ -MD

clean:
	rm -f $(OBJECT) $(D_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all

include $(wildcard $(D_FILE))

.PHONY: all clean fclean re bonus

test: 
	gcc -g3 $(FLAGS) $(HEADER) $(SOURCE) main.c