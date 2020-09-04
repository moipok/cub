#include "cub3d.h"

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
		return (-1);
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
			else
			{
				rgb[k] = ft_atoi(str[i] + j);
				j += ft_intlenn(rgb[k]);
				k++;
			}
		}
		i++;
	}
	k = 0;
	while (k < 3)
	{
		printf("%d   ", rgb[k]);
	k++;
	}
	printf("\n ");
    return(0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}