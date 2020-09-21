/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:05:58 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/21 16:02:23 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	correctangle(double angle)
{
	if (angle >= 2 * M_PI)
		return (angle - 2 * M_PI);
	else if (angle < 0)
		return (angle + 2 * M_PI);
	return (angle);
}

double	correctangle1(double angle, double mainangle)
{
	if (angle + M_PI_2 < mainangle)
		return (angle + 2 * M_PI);
	else if (angle - M_PI_2 > mainangle)
		return (angle - 2 * M_PI);
	return (angle);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}
