/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:55:09 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/05 19:55:27 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    put_texture(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    data->img = mlx_new_image(data->mlx, data->r1, data->r2);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            my_mlx_pixel_put(data, i, j, get_collor(data->notext, i, j));
            j++;
            //printf("%d", get_collor(data->notext, i, j));
        }
        //printf("\n");
        i++;
    }
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}