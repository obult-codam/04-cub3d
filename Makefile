
NAME		= cub3d
OBJ			= ray
OBJS		= $(addsuffix .o, $(addprefix obj/, ${OBJ}))
CC			= gcc
RM			= rm -f
HEADER		= -I includes/ 
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g -lm

all:		${NAME}

obj/%.o:	src/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) $(HEADER) -c -o $@ $<

clean:
				@${RM} ${OBJS} \
				$(info ************  cub 3d ed Clean)

fclean:		clean
				@${RM} ${NAME}
				$(info ************  cub 3d ed Removed)

re:			fclean all

run:		all
				./cub3d

${NAME}:	${OBJS}
				@${CC} $(OBJS) $(CFLAGS) -o $@
				$(info ************  cub 3d ed Ready!)

.PHONY: all clean fclean re