/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:55:19 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/21 19:49:56 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_cleanflag(t_flags *flag)
{
	flag->noflag = 0;
	flag->soflag = 0;
	flag->weflag = 0;
	flag->eaflag = 0;
	flag->spriteflag = 0;
	flag->r1flag = 0;
	flag->cellarflag = 0;
	flag->floorflag = 0;
	flag->allflag = 0;
}

int			fl_sumflag(t_flags *flag)
{
	return (flag->noflag + flag->soflag + flag->weflag + \
	flag->eaflag + flag->spriteflag + flag->r1flag + \
	flag->cellarflag + flag->floorflag);
}

int			setfc(char s, t_flags *flag, char **str)
{
	if (s == 'F')
		flag->floorflag = 1;
	else if (s == 'C')
		flag->cellarflag = 1;
	return (ft_setfloorcollor(str));
}

void		setdata(char **str, t_data *img, t_flags *flag)
{
	flag->allflag = fl_sumflag(flag);
	if (str[0][0] == 'R' && !flag->r1flag)
	{
		img->r1 = ft_atoi(str[1]);
		img->r2 = ft_atoi(str[2]);
		flag->r1flag = 1;
	}
	else if (str[0][0] == 'N')
		img->no = setno(str, flag, img);
	else if (str[0][0] == 'S' && str[0][1] == 'O' && !flag->soflag)
		img->so = setso(str, flag, img);
	else if (str[0][0] == 'S' && ft_strlen(str[0]) == 1 && !flag->spriteflag)
		img->sprite = setsprite(str, flag, img);
	else if (str[0][0] == 'W')
		img->we = setwe(str, flag, img);
	else if (str[0][0] == 'E')
		img->ea = setea(str, flag, img);
	else if (str[0][0] == 'F' && !flag->floorflag)
		img->floor = setfc('F', flag, str);
	else if (str[0][0] == 'C' && !flag->cellarflag)
		img->cellar = setfc('C', flag, str);
	else
		exit(error_setdata(flag, img));
}
