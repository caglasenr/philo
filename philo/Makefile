NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = cleanup.c \
	init.c \
	parsing.c \
	utils.c \
	main.c \
	time.c \
	print.c \
	monitoring.c \
	routine.c

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