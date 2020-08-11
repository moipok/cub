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

char	**ft_bigarr(char **arr, int n)
{
	char **new;
	int i;
	int j;

	new = malloc((sizeof(char*)) * (ft_arrlen(arr) * n + 1));
	i = 0;
	while (arr[i / n])
	{
		new[i] = malloc(sizeof(char) * (ft_strlenn(arr[i / n]) * n + 1));
		i++;
	}
	i = 0;
	while (arr[i / n])
	{
		j = 0;
		while (arr[i / n][j / n])
		{
			new[i][j] = arr[i / n][j / n];
			j++;
		}
		new[i][j] = '\0';
		i++;
	}
	//new[i][0] = '\0';
	ft_putstr("lala\n");
	//отчистить arr
	return (new);
}

void 	ft_parser(int argc, char **argv, t_data *img)
{
	char **arr;
	int i;
	int fd;
	char *line;
	t_list *list;

	
	line = NULL;
	list = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&list, ft_lstnew(line));
	ft_lstadd_back(&list, ft_lstnew(line));
	arr = ft_create_arr(list); //утечка
	i = 0;
	while(arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	img->arr = ft_bigarr(arr, 16); 
}