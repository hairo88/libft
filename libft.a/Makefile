NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = 

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

.c.o:
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all