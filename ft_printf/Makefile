NAME = libftprintf.a
CC = CC
CFLAGS = -Wall -Wextra -Werror
INCL = printf.h
SRCS = new_printf.c \
	printf_utils.c \
	put_dec_to_hex.c \
	put_nbr.c \
	put_pointer.c \
	put_string.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(INCL)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
