/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setfloorcollor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:43 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/05 19:55:36 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" //fewpoewfnfqnlfnenelwfnwefq

int ft_intlenn(int n)
{
    int len;

    if (n == 0)
        return (1);
    len = 0;
    while (n)
    {
        n = n/10;
        len++;
    }
    return (len);
}

int 		ft_setfloorcollor(char **str)
{
    int *rgb;
	int i;
	int j;
	int k;

    if (!(rgb = malloc(sizeof(int) * 3)))
		exit (1);
	i = 1;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (k > 2)
				break;
			else if (str[i][j] == ',')
				j++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				rgb[k] = ft_atoi(str[i] + j);
				j += ft_intlenn(rgb[k]);
				k++;
			}
			else
			{
				printf("error\n");
				exit(1);
			}
			
		}
		i++;
	}
    return(0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}