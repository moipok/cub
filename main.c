
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

int		main(int argc, char **argv)
{
	int i;
	int j;
    t_data  img;

	img.mlx = NULL;
	img.win = NULL;
	img.fulldata = 0;
	ft_parser(argc, argv, &img);
	i = 0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.r1, img.r2, "test");
	// img.img = mlx_new_image(img.mlx, img.r1, img.r2);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// text
	// ft_create_text(&img);
	// text
	ft_putwindow_3d(&img);
	mlx_hook(img.win, 2, 1L<<0, ft_docase, &img);
	mlx_loop(img.mlx);
	return (0);
}