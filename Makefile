
NAME		= cub3d
OBJ			= main ray ray_utils frame_render
OBJS		= $(addsuffix .o, $(addprefix obj/, ${OBJ}))
RAY_TEST_OBJS	= $(addsuffix .o, $(addprefix obj/, ray_test ray ray_utils))
CC			= gcc
RM			= rm -f
HEADER		= -I includes/ -I mlx42/include/MLX42/
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g
LIBS		= $(LIBMLX)/libmlx42.a
LINKFLAGS	= -lglfw -ldl -lm -O3 -L "/Users/$(USER)/.brew/opt/glfw/lib/"
LIBMLX		= ./mlx42

all:		libmlx ${NAME}

libmlx:
				@$(MAKE) -C $(LIBMLX)

obj/%.o:	src/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) $(HEADER) -c -o $@ $<

clean:
				@${RM} ${OBJS}
				@${RM} ${RAY_TEST_OBJS}
				$(info ************  cub 3d ed Clean)

fclean:		clean
				@${RM} ${NAME}
				@${RM} test
				@$(MAKE) -C $(LIBMLX) fclean
				$(info ************  cub 3d ed Removed)

re:			fclean all

raytest:		${RAY_TEST_OBJS}
				@${CC} ${RAY_TEST_OBJS} $(CFLAGS) -o test
				./test

${NAME}:	${OBJS}
				@${CC} $(OBJS) ${LIBS} $(CFLAGS) -o $@ ${LINKFLAGS}
				$(info ************  cub 3d ed Ready!)

run:		all
				./${NAME}

.PHONY: all clean fclean re