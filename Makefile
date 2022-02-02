CC		= clang
CFLAGS	= -Wall -Wextra -Werror

INCS		= incs/pipex.h
INCS_PATH	= incs
SRCS_PATH	= srcs
OBJS_PATH	= .obj
VPATH		= srcs

SRCS	 =	ft_get_path.c		\
			main.c				\
			ft_check_access.c	\
			ft_get_command.c	\

LIBFT_AR	=	./libft/libft.a

OBJ		= $(SRCS:.c=.o)
OBJS	= $(addprefix $(OBJS_PATH)/, $(OBJ))

NAME	= pipex

all : libft $(NAME)

libft:
	@make -C ./libft --no-print-directory

$(OBJS_PATH)/%.o: %.c $(INCS) Makefile
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

.PHONY: all libft mlx clean fclean re