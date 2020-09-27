/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mybmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:03:46 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/27 23:48:52 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		bitmapheader(int file, t_data *img)
{
	unsigned char	s[54];
	int				i;

	i = -1;
	while (++i < 54)
		s[i] = (unsigned char)(0);
	s[0] = (unsigned char)('B');
	s[1] = (unsigned char)('M');
	ft_setsize(s + 2, img);
	s[10] = (unsigned char)('6');
	s[14] = (unsigned char)(40);
	ft_setr1(s + 18, img->r1);
	ft_setr1(s + 22, img->r2);
	s[26] = (unsigned char)(1);
	s[28] = (unsigned char)(24);
	if (write(file, s, 54) != 54)
		return (0);
	return (1);
}

int		bitmapmap(int file, t_data *img)
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
				return (0);
			k++;
		}
		if (ft_count4(img->r1) != 4)
		{
			range = ft_count4(img->r1) + 1;
			while (--range != 0)
				if (write(file, 0, 1) != 1)
					return (0);
		}
		i--;
	}
	return (1);
}

int		my_bmp(t_data *img, int argc, char **argv)
{
	int	file;

	if (ft_strncmp(argv[2], "--save", 7) == 0 && argc == 3)
	{
		ft_putscreen(img);
		if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT \
									| O_TRUNC | O_APPEND)) < 0)
			exit(pritnerror(cleanmap(img, 404)));
		if (bitmapheader(file, img) == 0)
		{
			close(file);
			exit(pritnerror(cleanmap(img, 403)));
		}
		if (bitmapmap(file, img) == 0)
		{
			close(file);
			exit(pritnerror(cleanmap(img, 403)));
		}
		close(file);
		return (1);
	}
	return (0);
}
