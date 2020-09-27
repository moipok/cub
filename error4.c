/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 23:41:42 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/27 23:42:18 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		freexmp7(t_data *img)
{
	freexmp3(img);
	free(img->spritetext);
	return (12);
}

int		ft_errnocheck(int er, t_flags *flag, int fd)
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
