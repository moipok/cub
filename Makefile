NAME = cub3d

SRCS = main.c get_next_line.c get_next_line_utils.c \
		parser.c ft_putchars.c ft_move.c put_window.c \
		put_text.c ft_setfloorcollor.c setdata.c \
		parser_utils.c parser_check_map.c put_sprite.c \
		setdata_utils.c put_window_utils.c my_pixel_put.c \
		put_sprite_utils_1.c put_sprite_utils_2.c \
		parser_utils_1.c ft_putsprite.c inittexture.c \
		error1.c error2.c error3.c error4.c error5.c \
		ft_setfloorcollor_utils.c somefree.c mybmp.c \
		mybmp_utils.c put_screen.c 

#SRCO = $(SRCS:.c=.o)

all: $(SRCS)
	cd ./libft && make bonus && cd ..
	#gcc -c -g $(SRCS)
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME) libmlx.dylib -g -framework OpenGL -framework Appkit libft/libft.a

clean:
	/bin/rm -f $(SRCO)
	cd ./libft && make fclean && cd ..

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) clean fclean re