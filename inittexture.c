/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inittexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 04:44:34 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/22 20:54:59 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		inittexture5(t_data *data)
{
	data->notext->name = 'n';
	data->sotext->name = 's';
	data->wetext->name = 'w';
	data->eatext->name = 'e';
	data->spritetext->name = 's';
}

void		inittexture4(t_data *data)
{
	if (!(data->spritetext->mlx = mlx_xpm_file_to_image(data->mlx, \
	data->sprite,\
	&data->spritetext->width, &data->spritetext->height)))
		exit(pritnerror(freexmp7(data)));
	if (!(data->spritetext->addr = mlx_get_data_addr(data->spritetext->mlx, \
	&data->spritetext->bits_per_pixel, &data->spritetext->line_length, \
	&data->spritetext->endian)))
		exit(pritnerror(freexmp7(data)));
}

void		inittexture3(t_data *data)
{
	if (!(data->wetext->mlx = mlx_xpm_file_to_image(data->mlx, data->we, \
	&data->wetext->width, &data->wetext->height)))
		exit(pritnerror(freexmp7(data)));
	if (!(data->wetext->addr = mlx_get_data_addr(data->wetext->mlx, \
	&data->wetext->bits_per_pixel, &data->wetext->line_length, \
	&data->wetext->endian)))
		exit(pritnerror(freexmp7(data)));
	if (!(data->eatext->mlx = mlx_xpm_file_to_image(data->mlx, data->ea, \
	&data->eatext->width, &data->eatext->height)))
		exit(pritnerror(freexmp7(data)));
	if (!(data->eatext->addr = mlx_get_data_addr(data->eatext->mlx, \
	&data->eatext->bits_per_pixel, &data->eatext->line_length, \
	&data->eatext->endian)))
		exit(pritnerror(freexmp7(data)));
}

void		inittexture2(t_data *data)
{
	if (!(data->notext->mlx = mlx_xpm_file_to_image(data->mlx, data->no, \
	&data->notext->width, &data->notext->height)))
		exit(pritnerror(freexmp7(data)));
	if (!(data->notext->addr = mlx_get_data_addr(data->notext->mlx, \
	&data->notext->bits_per_pixel, &data->notext->line_length, \
	&data->notext->endian)))
		exit(pritnerror(freexmp7(data)));
	if (!(data->sotext->mlx = mlx_xpm_file_to_image(data->mlx, data->so, \
	&data->sotext->width, &data->sotext->height)))
		exit(pritnerror(freexmp7(data)));
	if (!(data->sotext->addr = mlx_get_data_addr(data->sotext->mlx, \
	&data->sotext->bits_per_pixel, &data->sotext->line_length, \
	&data->sotext->endian)))
		exit(pritnerror(freexmp7(data)));
}

void		inittexture(t_data *data)
{
	if (!((data)->notext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit(pritnerror(cleanmap(data, 0)));
	if (!((data)->sotext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit(pritnerror(freexmp1(data)));
	if (!((data)->wetext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit(pritnerror(freexmp2(data)));
	if (!((data)->eatext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit(pritnerror(freexmp3(data)));
	if (!((data)->spritetext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit(pritnerror(freexmp4(data)));
	inittexture2(data);
	inittexture3(data);
	inittexture4(data);
	inittexture5(data);
}
