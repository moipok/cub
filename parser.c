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

char	**ft_create_arr(t_list *list)
{
	char **arr;
	int i;
	t_list *tmp;


	tmp = list;
	i = 0;
	arr = malloc((sizeof(char*)) * (ft_lstsize(list) + 1));
	while (list)
	{
		arr[i] = malloc((sizeof(char)) * (ft_strlenn(list->content) + 1));
		arr[i] = list->content;
		list = list->next;
		i++;
	}
	i = 0;
	ft_lstfree(&tmp);
	return (arr);
}

int		ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
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

char	**ft_bigarr(char **arr, t_data *img)
{
	char **new;
	int flag;
	int i;
	int j;

	new = ft_calloc((sizeof(char*)), (ft_arrlen(arr) + 1));
	i = 0;
	flag = 0;
	while (arr[i])
	{
		new[i] = ft_calloc(sizeof(char), (ft_strlenn(arr[i]) + 1));
		i++;
	}
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (flag == 0 && (arr[i][j] == 'N' || arr[i][j] == 'E' ||arr[i][j] == 'W' || arr[i][j] == 'S'))
			{
				new[i][j] = '0';
				flag = 1;
				img->x = i + 0.5;
				img->y = j + 0.5;
				img->mainangle = ft_angle(arr[i][j]);
			}
			else if (flag == 1 && (arr[i][j] == 'N' || arr[i][j] == 'E' ||arr[i][j] == 'W' || arr[i][j] == 'S'))
			{
				new[i][j] = '0';
				return (0);
			}
			else
				new[i][j] = arr[i][j];
			j++;
		}
		i++;
	}
	ft_putstr("lala\n");
	//отчистить arr
	return (new);
}


void	setdata(char **str, t_data *img)
{
	if (str[0] == NULL)
		return ;
	else if (str[0][0] == 'R')
	{
		img->r1 = ft_atoi(str[1]);
		img->r2 = ft_atoi(str[2]);
		img->fulldata++;
	}
	else if (str[0][0] == 'N')
	{
		img->fulldata++;
		if (str[0][1] == 'O')
			img->no = str[1];
		else 
			exit(1); // error
	}
	else if (str[0][0] == 'S')
	{
		img->fulldata++;
		if (ft_strlen(str[0]) == 1)
			img->sprite = str[1];
		else if (str[0][1] == 'O')
			img->so = str[1];
		else 
			exit(1); // error
	}
	else if (str[0][0] == 'W')
	{
		img->fulldata++;
		if (str[0][1] == 'E')
			img->we = str[1];
		else 
			exit(1); // error
	}
	else if (str[0][0] == 'E')
	{
		img->fulldata++;
		if (str[0][1] == 'A')
			img->ea = str[1];
		else 
			exit(1); // error
	}
	else if (str[0][0] == 'F')
	{
		img->floor = ft_setfloorcollor(str);
		img->fulldata++;
	}
	else if (str[0][0] == 'C')
	{
		img->cellar = ft_setfloorcollor(str);
		img->fulldata++;
	}
	else
		;
}

void 	ft_parser(int argc, char **argv, t_data *img)
{
	char **arr;
	char **map;
	int i;
	int fd;
	char *line;
	t_list *list;
	char **tmp;

	
	line = NULL;
	list = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (img->fulldata == 8)
			ft_lstadd_back(&list, ft_lstnew(line));
		else if (line[0] == NULL)
			;
		else
		{
			tmp = ft_split(line, ' ');
			setdata(tmp, img);
			printf("%s\n", tmp[0]);
		}
	}
	printf("wow\n");
	ft_lstadd_back(&list, ft_lstnew(line));
	img->map = ft_bigarr(ft_create_arr(list), img); 
}