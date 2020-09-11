/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:55:14 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/05 19:55:26 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int            get_collor(t_xpm *data, int x, int y)
{
    char    *dst;
	int 	collor;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    collor = *(int*)dst;
	return (collor);
}

double	ft_foundpixel(int jj,int end, double pixelhiegt, int r2)
{
	if (pixelhiegt > r2)
		return(((pixelhiegt - r2)/2 + jj)/pixelhiegt);
	else
	{
		return ((jj - (r2 - pixelhiegt)/2)/pixelhiegt);
	}
}


void ft_putline(t_data *img, int i, double pixelhiegt, t_xpm *whatwall, double partofwall)
{
	int tmp;
	int jj;
	int end;

	if (i > img->r1)
	{
		printf("%d,\n", i);
		return ;
	}
	if ((int)pixelhiegt > img->r2)
	{
		jj = 1;
		end = img->r2 - 1;
	}
	else
	{	
		jj = (img->r2 - pixelhiegt)/2;
		end = jj + pixelhiegt;
	}
	tmp = jj;
	while (jj < img->r2 - 1)
	{
		if (jj < end)
			my_mlx_pixel_put(img, img->r1 - i, jj, get_collor(whatwall, (partofwall * whatwall->width), (whatwall->height * ft_foundpixel(jj, end, pixelhiegt, img->r2))));
		else
		{
			my_mlx_pixel_put(img, img->r1 - i, img->r2 - jj, img->floor);
			my_mlx_pixel_put(img, img->r1 - i, jj, img->cellar);
		}
		jj++;
	}
}

t_xpm 	*ft_findwall(t_data *img, double c, double x, double y, double angle1)
{
	double xx;
	double yy;
	
	c = c - 0.001;
	xx = img->x + c * cos(angle1);
	yy = img->y + c * sin(angle1);
	if ((int)x - (int)xx == -1)
		return (img->notext);
	else if ((int)x - (int)xx == 1)
		return (img->sotext);
	else if ((int)y - (int)yy == 1)
		return (img->wetext);
	else
		return (img->eatext);
}

double ft_findpartofwall(char wall, double x, double y)
{
	if (wall == 'w')
		return (x - (int)x);
	else if (wall == 'e')
		return (1 - x + (int)x);
	else if (wall == 'n')
		return (y - (int)y);
	else
		return (1 - y + (int)y); //s
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
	double pixelhiegt;
	double partofwall;
	t_xpm	*wall;

	angle1 = img->mainangle - M_PI / 6;
	angle2 = img->mainangle + M_PI / 6;
	if (!(img->deep = malloc(sizeof(double) * img->r1)))
		exit(0);
	i = 0;
	while (angle1 < angle2)
	{
		c = 0.001;
		while (c)
		{
			x = img->x + c * cos(angle1);
			y = img->y + c * sin(angle1);
		 	if (img->map[(int)x][(int)y] == '1' || img->map[(int)x][(int)y] == '\0') 
			{
				c = c - 0.05;
				while (c)
				{
					x = img->x + c * cos(angle1);
					y = img->y + c * sin(angle1);
					if (img->map[(int)x][(int)y] == '1' || img->map[(int)x][(int)y] == '\0') 
					{
						pixelhiegt = img->r2  / (c * cos(img->mainangle - angle1));
						wall = ft_findwall(img, c, x, y, angle1);
						partofwall = ft_findpartofwall(wall->name, x, y);
						ft_putline(img, i, pixelhiegt, wall, partofwall);
						img->deep[i] = c;
						i++;
						break;
					}
					c = c + 0.001;
				}
				break;
			}
			c = c + 0.05;
		}
		angle1 += M_PI / (img->r1 * 3);
	}
	return (img);
}

void	ft_putwindow_3d(t_data *img)
{
	img->img = mlx_new_image(img->mlx, img->r1, img->r2);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	ft_putcol(img);
	ft_putsprite(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}