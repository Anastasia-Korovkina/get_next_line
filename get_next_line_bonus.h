/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:23:23 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/27 17:54:13 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
int		ft_strchr(char *buf);
char	*ft_strjoin(char *line, char *remember);
char	*ft_remember_text(int fd, char *remember);
char	*get_next_line(int fd);

#endif
