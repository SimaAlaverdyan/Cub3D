NAME			=	cub3D

SRC				=	$(wildcard ./src/*.c)

HEAD			=	include/cub3d.h

LIBFT			=	libft/libft.a

OBJS			=	${SRC:.c=.o}

MLX_FLAGS		=	-lmlx -framework OpenGL -framework AppKit -lm

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -g -I $(HEAD)

.c.o			:
					${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS} ${LIBFT} ${HEAD}
					make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${MLX_FLAGS} ${OBJS} -o ${NAME} $(LIBFT) 


$(LIBFT)		:
					make -C ./libft

all				:	${NAME}


clean			:
					make clean -C mlx
					make clean -C libft
					@rm -rf ${OBJS}

fclean			:	clean
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re

NY			:	all clean fclean re
