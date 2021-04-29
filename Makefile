# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: famacama <famacama@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 10:40:45 by famacama          #+#    #+#              #
#    Updated: 2020/11/28 21:46:49 by famacama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D 

LIB				= lib/

SRCS			= 	utils/get_next_line/get_next_line.c \
					utils/get_next_line/get_next_line_utils.c \
					srcs/ft_cub3d.c \
					parsing/parsing.c \


OBJS			= $(SRCS:.c=.o)

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

FLAGS			= -L $(LIB)libft -lft -L $(LIB)minilibx_opengl -lmlx -framework OpenGL -framework AppKit 

$(NAME) : 	$(OBJS)
			make -C $(LIB)libft 
			make -C $(LIB)minilibx_opengl
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}
			
all:			$(NAME)

clean:
			make clean -C $(LIB)libft
			make clean -C $(LIB)minilibx_opengl
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(LIB)libft
			make clean -C $(LIB)minilibx_opengl
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re