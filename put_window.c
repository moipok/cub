/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:55:14 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/17 23:37:58 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	putfloor(t_data *img, int  i, int jj)
{
	int col;
	
	col = -1;
	while (col++ < img->coef)
	{
		my_mlx_pixel_put(img, img->r1 - i - col, img->r2 - jj - 1, img->floor);
		my_mlx_pixel_put(img, img->r1 - i - col, jj, img->cellar);
	}
}

void	set_start_end(int pixelhiegt, int r2, int *end, int *jj)
{
	if (pixelhiegt > r2)
	{
		*jj = 1;
		*end = r2 - 1;
	}
	else
	{	
		*jj = (r2 - pixelhiegt)/2;
		*end = *jj + pixelhiegt;
	}
}

void ft_putline(t_data *img, int i, double pixelhiegt, t_xpm *wall, double pofw)
{
	int jj;
	int end;
	int collor;
	int col;
	
	i = i*img->coef;
	if (i > img->r1)
		return ;
	set_start_end(pixelhiegt, img->r2, &end, &jj);
	while (jj < img->r2 - 1)
	{
		if (jj < end)
		{
			collor = get_collor(wall, (pofw * wall->width), (wall->height * \
			ft_foundpixel(jj, end, pixelhiegt, img->r2)));
			col = -1;
			while (col++ < img->coef)
				my_mlx_pixel_put(img, img->r1 - i - col, jj, collor);
		}
		else
			putfloor(img, i, jj);
		jj++;
	}
}

t_data *ft_putcol(t_data *img)
{
	double c;  
	double x;
	double y;
	double angle1;
	int i;
	double pixelhiegt;
	double partofwall;
	t_xpm	*wall;

	angle1 = img->mainangle - M_PI / 6;
	if (!(img->deep = malloc(sizeof(double) * (img->r1 / img->coef + 10)))) //fael;,e;kslvme;
		exit(0);
	i = 0;
	while (angle1 < img->mainangle + M_PI / 6)
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
		angle1 += M_PI * img->coef / (img->r1 * 3) ;
	}
	return (img);
}

void	ft_putwindow_3d(t_data *img)
{
	mlx_clear_window(img->mlx, img->win);
	img->img = mlx_new_image(img->mlx, img->r1, img->r2);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	ft_putcol(img);
	ft_putsprite(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}