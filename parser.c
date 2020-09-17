/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:10 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/17 23:37:52 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_create_arr(t_list *list)
{
	char **arr;
	int i;
	t_list *tmp;

	tmp = list;
	i = 0;
	if (!(arr = malloc((sizeof(char*)) * (ft_lstsize(list) + 1))))
		exit (1);
	while (list)
	{
		if (!(arr[i] = malloc((sizeof(char)) * (ft_strlenn(list->content) + 1))))
			exit (1);
		arr[i] = list->content;
		list = list->next;
		i++;
	}
	i = 0;
	ft_lstfree(&tmp);
	return (arr);
}

char **mallocbigarr(char **arr)
{
	int i;
	int j;
	char **new;

	if (!(new = ft_calloc((sizeof(char*)), (ft_arrlen(arr) + 1))))
		exit (1);
	i = 0;
	j = ft_maxlenarr(arr);
	while (arr[i])
	{
		if (!(new[i] = ft_calloc(sizeof(char), j + 1)))
			exit (1);
		i++;
	}
	return(new);
}

int checknwes(char a)
{
	if (a == 'N' || a == 'E' || a == 'W' || a == 'S')
		return (1);
	return (-1);
}

char	**ft_bigarr(char **arr, t_data *img)
{
	char **new;
	int flag;
	int i;
	int j;

	new = mallocbigarr(arr);
	img->num = 0;
	i = 0;
	flag = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (checknwes(arr[i][j]) == 1)
			{
				if (flag > 0)
					exit(0); //более 1 героя
				new[i][j] = '0';
				flag = 1;
				img->x = i + 0.5;
				img->y = j + 0.5;
				img->mainangle = ft_angle(arr[i][j]);
			}
			else if (arr[i][j] == ' ')
				new[i][j] = '1';
			else
				new[i][j] = arr[i][j];
			if (arr[i][j] == '2')
				img->num++;
			j++;
		}
		i++;
	}
	freemass(arr);
	return (new);
}

void 	ft_parser(int argc, char **argv, t_data *img)
{
	int fd;
	char *line;
	t_list *list;
	t_flags *flag;
	char **tmp;

	list = NULL;
	if (!(flag = malloc(sizeof(t_flags))))
		exit(0);
	ft_cleanflag(flag);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (fl_sumflag(flag) > 7 && line[0] != '\0') //прерыв карты
			ft_lstadd_back(&list, ft_lstnew(line));
		else if (line[0] != NULL)
		{
			tmp = ft_split(line, ' ');
			setdata(tmp, img, flag);
			free(tmp);
		}
	}
	ft_lstadd_back(&list, ft_lstnew(line));
	img->map = ft_bigarr(ft_create_arr(list), img);
	if (ft_checkmap(img->map, img->x) == 0)
	{
		printf("error");
		exit(1);
	}
	free(flag); 
}