#MAKEFLAGS += --silent

NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -Wpedantic 
INC_DIR = includes/
INC = push_swap.h

SRC_DIR = src/
SRC =	main.c\
		push_swap.c\
		push_swap2.c\
		stack_a.c\
		stack_b.c

LIBRARY_DIR = ./

LIBFT_DIR = $(LIBRARY_DIR)libft/
LIBFT_INC_DIR = $(LIBFT_DIR)includes/
LIBFT_INC = -I $(LIBFT_INC_DIR) $(LIBFT_DIR)libft.a

OBJ_DIR = .obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

ARGS = 8 2 1 18272 62 71 9 29 87 65 10 27 872 762 12 37 28 198 26 73 88

.PHONY : all clean fclean re $(LIBFT_DIR) exec

all: $(LIBFT_DIR) $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_INC) -I $(INC_DIR) -lm

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(addprefix $(INC_DIR),$(INC))
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_INC_DIR) -I $(INC_DIR)

$(LIBFT_DIR):
	$(MAKE) -C $(LIBFT_DIR)

exec:
	./$(NAME) $(ARGS)

norm:
	norminette $(SRC_DIR)$(SRC) $(INC_DIR)$(INC)

clean:
	/bin/rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	/bin/rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all
