/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somefree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 01:54:53 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/24 01:57:32 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freecharmass(char **str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	freemass(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_freeall(t_data *img)
{
	free(img->notext);
	free(img->sotext);
	free(img->wetext);
	free(img->eatext);
	free(img->spritetext);
	freemass(img->map);
	free(img->no);
	free(img->so);
	free(img->we);
	free(img->ea);
	free(img->sprite);
}
