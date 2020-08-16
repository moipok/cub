
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
	double *arrangle;
	double angle1;
	double angle2;

	angle1 = img->mainangle - M_PI_4;
	angle2 = img->mainangle + M_PI_4;
	while (angle1 < angle2)
	{
		c = 1;
		while (c)
		{
			x = img->x + c * cos(angle1);
			y = img->y + c * sin(angle1);
			xx = (int)x;
			yy = (int)y;
			my_mlx_pixel_put(img, yy + 50, xx + 50, 0xFF5F00);
		 	if (img->map[xx][yy] == '1') 
				break;
			c = c + 0.5;
		}
		angle1 += 0.01;
	}
	return (img);
}

void	ft_putwindow(t_data *img)
{
	int i;
	int j;

	img->img = mlx_new_image(img->mlx, img->r1, img->r2);
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

void ft_putline(t_data *img, int i, double c)
{
	double j;
	int jj;
	int a;

	j = (4 / c) * img->r2;
	if (i >= img->r1)
		return ;
	if (j > 480)
		j = 450;
	jj = (int)j;
	printf("%d, %f, %d\n", i, c, jj);
	while (jj)
	{
		my_mlx_pixel_put(img, i + 1, (img->r2 / 2) + jj - 2, 0xFFFFFF);
		jj = jj - 1;
	}
	a = 0;
	jj = (int)j;
	printf("%d, %f, %d\n", i, c, jj);
	while (a < jj)
	{
		my_mlx_pixel_put(img, i + 1, (img->r2 / 2) - a + 2, 0xFFFFFF);
		a++;
	}
	a = 100;
	while (a)
	{
		jj = 50;
		while (jj)
		{
			my_mlx_pixel_put(img, a + 10, jj + 10, 0xFFF0FF);
			jj--;
		}
		a--;
	}
}

t_data *ft_putcol(t_data *img)
{
	double c;  
	double x;
	double y;
	int xx;
	int yy;
	double *arrangle;
	double angle1;
	double angle2;
	int i;

	angle1 = img->mainangle - M_PI_4;
	angle2 = img->mainangle + M_PI_4;
	i = 0;
	while (angle1 < angle2)
	{
		c = 1;
		while (c)
		{
			x = img->x + c * cos(angle1);
			y = img->y + c * sin(angle1);
			xx = (int)x;
			yy = (int)y;
		 	if (img->map[xx][yy] == '1') 
			{
				ft_putline(img, i, c);
				i++;
				break;
			}
			c = c + 0.5;
		}
		angle1 += M_PI_2 / img->r1;
	}
	return (img);
}

void	ft_putwindow_3d(t_data *img)
{
	int i;
	int j;

	img->img = mlx_new_image(img->mlx, img->r1, img->r2);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	img = ft_putcol(img);
	my_mlx_pixel_put(img, img->y + 50, img->x + 50, 0xFF0FFF);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}