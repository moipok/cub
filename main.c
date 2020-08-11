
#include "cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void	ft_putwindow(t_data *img)
{
	int i;
	int j;

	i = 0;
	while(img->arr[i])
	{
		j = 0;
		while(img->arr[i][j])
		{
			if (img->arr[i][j] == '1')
				my_mlx_pixel_put(img, j+50, i+50, 0xFFFFFF);
			else if (img->arr[i][j] == 'N')
				my_mlx_pixel_put(img, j+50, i+50, 0xFF0FFF);
			else if (img->arr[i][j] == '2')
				my_mlx_pixel_put(img, j+50, i+50, 0xFFFF0F);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}


char **ft_w(t_data *img)
{
	int i;
	int j;

	while (i < ft_arrlen(img->arr))
	{
		while (j < ft_strlen(img->arr[i]))
		{
			if (img->arr[i][j] == 'N' && img->arr[i - 1][j])
				img->arr[i-1][j] = '1';
			j++;
		}
		i++;
	}
	return(img->arr);
}

int		render_next_frame(t_data *img)
{
	if (1)
	{
	my_mlx_pixel_put(img, 50, 50, 0x000AAA);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	// img->arr = ft_w(img);
	// ft_putwindow(img);
	}
	return (0);
}

int             ft_close(int keycode, t_data *img)
{
	if (keycode == 53)
		mlx_destroy_window(img->mlx, img->win);
	else if (keycode == 12)
	{
	my_mlx_pixel_put(img, 50, 50, 0x000AAA);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
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
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_loop(img.mlx);
	return (0);
}