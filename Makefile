NAME = cub3d

SRCS = main.c get_next_line.c get_next_line_utils.c \
		parser.c ft_putchars.c ft_move.c put_window.c \
		put_text.c ft_setfloorcollor.c setdata.c

#SRCO = $(SRCS:.c=.o)

all: $(SRCO)
	cd ./libft && make bonus && cd ..
	#gcc -c -g $(SRCS)
	gcc $(SRCS) libmlx.dylib -g -framework OpenGL -framework Appkit libft/libft.a 

clean:
	#/bin/rm -f $(SRCO)
	cd ./libft && make fclean && cd ..

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) clean fclean re