/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:05:30 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/05 19:55:33 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lends;

	lends = ft_strlenn(dst);
	if (size <= lends)
		return (ft_strlenn(src) + size);
	i = 0;
	while (dst[i] && (i < size - 1))
		i++;
	j = 0;
	while (src[j] && (i < size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lends + ft_strlenn(src));
}

char		*ft_strjoinn(char *s1, char *s2)
{
	char *str;

	if (s2[0] == '\0')
		return (0);
	if (!s1)
	{
		if (!(s1 = malloc(sizeof(char ) * 1)))
			return (0);
		s1[0] = '\0';
	}
	if (!(str = malloc(sizeof(char ) * (ft_strlenn(s1) + ft_strlenn(s2)) + 1)))
		return (0);
	ft_bzero(str, ft_strlenn(s1) + ft_strlenn(s2) + 1);
	ft_strlcat(str, s1, -1);
	ft_strlcat(str, s2, -1);
	free(s1);
	return (str);
}

char		*ft_check_and_create(char *s)
{
	if (!(s = malloc(sizeof(char ) * 1)))
		return (NULL);
	s[0] = '\0';
	return (s);
}

char		*ft_substrr(char *s, unsigned int start, size_t len, int n)
{
	char			*str;
	unsigned	int	min;
	unsigned	int	i;

	if (!s)
		if ((s = ft_check_and_create(s)) == NULL)
			return (0);
	min = ft_strlenn(s) - start;
	if (min < len)
		len = min;
	i = 0;
	while (s[start + i] && i < len)
		i++;
	if (!(str = malloc(sizeof(char ) * i + 1)))
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	if (n)
		free(s);
	return (str);
}
