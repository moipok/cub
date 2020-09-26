/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdata_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:04:17 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/24 17:19:26 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*setno(char **str, t_flags *flag, t_data *img)
{
	char *no;

	if (str[0][1] == 'O' && !flag->noflag)
	{
		no = ft_strdup(str[1]);
		flag->noflag = 1;
	}
	else
		exit(error_setdata(flag, img));
	return (no);
}

char		*setwe(char **str, t_flags *flag, t_data *img)
{
	char *we;

	if (str[0][1] == 'E' && !flag->weflag)
	{
		we = ft_strdup(str[1]);
		flag->weflag = 1;
	}
	else
		exit(error_setdata(flag, img));
	return (we);
}

char		*setea(char **str, t_flags *flag, t_data *img)
{
	char *ea;

	if (str[0][1] == 'A' && !flag->eaflag)
	{
		ea = ft_strdup(str[1]);
		flag->eaflag = 1;
	}
	else
		exit(error_setdata(flag, img));
	return (ea);
}

char		*setso(char **str, t_flags *flag, t_data *img)
{
	char *so;

	if (!flag->soflag)
	{
		so = ft_strdup(str[1]);
		flag->soflag = 1;
	}
	else
		exit(error_setdata(flag, img));
	return (so);
}

char		*setsprite(char **str, t_flags *flag, t_data *img)
{
	char *sprite;

	if (!flag->spriteflag)
	{
		sprite = ft_strdup(str[1]);
		flag->spriteflag = 1;
	}
	else
		exit(error_setdata(flag, img));
	return (sprite);
}
