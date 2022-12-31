CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c \
		utils.c \
		input_check.c	\
		initialize.c \
		stack.c \
		# rotate.c swap.c push.c reverse_rotate.c\
		# positions.c cost.c \
		# tiny_sort.c big_sort.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)
	
fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all  clean fclean re
