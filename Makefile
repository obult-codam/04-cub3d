
NAME		= cub3d
OBJ			= ray ray_utils
OBJS		= $(addsuffix .o, $(addprefix obj/, ${OBJ}))
RAY_TEST_OBJS	= ${OBJS} obj/ray_test.o
CC			= gcc
RM			= rm -f
HEADER		= -I includes/ 
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g

all:		${NAME}

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
				$(info ************  cub 3d ed Removed)

re:			fclean all

raytest:		${RAY_TEST_OBJS}
				@${CC} ${RAY_TEST_OBJS} $(CFLAGS) -o test
				./test

${NAME}:	${OBJS}
				@${CC} $(OBJS) $(CFLAGS) -o $@
				$(info ************  cub 3d ed Ready!)

.PHONY: all clean fclean re