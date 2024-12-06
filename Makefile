NAME = push_swap

SRC = push_swap.c cal_cost.c cal_moves2.c find_targets.c linked_list_func.c moves_push.c moves_rotates.c \
	moves_swap.c process_rotates.c process_stacks.c sort.c validate_creat_linked_list.c
OBJS = ${SRC:.c=.o}

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

MAKE = make -C

all: ${NAME}

$(NAME) : ${OBJS}
				cc ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}
clean : 
				${RM} ${OBJS}

fclean : clean
				${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re