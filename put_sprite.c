#include "cub3d.h"

int		check_elem(double x, double y, t_sprite *spr, double s)
{
	int i;
	
	i = 0;
	if (sqrt(pow((x - (int)x - 0.5), 2) + pow((y - (int)y - 0.5), 2)) > 0.3 && s < 1)
		return (1);
	while (i < 20)
	{
		if (spr[i].x == (int)x + 0.5 && spr[i].y == (int)y + 0.5)
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

	flag = 1;
	while (flag > 0)
	{
		flag = 0;
		i = 0;
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
	i = 0;
}

double	correctangle(double angle)
{
	if (angle >= 2 * M_PI)
		return(angle - 2 * M_PI);
	else if (angle < 0)
		return(angle + 2 * M_PI);
	return (angle);
}

double	correctangle1(double angle, double mainangle)
{
	if (angle + M_PI_2 < mainangle)
		return(angle + 2 * M_PI);
	else if (angle - M_PI_2 > mainangle)
		return(angle - 2 * M_PI);
	return (angle);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}


void	putsprite(t_data *img, int num)
{
	double i;
	int l;
	int k;
	double pixelhiegt;
	int collor;
	double cosin;

	cosin = cos(img->mainangle - img->spr[num].angle);
	if (cosin < 0.85)
		cosin = 0.85;
	pixelhiegt = 0.3 * img->r2  / (img->spr[num].average * cosin);
	i = (img->r1/2 + (img->mainangle - img->spr[num].angle) / (M_PI / (img->r1 * 3)) - pixelhiegt/2);
	l = 0;
	while (l < pixelhiegt)
	{
		if (i + l > 0 && img->spr[num].average < img->deep[(int)((img->r1 - l - i)/img->coef)] && i + l < img->r1)
		{
			if (pixelhiegt > img->r2)
			{
				k = 0;
				while (k < img->r2)
				{
					collor = get_collor(img->spritetext, img->spritetext->width * (l/pixelhiegt), img->spritetext->height * ((pixelhiegt - img->r2)/2 + k)/pixelhiegt);
					if (get_t(collor) == 0)
						my_mlx_pixel_put(img, i + l, k, collor);
					k++;
				}
			}
			else 
			{
				k = (img->r2 - pixelhiegt)/2 + 1;
				while (k < (img->r2 - pixelhiegt)/2 + pixelhiegt)
				{
					collor = get_collor(img->spritetext, img->spritetext->width * (l/pixelhiegt), img->spritetext->height * (k - (img->r2 - pixelhiegt)/2)/pixelhiegt);
					if (get_t(collor) == 0)
						my_mlx_pixel_put(img, i + l, k, collor);
					k++;
				}
			}
		}
		else if (i + l > img->r1)
			break;
		l++;
	}
}

void	putssss(t_data *img, int num)
{
	double i;
	int l;
	int k;
	double pixelhiegt;
	int collor;

	pixelhiegt = img->r2  / (img->spr[num].average * cos(img->mainangle - img->spr[num].angle));

	i = img->r1/2 + (img->mainangle - img->spr[num].angle) / (M_PI / (img->r1 * 3));
	l = 0;
	while (l < pixelhiegt)
	{
		k = 0;
		while (k < pixelhiegt && k < img->r2/2)
		{
			collor = get_collor(img->spritetext, img->spritetext->width * ((pixelhiegt + l)/(2 * pixelhiegt)), img->spritetext->height * ((pixelhiegt/2 + k/2)/pixelhiegt));
			if (get_t(collor) == 0 && (img->spr[num].average < img->deep[img->r1 - (int)i - l]) \
			&& (int)i + l < img->r1)
				my_mlx_pixel_put(img, i + l, img->r2/2 + k, collor);
			collor = get_collor(img->spritetext, img->spritetext->width * ((pixelhiegt - l)/(2 * pixelhiegt)), img->spritetext->height * ((pixelhiegt/2 + k/2)/pixelhiegt));
			if (get_t(collor) == 0 && (img->spr[num].average < img->deep[img->r1 - (int)i + l])\
			&& (int)i - l < img->r1)
				my_mlx_pixel_put(img, i - l, img->r2/2 + k, collor);
			collor = get_collor(img->spritetext, img->spritetext->width * ((pixelhiegt + l)/(2 * pixelhiegt)), img->spritetext->height * ((pixelhiegt/2 - k/2)/pixelhiegt));
			if (get_t(collor) == 0 && (img->spr[num].average < img->deep[img->r1 - (int)i - l])\
			&& (int)i + l < img->r1)
				my_mlx_pixel_put(img, i + l, img->r2/2 - k, collor);
			collor = get_collor(img->spritetext, img->spritetext->width * ((pixelhiegt - l)/(2 * pixelhiegt)), img->spritetext->height * ((pixelhiegt/2 - k/2)/pixelhiegt));
			if (get_t(collor) == 0 && (img->spr[num].average < img->deep[img->r1 - (int)i + l])\
			&& (int)i - l < img->r1)
				my_mlx_pixel_put(img, i - l, img->r2/2 - k, collor);
			k++;
		}
		l++;
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
	img->spr = malloc(sizeof(t_sprite) * img->num); 
	null_mas(img->spr, img->num);
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
				if (check_elem(x, y, img->spr, (sqrt(pow((img->x - (int)x + 0.5), 2) + pow((img->y - (int)y + 0.5), 2)))) == 0)
				{
					img->spr[i].x = (int)x + 0.5;
					img->spr[i].y = (int)y + 0.5;
					img->spr[i].average = (sqrt(pow((img->x - img->spr[i].x), 2) + pow((img->y - img->spr[i].y), 2)));
					img->spr[i].angle = correctangle1(atan2((img->spr[i].y - img->y), (img->spr[i].x - img->x)), \
					img->mainangle);
					i++;
				}
			}
			c = c + 0.5;
		}
		angle1 += 5 * M_PI / (img->r1 * 3);
	}
	bubblesort(img->spr, i);
	c = 0;
	while (c < i)
	{
		if (img->spr[(int)c].average > 0.7)
			putsprite(img, (int)c);
		c = c+1;
	}
	free(img->deep);
	free(img->spr);
}