/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:55:04 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/24 18:03:14 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lstfree(t_list **list)
{
	t_list *a;
	t_list *b;

	b = *list;
	while (b->next)
	{
		a = b;
		b = b->next;
		free(a);
	}
	free(b);
}

int		ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		ft_maxlenarr(char **arr)
{
	int		i;
	size_t	tmp;
	size_t	len;

	i = 0;
	tmp = 0;
	while (arr[i])
	{
		len = ft_strlenn(arr[i]);
		if (len >= tmp)
			tmp = len;
		i++;
	}
	return (tmp);
}

double	ft_angle(char c)
{
	if (c == 'N')
		return (M_PI);
	else if (c == 'E')
		return (M_PI_2);
	else if (c == 'W')
		return (-M_PI_2);
	else
		return (0);
}
