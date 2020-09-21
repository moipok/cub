/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:58:40 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/21 16:00:16 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	putlinesprite(t_data *img, int i, int l, double pixelhiegt)
{
	int k;
	int collor;

	k = 0;
	while (k < img->r2)
	{
		collor = get_collor(img->spritetext, img->spritetext->width \
		* (l / pixelhiegt), img->spritetext->height *\
		((pixelhiegt - img->r2) / 2 + k) / pixelhiegt);
		if (get_t(collor) == 0)
			my_mlx_pixel_put(img, i + l, k, collor);
		k++;
	}
}

void	putlinebigsprite(t_data *img, int i, int l, double pixelhiegt)
{
	int k;
	int collor;

	k = (img->r2 - pixelhiegt) / 2 + 1;
	while (k < (img->r2 - pixelhiegt) / 2 + pixelhiegt)
	{
		collor = get_collor(img->spritetext, img->spritetext->width \
		* (l / pixelhiegt), img->spritetext->height \
		* (k - (img->r2 - pixelhiegt) / 2) / pixelhiegt);
		if (get_t(collor) == 0)
			my_mlx_pixel_put(img, i + l, k, collor);
		k++;
	}
}

double	setcos(double mainangle, double angle)
{
	double cosin;

	cosin = cos(mainangle - angle);
	if (cosin < 0.85)
		cosin = 0.85;
	return (cosin);
}

void	putsprite(t_data *img, int num)
{
	double	i;
	int		l;
	double	pixelhiegt;
	double	cosin;

	cosin = setcos(img->mainangle, img->spr[num].angle);
	pixelhiegt = 0.3 * img->r2 / (img->spr[num].average * cosin);
	i = (img->r1 / 2 + (img->mainangle - img->spr[num].angle) \
	/ (M_PI / (img->r1 * 3)) - pixelhiegt / 2);
	l = 0;
	while (l < pixelhiegt)
	{
		if (i + l > 0 && img->spr[num].average < img->deep[(int)(\
		(img->r1 - l - i) / img->coef)] && i + l < img->r1)
		{
			if (pixelhiegt > img->r2)
				putlinesprite(img, i, l, pixelhiegt);
			else
				putlinebigsprite(img, i, l, pixelhiegt);
		}
		l++;
	}
}
