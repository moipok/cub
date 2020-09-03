
#include "cub3d.h"

int             ft_docase(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(1);
	}
	else if (keycode == 13 || keycode == 126)
		img = ft_w(img);
	else if (keycode == 1 || keycode == 125)
		img = ft_s(img);
	else if (keycode == 2)
		img = ft_d(img);
	else if (keycode == 0)
		img = ft_a(img);
	else if (keycode == 123)
		img->mainangle += 0.08;
	else if (keycode == 124)
		img->mainangle -= 0.08;
	else
		printf("%d\n", keycode);
	ft_putwindow_3d(img);
	return (0);
}

// void	ft_create_text(t_data *img)
// {
// 	printf("1\n");
// 	img->ntext = (t_xpm*)malloc(1);
// 	printf("2\n");
// 	mlx_xpm_file_to_image(&(img)->ntext->mlx, "./text/WALL77.xpm", &(img)->ntext->width, &(img)->ntext->height);
// 	printf("3\n");
// }

void	inittexture(t_data *data)
{
	(data)->notext = (t_xpm*)malloc(sizeof(t_xpm));
	(data)->sotext = (t_xpm*)malloc(sizeof(t_xpm));
	(data)->wetext = (t_xpm*)malloc(sizeof(t_xpm));
	(data)->eatext = (t_xpm*)malloc(sizeof(t_xpm));
	(data)->spritetext = (t_xpm*)malloc(sizeof(t_xpm));

	data->notext->mlx = mlx_xpm_file_to_image(data->mlx, data->no, &data->notext->width, &data->notext->height);
	data->notext->addr = mlx_get_data_addr(data->notext->mlx, &data->notext->bits_per_pixel, &data->notext->line_length, &data->notext->endian);
	
	data->sotext->mlx = mlx_xpm_file_to_image(data->mlx, data->so, &data->sotext->width, &data->sotext->height);
	data->sotext->addr = mlx_get_data_addr(data->sotext->mlx, &data->sotext->bits_per_pixel, &data->sotext->line_length, &data->sotext->endian);
	
	data->wetext->mlx = mlx_xpm_file_to_image(data->mlx, data->we, &data->wetext->width, &data->wetext->height);
	data->wetext->addr = mlx_get_data_addr(data->wetext->mlx, &data->wetext->bits_per_pixel, &data->wetext->line_length, &data->wetext->endian);
	
	data->eatext->mlx = mlx_xpm_file_to_image(data->mlx, data->ea, &data->eatext->width, &data->eatext->height);
	data->eatext->addr = mlx_get_data_addr(data->eatext->mlx, &data->eatext->bits_per_pixel, &data->eatext->line_length, &data->eatext->endian);
	
	data->spritetext->mlx = mlx_xpm_file_to_image(data->mlx, data->sprite, &data->spritetext->width, &data->spritetext->height);
	data->spritetext->addr = mlx_get_data_addr(data->spritetext->mlx, &data->spritetext->bits_per_pixel, &data->spritetext->line_length, &data->spritetext->endian);
}

int		main(int argc, char **argv)
{
	int i;
	int j;
    t_data  img;

	img.mlx = NULL;
	img.win = NULL;
	img.fulldata = 0;
	ft_parser(argc, argv, &img);
	printf("%s \n %s \n %s \n %s\n %s \n", img.no, img.so, img.we, img.ea, img.sprite);
	i = 0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.r1, img.r2, "test");
	//	ft_putwindow_3d(&img);
	inittexture(&img);
	put_texture(&img);
	mlx_hook(img.win, 2, 1L<<0, ft_docase, &img);
	mlx_loop(img.mlx);
	return (0);
}