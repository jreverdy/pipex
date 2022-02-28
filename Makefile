CC		= clang
CFLAGS	= -Wall -Wextra -Werror

INCS		= incs/pipex.h
INCS_PATH	= incs
SRCS_PATH	= srcs
OBJS_PATH	= .objs
VPATH		= srcs

SRCS	 =	main.c				\
			ft_get_path.c		\
			ft_check_access.c	\
			ft_get_command.c	\
			pipex.c				\

LIBFT_AR	=	./libft/libft.a

OBJS	= $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))

NAME	= pipex

all : libft $(NAME)

libft:
	@make -C ./libft --no-print-directory

$(OBJS_PATH)/%.o: %.c $(INCS) Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_AR)
	$(CC) $(OBJS) $(LIBFT_AR) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C ./libft

fclean: clean
	$(RM) $(LIBFT_AR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re