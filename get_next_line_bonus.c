/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:23:13 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/27 17:43:19 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_remember_text(int fd, char *remember)
{
	int		bytes;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes && !ft_strchr(remember))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		remember = ft_strjoin(remember, buf);
	}
	free(buf);
	return (remember);
}

char	*ft_copy(char *remember)
{
	char	*line;
	int		bytes;

	bytes = 0;
	if (!(*remember))
		return (NULL);
	while (remember[bytes] && remember[bytes] != '\n')
		bytes++;
	line = (char *)malloc(sizeof(char) * (bytes + 2));
	if (line)
	{
		bytes = 0;
		while (*remember && *remember != '\n')
			line[bytes++] = *remember++;
		if (*remember == '\n')
			line[bytes++] = '\n';
		line[bytes] = '\0';
		return (line);
	}
	return (NULL);
}

char	*ft_new_remember(char *remember)
{
	int		i;
	int		j;
	char	*new_remember;

	i = 0;
	j = 0;
	while (remember[i] && remember[i] != '\n')
		i++;
	if (!remember[i])
	{
		free(remember);
		return (NULL);
	}
	new_remember = malloc(sizeof(char) * (ft_strlen(remember) - i + 1));
	if (new_remember)
	{
		i++;
		while (remember[i])
			new_remember[j++] = remember[i++];
		new_remember[j] = '\0';
		free(remember);
		return (new_remember);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remember[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remember[fd] = ft_remember_text(fd, remember[fd]);
	if (!remember[fd])
		return (NULL);
	line = ft_copy(remember[fd]);
	remember[fd] = ft_new_remember(remember[fd]);
	return (line);
}
