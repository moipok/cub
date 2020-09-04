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

	if (!(new = ft_calloc((sizeof(char*)), (ft_arrlen(arr) + 1))))
		exit (1);
	i = 0;
	flag = 0;
	while (arr[i])
	{
		if (!(new[i] = ft_calloc(sizeof(char), (ft_strlenn(arr[i]) + 1))))
			exit (1);
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
	freemass(arr);
	return (new);
}

void 	ft_parser(int argc, char **argv, t_data *img)
{
	char **arr;
	char **map;
	int i;
	int fd;
	char *line;
	t_list *list;
	t_flags *flag;
	char **tmp;

	
	line = NULL;
	list = NULL;
	if (!(flag = malloc(sizeof(t_flags))))
		exit(1);
	ft_cleanflag(flag);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (fl_sumflag(flag) > 7)
			ft_lstadd_back(&list, ft_lstnew(line));
		else if (line[0] == NULL)
			;
		else
		{
			tmp = ft_split(line, ' ');
			setdata(tmp, img, flag);
			free(tmp);
		}
	}
	ft_lstadd_back(&list, ft_lstnew(line));
	img->map = ft_bigarr(ft_create_arr(list), img);
	free(flag); 
}