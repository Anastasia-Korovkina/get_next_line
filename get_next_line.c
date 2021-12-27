#include "get_next_line.h"

char    *ft_remember_text(int fd, char *remember)
{
    int     bytes;
    char    *buf;

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

char *ft_copy(char *remember)
{
    char    *line;
    int     bytes;
    
    bytes = 0;
    if (!(*remember))
        return (NULL);
    while (remember[bytes] && remember[bytes] != '\n')
    {
        bytes++;
    }
	line = (char *)malloc(sizeof(char) * (bytes + 2));
	if (line)
	{
        bytes = 0;
		while (*remember && *remember != '\n')
			line[bytes++] = *remember++;
        if (*remember == '\n')
            line[bytes++] = '\n';
		line[bytes] = '\0';
        return(line);
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

char    *get_next_line(int fd)
{
    char        *line; //строка
    static char *remember; //фиксирует, где остановились

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    remember = ft_remember_text(fd, remember);
    printf("\n/rem1/ -> %s\n", remember);
    if (!remember)
        return (NULL);
    line = ft_copy(remember);
    remember = ft_new_remember(remember);
    static int i;
    printf("\n------%d------\n/line/ -> %s\n/rem/  -> %s\n", i++, line, remember);
    return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd;

    fd = open("file.txt", O_RDONLY);
    printf("/res/  -> %s", get_next_line(fd));
    printf("/res/  -> %s", get_next_line(fd));
    printf("/res/  -> %s", get_next_line(fd));
    printf("/res/  -> %s", get_next_line(fd));
    printf("/res/  -> %s", get_next_line(fd));
    printf("/res/  -> %s", get_next_line(fd));

    return 0;
}
