/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:43:28 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/27 18:11:25 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_strchr(char *buf);
char	*ft_strjoin(char *line, char *remember);
char	*ft_remember_text(int fd, char *remember);
char	*get_next_line(int fd);

#endif
