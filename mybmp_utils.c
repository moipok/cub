/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mybmp_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 23:47:06 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/27 23:48:46 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_count4(int r)
{
	return (4 - (r * 3) % 4);
}

void	ft_setsize(unsigned char *s, t_data *img)
{
	int size;
	int col;

	col = (img->r1 * 3) + ft_count4(img->r1);
	size = 54 + (col * img->r2);
	s[0] = (unsigned char)(size);
	s[1] = (unsigned char)(size >> 8);
	s[2] = (unsigned char)(size >> 16);
	s[3] = (unsigned char)(size >> 24);
}

void	ft_setr1(unsigned char *s, int r)
{
	s[0] = (unsigned char)(r);
	s[1] = (unsigned char)(r >> 8);
	s[2] = (unsigned char)(r >> 16);
	s[3] = (unsigned char)(r >> 24);
}
