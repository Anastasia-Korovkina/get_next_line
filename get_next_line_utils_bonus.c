/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:23:19 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/27 17:34:43 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*res;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ((ft_strlen((char *)str1))
				+ (ft_strlen((char *)str2)) + 1));
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	while (str1[j])
		res[i++] = str1[j++];
	j = 0;
	while (str2[j])
		res[i++] = str2[j++];
	res[i] = '\0';
	free (str1);
	return (res);
}
