# push_swap
NAME				=	push_swap
PUSHSWAP			=	push_swap.a
PUSHSWAP_SRC		=	push_swap.c \
						print_stacks.c \
						ft_actions.c \
						random_staks.c \
OBJS			= $(PUSHSWAP_SRC:.c=.o)

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Other vars
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Commands
all:		$(LIBFT) $(NAME)
			@printf "Push_swap compiled ✅\n"

$(LIBFT):
			@make -C libft

$(NAME):			$(OBJS)
					ar rcs $(OBJS)
					$(CC) $(CFLAGS) $(PUSHSWAP) random_staks.c $(LIBFT_SRC)$(LIBFT) -o $(PUSHSWAP)
					@printf "Push_swap compiled ✅\n\n"

clean:
			@$(RM) $(PUSHSWAP) $(PUSHSWAP)
			@printf "\nRemoved push_swap 🗑️\n"

fclean:		clean
			@make -C libft fclean

re:			fclean all
			@printf "Push_swap recompiled 🔄\n"

.PHONY:		all clean fclean re