SRCS =	main.c argparser.c argchecker.c utils.c stackoperations.c swap_stack.c rotate_stack.c\
		reverse_rotate_stack.c push_stack.c sortshort.c sort.c sortutils.c

INC_DIR = ./libft

LIB_DIR = ./libft/libft.a

NAME = push_swap

CC = GCC

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m

all: $(NAME) title

$(NAME): $(SRCS)
	@clear
	@echo "Compailing please wait"
	@make -C $(INC_DIR)
	@make clean -C $(INC_DIR)
	@$(CC) $(CFLAGS) $(LIB_DIR) $(SRCS) -o $(NAME)

title:
	@clear 
	@echo "$(RED)███████▒  ██▒   ██▒  ██████▒  ██▒   ██▒  ██████▒  ██▒      ██▒  ██████▒  ███████▒  ";
	@echo "██  ▒▒██▒ ██ ▒  ██ ▒██  ▒▒██▒ ██ ▒  ██ ▒██  ▒▒██▒ ██ ▒ █▒  ██ ▒██  ▒▒██▒ ██  ▒▒██▒ ";
	@echo "██ ▒  ██ ▒██ ▒  ██ ▒██ ▒  ▒▒▒▒██ ▒  ██ ▒██ ▒  ▒▒▒▒██ ▒███▒ ██ ▒██ ▒  ██ ▒██ ▒  ██ ▒";
	@echo "███████  ▒██ ▒  ██ ▒▒██████▒  ████████ ▒▒██████▒  ██ ██ ██▒██ ▒████████ ▒███████  ▒";
	@echo "██  ▒▒▒▒▒ ██ ▒  ██ ▒ ▒▒▒▒▒██▒ ██  ▒▒██ ▒ ▒▒▒▒▒██▒ ████  ▒████ ▒██  ▒▒██ ▒██  ▒▒▒▒▒ ";
	@echo "██ ▒      ██ ▒  ██ ▒██▒   ██ ▒██ ▒  ██ ▒██▒   ██ ▒███  ▒ ▒███ ▒██ ▒  ██ ▒██ ▒      ";
	@echo "██ ▒      ▒██████  ▒▒██████  ▒██ ▒  ██ ▒▒██████  ▒██  ▒   ▒██ ▒██ ▒  ██ ▒██ ▒      ";
	@echo "▒▒▒▒       ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒ ▒▒▒▒  ▒▒▒▒ ▒▒▒▒▒▒▒▒ ▒▒▒▒     ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒      ";
	@echo "                                                                                   ";
	@echo "                                                  	$(BLUE)By Ahmet Abdullah CAN$(RESET)                                 ";
	@echo "                                                                                   ";
clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)
	@make fclean -C $(INC_DIR)

re: fclean all

.PHONY: all clean fclean re