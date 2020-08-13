#include "cub3d.h"

void	ft_w(t_data *img)
{
	int i;
	int j;
	int ii;
	int jj;
	int arrlen;

	i = 0;
	arrlen = ft_arrlen(img->arr);
	jj = 0;
	ii = 0;
	while (i < arrlen)
	{
		j = 0;
		while (j < ft_strlen(img->arr[i]))
		{
			if (img->arr[i][j] == 'N' && img->map[i][j] != '1')
			{
				img->arr[i-1][j] = 'N';
				img->arr[i][j] = img->map[i][j]; 
				ii = i;
				jj = 0;
			}
			j++;
		}
		i++;
	}
	printf("(%d, %d,)\n", ii, jj);
}

void	ft_s(t_data *img)
{
	int i;
	int j;
	int jj;
	int ii;

	ii = 0;
	jj = 0;

	i = ft_arrlen(img->arr) - 1;
	while (i > 0)
	{
		j = ft_strlen(img->map[i]);
		while (j >= 0)
		{
			if (img->arr[i][j] == 'N' && img->map[i][j] != '1')
			{
				img->arr[i+1][j] = 'N';
				img->arr[i][j] = img->map[i][j]; 
				ii = i;
				jj = j;
			}
			j--;
		}
		i--;
	}
	printf("(%d, %d,)\n", ii, jj);
}

void	ft_d(t_data *img)
{
	int i;
	int j;
	int jj;
	int ii;

	ii = 0;
	jj = 0;

	i = ft_arrlen(img->arr) - 1;
	while (i > 0)
	{
		j = ft_strlen(img->map[i]);
		while (j >= 0)
		{
			if (img->arr[i][j] == 'N' && img->map[i][j] != '1')
			{
				img->arr[i][j + 1] = 'N';
				img->arr[i][j] = img->map[i][j]; 
				ii = i;
				jj = j;
			}
			j--;
		}
		i--;
	}
	printf("(%d, %d,)\n", ii, jj);
}

void	ft_a(t_data *img)
{
	int i;
	int j;
	int ii;
	int jj;
	int arrlen;

	i = 0;
	arrlen = ft_arrlen(img->arr);
	jj = 0;
	ii = 0;
	while (i < arrlen)
	{
		j = 0;
		while (j < ft_strlen(img->arr[i]))
		{
			if (img->arr[i][j] == 'N' && img->map[i][j] != '1')
			{
				img->arr[i][j-1] = 'N';
				img->arr[i][j] = img->map[i][j]; 
				ii = i;
				jj = 0;
			}
			j++;
		}
		i++;
	}
	printf("(%d, %d,)\n", ii, jj);
}