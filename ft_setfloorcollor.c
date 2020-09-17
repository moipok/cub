/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setfloorcollor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:43 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/17 23:37:47 by fbarbera         ###   ########.fr       */
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

void	ft_setrgb(char **str, int *i, int *j, int *k, int *rgb)
{
	if (str[*i][*j] == ',')
		*j = *j + 1;
	else if (str[*i][*j] >= '0' && str[*i][*j] <= '9')
	{
		*rgb = ft_atoi(str[*i] + *j);
		*j = *j + ft_intlenn(*rgb);
		*k = *k + 1;
	}
	else
	{
		printf("error\n");
		exit(1);
	}
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
		while (str[i][j] && k < 3)
			ft_setrgb(str, &i, &j, &k, &rgb[k]);			
		i++;
	}
    return(0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}