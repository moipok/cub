
#include "cub3d.h"


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

t_data			*ft_first_angle(t_data *img)
{
	double c;  
	double x;
	double y;
	int xx;
	int yy;
	img->mainangle = M_PI;

	c = 1;
	while (c)
	{
		x = img->x + c * cos(img->mainangle);
    	y = img->y + c * sin(img->mainangle);
		xx = (int)x;
		yy = (int)y;
		my_mlx_pixel_put(img, yy + 50, xx + 50, 0xFFFF0F);
    	if (img->map[xx][yy] == '1') 
			break;
		c = c + 0.1;
	}
	return (img);
}

void	ft_putwindow(t_data *img)
{
	int i;
	int j;

	img->img = mlx_new_image(img->mlx, 640, 480);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	i = 0;
	while(img->arr[i])
	{
		j = 0;
		while(img->arr[i][j])
		{
			if (img->arr[i][j] == '1')
				my_mlx_pixel_put(img, j+50, i+50, 0xFFFFFF);
			else if (img->arr[i][j] == '2')
				my_mlx_pixel_put(img, j+50, i+50, 0xFFFF0F);
			j++;
		}
		i++;
	}
	img = ft_first_angle(img);
	my_mlx_pixel_put(img, img->y + 50, img->x + 50, 0xFF0FFF);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}


void			ft_putred(t_data *img)
{
	int i;
	int j;

	img->img = mlx_new_image(img->mlx, 640, 480);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	i = 0;
	while (i<200)
	{
		j = 50;
		while (j<250)
		{
			my_mlx_pixel_put(img, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int             ft_close(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(1);
	}
	else if (keycode == 13)
	{
		img = ft_w(img);
		//ft_putred(img);
		ft_putwindow(img);
	}
	else if (keycode == 1)
	{
		img = ft_s(img);
		//ft_putred(img);
		ft_putwindow(img);
	}
	else if (keycode == 2)
	{
		img = ft_d(img);
		//ft_putred(img);
		ft_putwindow(img);
	}
	else if (keycode == 0)
	{
		img = ft_a(img);
		//ft_putred(img);
		ft_putwindow(img);
	}
	else
		printf("%d\n", keycode);
	return (0);
}


int		main(int argc, char **argv)
{
	int i;
	int j;
    t_data  img;

	img.mlx = NULL;
	img.win = NULL;
	ft_parser(argc, argv, &img);
	i = 0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 640, 480, "test");
	img.img = mlx_new_image(img.mlx, 640, 480);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_putwindow(&img);
	mlx_hook(img.win, 2, 1L<<0, ft_close, &img);
	mlx_loop(img.mlx);
	return (0);
}