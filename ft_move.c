#include "cub3d.h"

t_data	*ft_w(t_data *img)
{
	if (img->map[img->x - 1][img->y] != '1')
		img->x = img->x - 1;
	return (img);
	printf("(%d, %d,)\n", img->x, img->y);
}


t_data	*ft_s(t_data *img)
{
	if (img->map[img->x + 1][img->y] != '1')
		img->x = img->x + 1;
	return (img);
	printf("(%d, %d,)\n", img->x, img->y);
}


t_data	*ft_d(t_data *img)
{
	if (img->map[img->x][img->y + 1] != '1')
		img->y = img->y + 1;
	return (img);
	printf("(%d, %d,)\n", img->x, img->y);
}

t_data	*ft_a(t_data *img)
{
	if (img->map[img->x][img->y - 1] != '1')
		img->y = img->y - 1;
	return (img);
	printf("(%d, %d,)\n", img->x, img->y);
}