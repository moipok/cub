#include "cub3d.h"

int		check_elem(int x, int y, t_sprite *spr)
{
	int i;
	
	i = 0;
	while (i < 20)
	{
		if (spr[i].x == x + 0.5 && spr[i].y == y + 0.5)
			return (1);
		i++;
	}
	return (0);
}

int		**ft_malloc_arrayint(int i, int j)
{
	int **arr;
	int k;

	if (!(arr = malloc(sizeof(int*) * i)))
		exit(0);
	k = 0;
	while (k < i)
	{
		if (!(arr[k] = malloc(sizeof(int) * j)))
			exit(0);
		k++;
	}
	return (arr);
}

void	freeintmass(int **arr, int i, int j)
{
	int k;

	k = 0;
	while (k < i)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}

void	null_mas(t_sprite *spr, int i)
{
	int k;

	k = 0;
	while (k < i)
	{
		spr[k].x = 0;
		spr[k].y = 0;
		spr[k].average = 0;
		k++;
	}
}

void bubblesort(t_sprite *spr, int size)
{
	int i;
	int j;
	int flag;
	t_sprite tmp;

	i = 0;
	flag = 1;
	while (flag > 0)
	{
		flag = 0;
		while(i < size - 1)
		{
			if (spr[i].average < spr[i + 1].average)
			{
				tmp = spr[i + 1];
				spr[i + 1] = spr[i];
				spr[i] = tmp;
				flag++;
			}
			i++;
		}
	}
}

void	ft_putsprite(t_data *img)
{
	double angle1;
	int i;
	double x;
	double y;
	double c;
	
	angle1 = img->mainangle - M_PI / 6;
	i = 0;
	img->spr = malloc(sizeof(t_sprite) * 20); 
	null_mas(img->spr, 20);
	while (angle1 < img->mainangle + M_PI / 6)
	{
		c = 0.001;
		while (c)
		{
			x = img->x + c * cos(angle1);
			y = img->y + c * sin(angle1);
		 	if (img->map[(int)x][(int)y] == '1' || img->map[(int)x][(int)y] == '\0') 
				break;
			if (img->map[(int)x][(int)y] == '2')
			{
				if (check_elem((int)x, (int)y, img->spr) == 0)
				{
					img->spr[i].x = (int)x + 0.5;
					img->spr[i].y = (int)y + 0.5;
					img->spr[i].average = (sqrt(pow((img->x - img->spr[i].x), 2) + pow((img->y - img->spr[i].y), 2)));
					img->spr[i].angle = atan2((img->spr[i].y - img->y), (img->spr[i].x - img->x));
					printf("%f\n", img->spr[i].angle);
					printf("%f\n", img->mainangle);
					i++;
				}
			}
			c = c + 0.1;
		}
		angle1 += M_PI / (img->r1 * 3);
	}
	bubblesort(img->spr, 20);
	free(img->spr);
}