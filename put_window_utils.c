/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:10:09 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/17 23:37:59 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_foundpixel(int jj,int end, double pixelhiegt, int r2)
{
	if (pixelhiegt > r2)
		return(((pixelhiegt - r2)/2 + jj)/pixelhiegt);
	else
	{
		return ((jj - (r2 - pixelhiegt)/2)/pixelhiegt);
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