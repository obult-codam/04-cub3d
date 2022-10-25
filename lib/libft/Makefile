# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: Ivellinga <izaakvellinga@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/11 22:02:50 by ieilat        #+#    #+#                  #
#    Updated: 2022/10/25 15:17:11 by obult         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER_FILES = libft.h printf.h
HEADER_DIR = includes
FLAGS = -Wall -Werror -Wextra -pedantic -g #-fsanitize=address -std=c89 
REG_SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_malloc_less_itoa.c ft_uns_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_long_atoi.c ft_iswhitespace.c ft_errors.c extention_check.c  \
free_arrays.c print_2d_array.c join3strings.c arrlen.c \
get_next_line.c get_next_line_utils.c \

BONUS_SRC = ft_lstnew.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
ft_lstmap.c

PRINTF_SRC = convert_char.c convert_hexidecimal.c convert_int.c \
convert_percent.c convert_pointer.c convert_string.c convert_uns_int.c \
format_print.c struct.c utils.c parse.c ft_printf.c


PRINTF_SRCS = $(addprefix ft_printf/, $(PRINTF_SRC))
BONUS_OBJ_FILES = $(BONUS_SRC:.c=.o)
REG_OBJ_FILES = $(REG_SRC:.c=.o)
PRINTF_OBJ_FILES = $(PRINTF_SRCS:.c=.o)



# ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJ_FILES) $(BONUS_OBJ_FILES) $(PRINTF_OBJ_FILES)
# else
# OBJ_FILES = $(REG_OBJ_FILES) $(PRINTF_OBJ_FILES)
# endif

all: $(NAME)

$(NAME): $(addprefix obj/, $(OBJ_FILES))
	@ar -rc $(NAME) $(addprefix obj/, $(OBJ_FILES))
# header files: -I includes
#       -I
#       includes

obj/%.o: %.c $(addprefix $(HEADER_DIR)/, $(HEADER_FILES))
	@mkdir -p $(dir $@)
	@$(CC) -c $(FLAGS) -I $(HEADER_DIR) -o $@ $<

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1 all

re: fclean all

.PHONY: all clean fclean re bonus
