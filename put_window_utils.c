/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:10:09 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/20 23:54:04 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_foundpixel(int jj, double pixelhiegt, int r2)
{
	if (pixelhiegt > r2)
		return(((pixelhiegt - r2)/2 + jj)/pixelhiegt);
	else
	{
		return ((jj - (r2 - pixelhiegt)/2)/pixelhiegt);
	}
}

t_xpm 	*ft_findwall(t_data *img)
{
	double x;
	double y;
	
	x = img->mapx;
	y = img->mapy;
	if (img->map[(int)x][(int)y] != img->map[(int)(x + 0.002)][(int)y])
		return (img->notext);
	else if (img->map[(int)x][(int)y] != img->map[(int)(x - 0.002)][(int)y])
		return (img->sotext);
	else if (img->map[(int)x][(int)y] != img->map[(int)(x)][(int)(y - 0.002)])
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
		return (1 - y + (int)y);
}