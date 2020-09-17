/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:58:40 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/17 23:37:54 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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