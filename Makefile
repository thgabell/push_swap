CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap
BONUS	= checker

SRC_PATH 		= srcs/
PUSHSWAP_PATH	= push_swap/
CHECKER_PATH	= checker/
COMMON_PATH		= common/
GNL_PATH		= get_next_line/
OBJS_PATH 		= objs/

PUSHSWAP_SRC	= main.c \
				sort.c \
				positions.c \
				cost.c
CHECKER_SRC 	= main.c
COMMON_SRC		= input_check.c \
				initialize.c \
				utils.c \
				stack.c \
				stack_utils.c \
				rotate.c \
				swap.c \
				push.c \
				reverse_rotate.c
GNL_SRC			= get_next_line.c \
				get_next_line_utils.c

PUSHSWAP_OBJS	= $(addprefix $(OBJS_PATH)$(PUSHSWAP_PATH), $(PUSHSWAP_SRC:.c=.o))
CHECKER_OBJS 	= $(addprefix $(OBJS_PATH)$(CHECKER_PATH), $(CHECKER_SRC:.c=.o))
COMMON_OBJS		= $(addprefix $(OBJS_PATH)$(COMMON_PATH), $(COMMON_SRC:.c=.o))
GNL_OBJS		= $(addprefix $(OBJS_PATH)$(GNL_PATH), $(GNL_SRC:.c=.o))

INCS_PATH	= includes/
INCS_SRC	= push_swap.h checker.h common.h
INCS_ARGS	= -I./includes
INC_GNL		= -I./srcs/get_next_line

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: $(NAME) $(BONUS)

$(OBJS_PATH):
	@mkdir $@

$(OBJS_PATH)$(PUSHSWAP_PATH): | $(OBJS_PATH)
	@mkdir $@

$(OBJS_PATH)$(CHECKER_PATH): | $(OBJS_PATH)
	@mkdir $@

$(OBJS_PATH)$(COMMON_PATH): | $(OBJS_PATH)
	@mkdir $@

$(OBJS_PATH)$(GNL_PATH): | $(OBJS_PATH)
	@mkdir $@

$(NAME): $(OBJS_PATH)$(PUSHSWAP_PATH) $(PUSHSWAP_OBJS) $(OBJS_PATH)$(COMMON_PATH) $(COMMON_OBJS) $(LIBFTPRINTF)
	@gcc $(CFLAGS) $(LIBFTPRINTF) $(PUSHSWAP_OBJS) $(COMMON_OBJS) -o $@
	@echo "$(GREEN) Creating $@... $(NONE)"

$(BONUS): $(OBJS_PATH)$(CHECKER_PATH) $(CHECKER_OBJS) $(OBJS_PATH)$(COMMON_PATH) $(COMMON_OBJS) $(OBJS_PATH)$(GNL_PATH) $(GNL_OBJS) $(LIBFTPRINTF) $(INCS)
	@gcc $(CFLAGS) $(LIBFTPRINTF) $(CHECKER_OBJS) $(GNL_OBJS) $(COMMON_OBJS) -o $@
	@echo "$(GREEN) Creating $@... $(NONE)"
	
$(OBJS_PATH)$(PUSHSWAP_PATH)%.o: $(SRC_PATH)$(PUSHSWAP_PATH)%.c $(LIBFTPRINTF)
	@gcc $(CFLAGS) $(INCS_ARGS) $(INC_GNL) -o $@ -c $<
	@echo "Creating $@..."

$(OBJS_PATH)$(CHECKER_PATH)%.o: $(SRC_PATH)$(CHECKER_PATH)%.c $(LIBFTPRINTF)
	@gcc $(CFLAGS) $(INCS_ARGS) $(INC_GNL) -o $@ -c $<
	@echo "Creating $@..."

$(OBJS_PATH)$(COMMON_PATH)%.o: $(SRC_PATH)$(COMMON_PATH)%.c $(LIBFTPRINTF)
	@gcc $(CFLAGS) $(INCS_ARGS) $(INC_GNL) -o $@ -c $<
	@echo "Creating $@..."

$(OBJS_PATH)$(GNL_PATH)%.o: $(SRC_PATH)$(GNL_PATH)%.c $(LIBFTPRINTF)
	@gcc $(CFLAGS) $(INCS_ARGS) $(INC_GNL) -o $@ -c $<
	@echo "Creating $@..."

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Deleting $(OBJS_PATH)...$(NONE)"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@echo "$(RED)Deleting $(NAME) & $(BONUS)...$(NONE)"

re: fclean all

test2: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 2))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 3))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-10000 -n 5))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME) $(BONUS)
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test1000: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
