/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdata_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:04:17 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/21 18:48:05 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*setno(char **str, t_flags *flag)
{
	char *no;

	if (str[0][1] == 'O' && !flag->noflag)
	{
		no = ft_strdup(str[1]);
		flag->noflag = 1;
	}
	else
		exit(1);
	return (no);
}

char		*setwe(char **str, t_flags *flag)
{
	char *we;

	if (str[0][1] == 'E' && !flag->weflag)
	{
		we = ft_strdup(str[1]);
		flag->weflag = 1;
	}
	else
		exit(1);
	return (we);
}

char		*setea(char **str, t_flags *flag)
{
	char *ea;

	if (str[0][1] == 'A' && !flag->eaflag)
	{
		ea = ft_strdup(str[1]);
		flag->eaflag = 1;
	}
	else
		exit(1);
	return (ea);
}

char		*setso(char **str, t_flags *flag)
{
	char *so;

	if (!flag->soflag)
	{
		so = ft_strdup(str[1]);
		flag->soflag = 1;
	}
	else
		exit(1);
	return (so);
}

char		*setsprite(char **str, t_flags *flag)
{
	char *sprite;

	if (!flag->spriteflag)
	{
		sprite = ft_strdup(str[1]);
		flag->spriteflag = 1;
	}
	else
		exit(1);
	return (sprite);
}
