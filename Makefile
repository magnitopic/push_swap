# push_swap
NAME				=	push_swap
						
PUSHSWAP_SRC		=	src/stack.c \
						src/helpers.c \
						src/push_swap.c \
						src/validator.c \
						src/dictionary.c \
						src/short_sort.c \
						src/modern_times.c \
						src/moves/ft_push.c \
						src/moves/ft_swap.c \
						src/moves/ft_rotate.c \
						src/moves/ft_reverse_rotate.c

OBJS			= $(PUSHSWAP_SRC:.c=.o)

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Colours
BLACK				=	\033[0;30m
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

# Rules
all:		$(LIBFT) $(NAME)
			@printf "$(BLUE)==> $(CYAN)Push_swap compiled ✅\n\n$(RESET)"

$(LIBFT):
			@make -C libft bonus

$(NAME):			$(OBJS)
					@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

clean:
			@$(RM) $(NAME) $(OBJS)
			@printf "\n$(BLUE)==> $(RED)Removed Push_swap 🗑️\n$(RESET)"

fclean:		clean
			@make -C libft fclean

re:			fclean all
			@printf "$(BLUE)==> $(CYAN)Push_swap recompiled 🔄\n$(RESET)"

.PHONY:		all clean fclean re
