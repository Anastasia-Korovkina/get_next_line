#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 15
# endif

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
size_t	ft_strlen(const char *s);
int     ft_strchr(char *buf);
char	*ft_strjoin(char *line, char *remember);
char    *ft_remember_text(int fd, char *remember);
char    *get_next_line(int fd);

#endif
