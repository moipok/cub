/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:24 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/17 23:20:14 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include "minilibx_mms/mlx.h"
#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

typedef struct		s_xpm
{
    void			*mlx;
    char			*addr;
    int				bits_per_pixel;
    int				line_length;
    int				endian;
	int				height;
	int				width;
	char			name;
}					t_xpm;

typedef struct		s_flags
{
    int				noflag;
	int				soflag;
	int				weflag;
	int				eaflag;
	int				spriteflag;
	int				r1flag;
	int				cellarflag;
	int				floorflag;
	int				allflag;
}					t_flags;


typedef struct		s_sprite
{
	double 			x;
	double 			y;
	double			average;
	double			angle;
}					t_sprite;

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
	double			x;
	double			y;
	double			mainangle;
	int				r1;
	int				r2;
	int				coef;
	int				fulldata;
	char			*sprite;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				cellar;
	int				floor;
	int				num;
	t_xpm			*notext;
	t_xpm			*sotext;
	t_xpm			*wetext;
	t_xpm			*eatext;
	t_xpm			*spritetext;
	t_sprite		*spr;
	double			*deep;
}					t_data;


void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char *s);
void		ft_parser(int argc, char **argv, t_data *img);
int			ft_arrlen(char **arr);
t_data		*ft_w(t_data *img);
t_data		*ft_s(t_data *img);
t_data		*ft_a(t_data *img);
t_data		*ft_d(t_data *img);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data		*ft_first_angle(t_data *img);
void		ft_putwindow(t_data *img);
void		ft_putwindow_3d(t_data *img);
void 		put_texture(t_data *data);
int			get_collor(t_xpm *data, int x, int y);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 		ft_setfloorcollor(char **str);
void		setdata(char **str, t_data *img, t_flags *flag);
int 		fl_sumflag(t_flags *flag);
void		ft_cleanflag(t_flags *flag);
void		freemass(char **str);
void		ft_lstfree(t_list **list);
int			ft_arrlen(char **arr);
int			ft_maxlenarr(char **arr);
int			ft_checkmap(char **map, double x);
void		ft_putsprite(t_data *img);
double		correctangle(double angle);
double		correctangle1(double angle, double mainangle);
char		*setno(char **str, t_flags *flag);
char		*setwe(char **str, t_flags *flag);
char		*setea(char **str, t_flags *flag);
char		*setso(char **str, t_flags *flag);
char		*setsprite(char **str, t_flags *flag);
double		ft_foundpixel(int jj,int end, double pixelhiegt, int r2);
t_xpm		*ft_findwall(t_data *img, double c, double x, double y, double angle1);
double		ft_findpartofwall(char wall, double x, double y);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			get_collor(t_xpm *data, int x, int y);
int		check_elem(double x, double y, t_sprite *spr, double s);
int		**ft_malloc_arrayint(int i, int j);
void	freeintmass(int **arr, int i, int j);
void	null_mas(t_sprite *spr, int i);
void bubblesort(t_sprite *spr, int size);
double	correctangle(double angle);
double	correctangle1(double angle, double mainangle);
int		get_t(int trgb);
double	ft_angle(char c);

#endif