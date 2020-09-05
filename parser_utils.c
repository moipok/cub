/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:55:04 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/05 19:55:28 by fbarbera         ###   ########.fr       */
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
	int i;
	int tmp;
	
	i = 0;
	tmp = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > tmp)
			tmp = ft_strlen(arr[i]);
		i++;
	}
	return (tmp);
}
