/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:22:43 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/21 22:04:42 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		pritnerror(int error)
{
	if (error == 0)
		ft_putstr_fd("ERROR MALLOC\n", 2);
	if (error == 1)
		ft_putstr_fd("ERROR SYMBOL IN FILE\n", 2);
	if (error == 3)
		ft_putstr_fd("TWO OR MORE HERO\n", 2);
	if (error == 2)
		ft_putstr_fd("NO HERO\n", 2);
	if (error == 4)
		ft_putstr_fd("UNCNOWN SYMBOL\n", 2);
	if (error == 5)
		ft_putstr_fd("ERROR MAP\n", 2);
	if (error == 6)
		ft_putstr_fd("ERROR INIT MLX\n", 2);
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

int		error_setdata0(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return(0);
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