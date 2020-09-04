#include "cub3d.h"

void	ft_cleanflag(t_flags *flag)
{
	flag->noflag = 0;
	flag->soflag = 0;
	flag->weflag = 0;
	flag->eaflag = 0;
	flag->spriteflag = 0;
	flag->r1flag = 0;
	flag->r2flag = 0;
	flag->cellarflag = 0;
	flag->floorflag = 0;
	flag->allflag = 0;
}

int fl_sumflag(t_flags *flag)
{
	return (flag->noflag + flag->soflag + flag->weflag + \
	flag->eaflag + flag->spriteflag + flag->r1flag + \
	flag->cellarflag + flag->floorflag);
}

void	setdata(char **str, t_data *img, t_flags *flag)
{
	flag->allflag = fl_sumflag(flag);
	if (str[0] == NULL)
		return ;
	else if (str[0][0] == 'R' && !flag->r1flag && !flag->r2flag)
	{
		img->r1 = ft_atoi(str[1]);
		img->r2 = ft_atoi(str[2]);
		flag->r1flag = 1;
		flag->r2flag = 1;
	}
	else if (str[0][0] == 'N')
	{
		if (str[0][1] == 'O' && !flag->noflag)
		{
			img->no = ft_strdup(str[1]);
			flag->noflag = 1;
		}
		else 
			exit(1); // error
	}
	else if (str[0][0] == 'S')
	{
		if (ft_strlen(str[0]) == 1 && !flag->spriteflag)
		{
			img->sprite = ft_strdup(str[1]);
			flag->spriteflag = 1;
		}
		else if (str[0][1] == 'O' && !flag->soflag)
		{
			img->so = ft_strdup(str[1]);
			flag->soflag = 1;
		}
		else 
			exit(1); // error
	}
	else if (str[0][0] == 'W')
	{
		img->fulldata++;
		if (str[0][1] == 'E' && !flag->weflag)
		{
			img->we = ft_strdup(str[1]);
			flag->weflag = 1;
		}
		else 
			exit(1); // error
	}
	else if (str[0][0] == 'E')
	{
		img->fulldata++;
		if (str[0][1] == 'A' && !flag->eaflag)
		{
			img->ea = ft_strdup(str[1]);
			flag->eaflag = 1;
		}
		else 
			exit(1); // error
	}
	else if (str[0][0] == 'F' && !flag->floorflag)
	{
		img->floor = ft_setfloorcollor(str);
		flag->floorflag = 1;
		img->fulldata++;
	}
	else if (str[0][0] == 'C' && !flag->cellarflag)
	{
		img->cellar = ft_setfloorcollor(str);
		flag->cellarflag = 1;
		img->fulldata++;
	}
	else
		exit(1);
}