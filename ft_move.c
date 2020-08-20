#include "cub3d.h"

t_data	*ft_w(t_data *img)
{
	double x;
	double y;

	x = img->x + 0.15 * cos(img->mainangle);
	y = img->y + 0.15 * sin(img->mainangle);
	if (img->map[(int)x][(int)y] != '1') 
	{
		img->x = x;
		img->y = y;
	}
	return (img);
}


t_data	*ft_s(t_data *img)
{
	double x;
	double y;

	x = img->x + 0.15 * cos(img->mainangle - M_PI);
	y = img->y + 0.15 * sin(img->mainangle - M_PI);
	if (img->map[(int)x][(int)y] != '1') 
	{
		img->x = x;
		img->y = y;
	}
	return (img);
}


t_data	*ft_d(t_data *img)
{
	double x;
	double y;

	x = img->x + 0.15 * cos(img->mainangle - M_PI_2);
	y = img->y + 0.15 * sin(img->mainangle - M_PI_2);
	if (img->map[(int)x][(int)y] != '1') 
	{
		img->x = x;
		img->y = y;
	}
	return (img);
}

t_data	*ft_a(t_data *img)
{
	double x;
	double y;

	x = img->x + 0.15 * cos(img->mainangle + M_PI_2);
	y = img->y + 0.15 * sin(img->mainangle + M_PI_2);
	if (img->map[(int)x][(int)y] != '1') 
	{
		img->x = x;
		img->y = y;
	}
	return (img);
}