NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
FILES = ft_itoa.c \
		ft_printf.c \
		printf_utils.c \
		printf_utils2.c

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	$(CC) $(CFLAGS) $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


test:
	echo "hi, I am working as test"

f : fclean

.PHONY = f re all fclean clean 
