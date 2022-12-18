# push_swap
PUSHSWAP			=	push_swap
PUSHSWAP_SRC		=	push_swap.c

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Other vars
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Commands
all:		$(LIBFT) $(PUSHSWAP)
			@printf "Minitalk compiled ✅\n"

bonus:		$(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)
			@printf "Minitalk bonus compiled ✅✨\n"

$(LIBFT):
			@make -C libft

$(PUSHSWAP):		$(PUSHSWAP_SRC)
					$(CC) $(CFLAGS) $(PUSHSWAP_SRC) random_staks.c $(LIBFT_SRC)$(LIBFT) -o $(PUSHSWAP)
					@printf "Push_swap compiled ✅\n\n"

clean:
			@$(RM) $(PUSHSWAP)
			@printf "\nRemoved push_swap 🗑️\n"

fclean:		clean
			@make -C libft fclean

re:			fclean all
			@printf "Push_swap recompiled 🔄\n"

.PHONY:		all clean fclean re