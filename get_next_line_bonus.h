/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:35:41 by nmohd-ed          #+#    #+#             */
/*   Updated: 2024/12/06 15:46:56 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*my_strdup(const char *s1);
int		my_strlen(const char *str);
char	*my_strjoin(char *s1, char *s2);
char	*my_strchr(const char *str, int ch);
char	*my_substr(char const *s, unsigned int start, size_t len);
char	*read_files(int fd, char *surplus);
char	*extract_from_buffer(char *surplus);
char	*after_buffer(char *surplus);
char	*get_next_line(int fd);
#endif