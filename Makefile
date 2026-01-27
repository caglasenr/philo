NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c \
       parsing.c \
       utils.c 

OBJS = $(SRCS:.c=.o)
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re