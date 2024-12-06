/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:00:59 by nmohd-ed          #+#    #+#             */
/*   Updated: 2024/12/06 15:46:22 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	my_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*my_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = my_strlen(s1);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*my_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = my_strlen(s1) + my_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	free(s1);
	return (ptr);
}

char	*my_strchr(const char *str, int ch)
{
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s || start >= (unsigned int)my_strlen(s))
		return (my_strdup(""));
	if ((size_t)my_strlen(s + start) < len)
		len = my_strlen(s + start);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len && s[start])
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
