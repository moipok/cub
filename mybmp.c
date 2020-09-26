/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mybmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:03:46 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/26 22:50:27 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_count4(int r)
{
	return (4 - (r * 3) % 4);
}

void	ft_setsize(unsigned char *s, t_data *img)
{
	int size;
	int col;

	col = (img->r1 * 3) + ft_count4(img->r1);
	size = 54 + (col * img->r2);
	s[0] = (unsigned char)(size);
	s[1] = (unsigned char)(size >> 8);
	s[2] = (unsigned char)(size >> 16);
	s[3] = (unsigned char)(size >> 24);
}

void	ft_setr1(unsigned char *s, int r)
{
	s[0] = (unsigned char)(r);
	s[1] = (unsigned char)(r >> 8);
	s[2] = (unsigned char)(r >> 16);
	s[3] = (unsigned char)(r >> 24);	
}

void	bitmapheader(int file, t_data *img)
{
	unsigned char s[54];
	int i;

	i = -1;
	while (++i < 54)
		s[i] = (unsigned char)(0);
	s[0] = (unsigned char)('B');
	s[1] = (unsigned char)('M');
	ft_setsize(s + 2, img); //размер
	s[10] = (unsigned char)('6'); //смещение (36)
	s[14] = (unsigned char)(40); //что то 28
	ft_setr1(s + 18, img->r1); //ширина и длина
	ft_setr1(s + 22, img->r2);
	s[26] = (unsigned char)(1);
	s[28] = (unsigned char)(24); //bit for pixel
	i = 0;
	while (i < 54)
		printf("%2x ", s[i++]);
	write(file, s, 54);
}

void	bitmapmap(int file, t_data *img)
{
	int i;
	int k;
	int range;

	i = img->r2;
	while (i)
	{
		k = 0;
		while (k < img->r1)
		{
			if (write_collor(img, k, i - 1, file) < 0)
				exit(0);
			k++;
		}
		range = ft_count4(img->r1) + 1;
		while (--range != 0)
			write(file, 0, 1);
		i--;
	}
}

int		my_bmp(t_data *img, int argc, char **argv)
{
	int	file;

	if (argc != 3)
		return (0);
	else if (ft_strncmp(argv[2], "--save", 7) == 0)
	{
		ft_putscreen(img);
		if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT \
									| O_TRUNC | O_APPEND)) < 0)
			return (0);
		bitmapheader(file, img);
		bitmapmap(file, img);
		close(file);
		return (0);
	}
	else
		return (0);
	
}