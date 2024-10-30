NAME = philo

CC = cc -Werror -Wall -Wextra -g

CC_FLG = -lpthread

RM = rm -f

SRCS_PATH = ./philo/

SRCS_FILES = error.c ft_atoi.c init_func.c main.c play_philo.c play_thread.c print.c time.c

SRCS = $(SRCS_FILES)

SRCS_OBJS = $(SRCS:.c=.o)

.PHONY: all re clean fclean

all: ${NAME}

.c.o:
	${CC} -c $< -o $@

${NAME}:${SRCS_OBJS}
	${CC} ${CC_FLG} $^ -o $@

clean:
	${RM} ${SRCS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
