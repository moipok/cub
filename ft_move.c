#include "cub3d.h"

void	ft_w(t_data *img)
{
	int i;
	int j;

	i = 0;
	while (i < ft_arrlen(img->arr))
	{
		j = 0;
		while (j < ft_strlen(img->arr[i]))
		{
			if (img->arr[i][j] == 'N' && img->arr[i - 1][j])
				img->arr[i-1][j] = 'N';
			if (img->arr[i][j] != 'N' && img->arr[i - 1][j] == 'N')
				img->arr[i - 1][j] = img->map[i-1][j];
			j++;
		}
		i++;
	}
}

void	ft_s(t_data *img)
{
	int i;
	int j;

	i = 0;
	while (i < ft_arrlen(img->arr))
	{
		j = 0;
		while (j < ft_strlen(img->arr[i]))
		{
			if (img->arr[i][j] != 'N' && img->arr[i + 1][j] == 'N')
				img->arr[i + 1][j] = img->map[i-1][j];
			if (img->arr[i][j] == 'N' && img->arr[i + 1][j])
				img->arr[i+1][j] = 'N';
			j++;
		}
		i++;
	}
}