#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include "minilibx_mms/mlx.h"
#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct		s_data 
{
    void			*mlx;
    void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			**arr;
	char			**map;
}					t_data;


void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void    ft_parser(int argc, char **argv, t_data *img);
int		ft_arrlen(char **arr);
void	ft_w(t_data *img);
void	ft_s(t_data *img);
void	ft_a(t_data *img);
void	ft_d(t_data *img);

#endif