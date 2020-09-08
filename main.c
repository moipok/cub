/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:54 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/06 01:17:32 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void freemass(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void			ft_freeall(t_data *img)
{
	free(img->notext);
	free(img->sotext);
	free(img->wetext);
	free(img->eatext);
	free(img->spritetext);
	freemass(img->map);
	free(img->no);
	free(img->so);
	free(img->we);
	free(img->ea);
	free(img->sprite);
}

int             ft_docase(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		ft_freeall(img);
		exit(1);
	}
	else if (keycode == 13 || keycode == 126)
		img = ft_w(img);
	else if (keycode == 1 || keycode == 125)
		img = ft_s(img);
	else if (keycode == 2)
		img = ft_d(img);
	else if (keycode == 0)
		img = ft_a(img);
	else if (keycode == 123)
		img->mainangle += 5 * M_PI/365;
	else if (keycode == 124)
		img->mainangle -= 5 * M_PI/365;
	else
		printf("%d\n", keycode);
	img->mainangle = correctangle(img->mainangle);
	ft_putwindow_3d(img);
	return (0);
}


void	inittexture(t_data *data)
{
	if (!((data)->notext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit (1);
	if (!((data)->sotext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit (1);
	if (!((data)->wetext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit (1);
	if (!((data)->eatext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit (1);
	if (!((data)->spritetext = (t_xpm*)malloc(sizeof(t_xpm))))
		exit (1);
	data->notext->mlx = mlx_xpm_file_to_image(data->mlx, data->no, &data->notext->width, &data->notext->height);
	data->notext->addr = mlx_get_data_addr(data->notext->mlx, &data->notext->bits_per_pixel, &data->notext->line_length, &data->notext->endian);
	data->sotext->mlx = mlx_xpm_file_to_image(data->mlx, data->so, &data->sotext->width, &data->sotext->height);
	data->sotext->addr = mlx_get_data_addr(data->sotext->mlx, &data->sotext->bits_per_pixel, &data->sotext->line_length, &data->sotext->endian);
	data->wetext->mlx = mlx_xpm_file_to_image(data->mlx, data->we, &data->wetext->width, &data->wetext->height);
	data->wetext->addr = mlx_get_data_addr(data->wetext->mlx, &data->wetext->bits_per_pixel, &data->wetext->line_length, &data->wetext->endian);
	data->eatext->mlx = mlx_xpm_file_to_image(data->mlx, data->ea, &data->eatext->width, &data->eatext->height);
	data->eatext->addr = mlx_get_data_addr(data->eatext->mlx, &data->eatext->bits_per_pixel, &data->eatext->line_length, &data->eatext->endian);
	data->spritetext->mlx = mlx_xpm_file_to_image(data->mlx, data->sprite, &data->spritetext->width, &data->spritetext->height);
	data->spritetext->addr = mlx_get_data_addr(data->spritetext->mlx, &data->spritetext->bits_per_pixel, &data->spritetext->line_length, &data->spritetext->endian);

	data->notext->name = 'n';
	data->sotext->name = 's';
	data->wetext->name = 'w';
	data->eatext->name = 'e';
	data->spritetext->name = 's';
}

int		main(int argc, char **argv)
{
	int i;
	int j;
    t_data  img;

	img.mlx = NULL;
	img.win = NULL;
	ft_parser(argc, argv, &img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.r1, img.r2, "test");
	//	ft_putwindow_3d(&img);
	inittexture(&img);
	ft_putwindow_3d(&img);
	mlx_hook(img.win, 2, 1L<<0, ft_docase, &img);
	mlx_loop(img.mlx);
	return (0);
}