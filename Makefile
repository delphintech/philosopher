CC = cc
CFLAGS += -Werror -Wall -Wextra -MMD -pthread -fsanitize=thread

NAME = philo

SRCS += main.c \
	utils/ft_atoi.c \
	utils/utils.c \
	utils/philo_struct.c \
	utils/fork_struct.c \
	utils/life.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all	:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean	:
	rm -f $(OBJS) $(DEPS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY: all clean fclean re
-include DEPS

# --------------------------------------------------------------------------------------

DBGFLAGS = "-g3 -pthread -fsanitize=thread"

ARG = ""

run : $(NAME)
	./$(NAME) $(ARG)

# Pour le developpement
debug :  $(SRCS)             ## Permet de debuger le code avec lldb
	$(CC) ${DBGFLAGS} -o $(NAME) $(SRCS)
	lldb ./$(NAME) $(ARG)

val :                       ## Lance le check valgrind
	$(CC) ${DBGFLAGS} -o $(NAME) $(SRCS)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARG)
