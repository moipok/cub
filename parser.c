/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:10 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/20 23:53:12 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_bigarr(char **arr, t_data *img)
{
	char **new;
	int i;
	int j;

	new = mallocbigarr(arr);
	img->num = 0;
	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (arr[i][j] == ' ')
				new[i][j] = '1';
			else
				new[i][j] = arr[i][j];
			if (arr[i][j] == '2')
				img->num++;
		}
	}
	freemass(arr);
	return (new);
}

void	ft_persetdata(t_data *img, t_flags *flag, char *line)
{
	char **tmp;

	tmp = ft_split(line, ' ');
	setdata(tmp, img, flag);
	free(tmp);
	free(line);
}

void 	ft_parser(char **argv, t_data *img)
{
	int fd;
	char *line;
	t_list *list;
	t_flags *flag;

	list = NULL;
	if (!(flag = malloc(sizeof(t_flags))))
		exit(0);
	ft_cleanflag(flag);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (fl_sumflag(flag) > 7 && line[0] != '\0') //прерыв карты
			ft_lstadd_back(&list, ft_lstnew(line));
		else if (line[0])
			ft_persetdata(img, flag, line);
	}
	ft_lstadd_back(&list, ft_lstnew(line));
	img->map = ft_bigarr(ft_create_arr(list), img);
	if (ft_checkmap(img->map, img) == 0)
		exit(1);
	free(flag); 
}