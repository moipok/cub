/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:02:38 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/22 20:55:22 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		freexmp1(t_data *img)
{
	cleanmap(img, 0);
	free(img->notext);
	return (0);
}

int		freexmp2(t_data *img)
{
	freexmp1(img);
	free(img->sotext);
	return (0);
}

int		freexmp3(t_data *img)
{
	freexmp2(img);
	free(img->eatext);
	return (0);
}

int		freexmp4(t_data *img)
{
	freexmp3(img);
	free(img->spritetext);
	return (0);
}

int		freexmp5(t_data *img)
{
	freexmp4(img);
	free(img->deep);
	return (0);
}

int		freexmp7(t_data *img)
{
	freexmp3(img);
	free(img->spritetext);
	return (12);
}

int		ft_errnocheck(int er, char *av, t_flags *flag, int fd)
{
	if (er == 13)
	{
		ft_putstr_fd("ERROR : Permission denied\n", 2);
		free(flag);
		close(fd);
		return (1);
	}
	if (er == 21)
	{
		ft_putstr_fd("ERROR : Realy?\n", 2);
		free(flag);
		close(fd);
		return (1);
	}
	if (er == 2)
	{
		ft_putstr_fd("ERROR : No such file or directory\n", 2);
		free(flag);
		close(fd);
		return (1);
	}
	return (0);
}