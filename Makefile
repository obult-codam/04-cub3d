
NAME		= cub3d
PARSER		= parsing/pars_file parsing/split_map_str parsing/check_map_walls\
				textures/load_textures \
				utils/null_strjoin utils/print_map
ENGINE		= ray ray_utils frame_render render_utils movement draw tomato_factory
OBJ			= $(addprefix engine/, ${ENGINE}) ${PARSER} main
OBJS		= $(addsuffix .o, $(addprefix obj/, ${OBJ}))
CC			= gcc
RM			= rm -f
HEADER		= -I includes/ -I lib/mlx42/include/MLX42/
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address
LINKFLAGS	= -lglfw -ldl -lm -O3 -L "/Users/$(USER)/.brew/opt/glfw/lib/"
LIBMLX		= ./lib/mlx42

all:		${NAME}

${NAME}:	${OBJS} lib/libft/libft.a lib/MLX42/libmlx42.a
				${CC} $^ $(CFLAGS) ${LINKFLAGS} -o $@
				$(info ************  cub 3d ed Ready!)

lib/MLX42/libmlx42.a:
				$(MAKE) -C ${LIBMLX}

lib/libft/libft.a:
				$(MAKE) -C lib/libft

obj/%.o:	src/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) $(HEADER) -c -o $@ $<

clean:
				@${RM} ${OBJS}
				@${RM} ${RAY_TEST_OBJS}
				@$(MAKE) -C $(LIBMLX) clean
				@$(MAKE) -C lib/libft clean
				$(info ************  cub 3d ed Clean)

fclean:		clean
				@${RM} ${NAME}
				@${RM} test
				@$(MAKE) -C $(LIBMLX) fclean
				@$(MAKE) -C lib/libft fclean
				$(info ************  cub 3d ed Removed)

re:			fclean all

run:		all
				./${NAME} working.cub

.PHONY: all clean fclean re
