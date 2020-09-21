/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:01:38 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/22 00:29:57 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_malloc2(t_data *img, char **arr)
{
	error_setdata(img->flag, img);
	freemass(arr);
	return (0);
}

int		error_malloc3(t_data *img, char **arr, char **new, int i)
{
	error_setdata(img->flag, img);
	freemass(arr);
	freecharmass(new, i);
	return (0);
}

int		cleanmap(t_data *img, int error)
{
	freemass(img->map);
	error_setdata(img->flag, img);
	return (error);
}
