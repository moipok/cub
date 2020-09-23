/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:54 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/24 02:31:15 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_docase(int keycode, t_data *img)
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
		img->mainangle += 5 * M_PI / 360;
	else if (keycode == 124)
		img->mainangle -= 5 * M_PI / 360;
	else
		;
	img->mainangle = correctangle(img->mainangle);
	ft_putwindow_3d(img);
	return (0);
}

int		ft_close(t_data *img)
{
	//mlx_destroy_window(img->mlx, img->win);
	ft_freeall(img);
	exit(1);
}

int		main(int argc, char **argv)
{
	t_data	img;

	img.mlx = NULL;
	img.win = NULL;
	if (argc != 2)
		return (0);
	ft_parser(argv, &img);
	if (!(img.mlx = mlx_init()))
		exit(pritnerror(cleanmap(&img, 6)));
	if (!(img.win = mlx_new_window(img.mlx, img.r1, img.r2, "test")))
		exit(pritnerror(cleanmap(&img, 6)));
	img.coef = 1;
	inittexture(&img);
		if (!(img.img = mlx_new_image(img.mlx, img.r1, img.r2)))
		exit(pritnerror(freexmp4(&img)));
	if (!(img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,\
	&img.line_length, &img.endian)))
		exit(pritnerror(freexmp4(&img)));
	ft_putwindow_3d(&img);
	mlx_hook(img.win, 17, 1L << 0, ft_close, &img);
	mlx_hook(img.win, 2, 1L << 0, ft_docase, &img);
	mlx_loop(img.mlx);
	return (0);
}
