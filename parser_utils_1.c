/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 20:38:06 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/21 15:29:31 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_create_arr(t_list *list)
{
	char	**arr;
	int		i;
	t_list	*tmp;

	tmp = list;
	i = 0;
	if (!(arr = malloc((sizeof(char*)) * (ft_lstsize(list) + 1))))
		exit(1);
	while (list)
	{
		if (!(arr[i] = malloc((sizeof(char)) * \
		(ft_strlenn(list->content) + 1))))
			exit(1);
		arr[i] = list->content;
		list = list->next;
		i++;
	}
	i = 0;
	ft_lstfree(&tmp);
	return (arr);
}

char	**mallocbigarr(char **arr)
{
	int		i;
	int		j;
	char	**new;

	if (!(new = ft_calloc((sizeof(char*)), (ft_arrlen(arr) + 1))))
		exit(1);
	i = 0;
	j = ft_maxlenarr(arr);
	while (arr[i])
	{
		if (!(new[i] = ft_calloc(sizeof(char), j + 1)))
			exit(1);
		i++;
	}
	return (new);
}

int		checknwes(char a)
{
	if (a == 'N' || a == 'E' || a == 'W' || a == 'S')
		return (1);
	return (-1);
}

int		checkunknown(char c)
{
	if (c == '0' || c == '1' || c == '2')
		return (0);
	return (1);
}

int		checkunknownsymbol(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (checkunknown(map[i][j]) == 1)
				return (1);
	}
	return (0);
}
