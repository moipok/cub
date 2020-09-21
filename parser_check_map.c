/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:02 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/21 21:58:51 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checkline(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '2')
			return (1);
		i++;
	}
	return (0);
}

int		checkarr(char **map)
{
	int i;
	int len;

	i = 0;
	len = ft_maxlenarr(map);
	while (map[i])
	{
		if (map[i][0] == '0' || map[i][0] == '2')
			return (1);
		if (map[i][len] == '0' || map[i][len] == '2')
			return (1);
		i++;
	}
	return (0);
}

int		checktwohero(char **map, t_data *img)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (checknwes(map[i][j]) == 1)
			{
				flag++;
				img->mainangle = ft_angle(map[i][j]);
				map[i][j] = '0';
				img->x = i + 0.5;
				img->y = j + 0.5;
			}
		}
	}
	return (flag);
}

int		ft_checkmap(char **map, t_data *img)
{
	int i;

	i = checktwohero(map, img);
	if (i > 1)
		exit(pritnerror(cleanmap(img, 3)));
	else if (i == 0)
		exit(pritnerror(cleanmap(img, 2)));
	if (checkunknownsymbol(map) != 0)
		exit(pritnerror(cleanmap(img, 4)));
	if (checkline(map[0]) == 1 || \
	checkline(map[ft_arrlen(map) - 1]) == 1)
		exit(pritnerror(cleanmap(img, 5)));
	if (checkarr(map) == 1)
		exit(pritnerror(cleanmap(img, 5)));
	return (1);
}
