/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:22:43 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/24 17:21:33 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		pritnerror(int error)
{
	if (error == 0)
		ft_putstr_fd("ERROR\nMALLOC\n", 2);
	if (error == 1)
		ft_putstr_fd("ERROR\nSYMBOL IN FILE\n", 2);
	if (error == 3)
		ft_putstr_fd("ERROR\nTWO OR MORE HERO\n", 2);
	if (error == 2)
		ft_putstr_fd("ERROR\nNO HERO\n", 2);
	if (error == 4)
		ft_putstr_fd("ERROR\nUNCNOWN SYMBOL\n", 2);
	if (error == 5)
		ft_putstr_fd("ERROR\nMAP\n", 2);
	if (error == 6)
		ft_putstr_fd("ERROR\nINIT MLX\n", 2);
	if (error == 10)
		ft_putstr_fd("ERROR\nCOLLOR\n", 2);
	if (error == 11)
		ft_putstr_fd("ERROR\nRESOLUTION\n", 2);
	if (error == 12)
		ft_putstr_fd("ERROR\nTEXURE NAME\n", 2);
	return (0);
}

int		error_setdata(t_flags *flag, t_data *img)
{
	if (flag->noflag == 1)
		free(img->no);
	if (flag->weflag == 1)
		free(img->we);
	if (flag->eaflag == 1)
		free(img->ea);
	if (flag->soflag == 1)
		free(img->so);
	if (flag->spriteflag == 1)
		free(img->sprite);
	free(flag);
	return (1);
}

int		error_setdatar1(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return (11);
}

int		error_setdata1(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return (10);
}

int		error_setdata0(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return (0);
}

int		error_inside(t_flags *flag, t_data *img, char **arr, int i)
{
	int k;

	k = -1;
	error_setdata(flag, img);
	while (++k < i)
		free(arr[k]);
	free(arr);
	return (0);
}
