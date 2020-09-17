/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:02 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/17 23:37:51 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int checkline(char *line)
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

int	checkarr(char **map)
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

int 	ft_checkmap(char **map, double x)
{
	int i;
	int j;

	if ((x - (int)x) != 0.5)
	{
		printf("nohero\n");
		exit (1);
	}
	if (checkline(map[0]) == 1 || \
	checkline(map[ft_arrlen(map) - 1]) == 1)
	{
		printf("error line\n");
		exit(1);
	}
	if (checkarr(map) == 1)
	{
		printf("error collon\n");
		exit(1);
	}
	return (1);
}