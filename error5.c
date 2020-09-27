/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 23:53:16 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/27 23:53:42 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_setdatar777(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return (777);
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
