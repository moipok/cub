#include "cub3d.h"

t_data	*ft_w(t_data *img)
{
	double x;
	double y;
	int	xx;
	int yy;

	x = img->x + 4 * cos(img->mainangle);
	y = img->y + 4 * sin(img->mainangle);
	xx = (int)x;
	yy = (int)y;
	if (img->map[xx][yy] != '1') 
	{
		img->x = xx;
		img->y = yy;
	}
	return (img);
}


t_data	*ft_s(t_data *img)
{
	double x;
	double y;
	int	xx;
	int yy;

	x = img->x + 4 * cos(img->mainangle - M_PI);
	y = img->y + 4 * sin(img->mainangle - M_PI);
	xx = (int)x;
	yy = (int)y;
	if (img->map[xx][yy] != '1') 
	{
		img->x = xx;
		img->y = yy;
	}
	return (img);
}


t_data	*ft_d(t_data *img)
{
	double x;
	double y;
	int	xx;
	int yy;

	x = img->x + 4 * cos(img->mainangle - M_PI_2);
	y = img->y + 4 * sin(img->mainangle - M_PI_2);
	xx = (int)x;
	yy = (int)y;
	if (img->map[xx][yy] != '1') 
	{
		img->x = xx;
		img->y = yy;
	}
	return (img);
}

t_data	*ft_a(t_data *img)
{
	double x;
	double y;
	int	xx;
	int yy;

	x = img->x + 4 * cos(img->mainangle + M_PI_2);
	y = img->y + 4 * sin(img->mainangle + M_PI_2);
	xx = (int)x;
	yy = (int)y;
	if (img->map[xx][yy] != '1') 
	{
		img->x = xx;
		img->y = yy;
	}
	return (img);
}