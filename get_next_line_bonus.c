/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:22:24 by nmohd-ed          #+#    #+#             */
/*   Updated: 2024/12/06 16:03:11 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_files(int fd, char *surplus)
{
	char	*temp;
	ssize_t	num_read;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	num_read = read(fd, temp, BUFFER_SIZE);
	while (num_read > 0)
	{
		temp[num_read] = '\0';
		surplus = my_strjoin(surplus, temp);
		if (my_strchr(surplus, '\n'))
			break ;
		num_read = read(fd, temp, BUFFER_SIZE);
	}
	if (num_read < 0)
	{
		free(temp);
		free(surplus);
		return (NULL);
	}
	free(temp);
	return (surplus);
}

char	*extract_from_buffer(char *surplus)
{
	char	*line;
	int		len;

	len = 0;
	if (!surplus || surplus[0] == '\0')
		return (NULL);
	while (surplus[len] != '\n' && surplus[len] != '\0')
		len++;
	if (surplus[len] == '\n')
		len++;
	line = my_substr(surplus, 0, len);
	return (line);
}

char	*after_extract(char *surplus)
{
	char	*nextline;
	int		len;

	len = 0;
	if (!surplus)
		return (NULL);
	if (surplus[0] == '\0')
	{
		free (surplus);
		return (NULL);
	}
	while (surplus[len] != '\n' && surplus[len] != '\0')
		len++;
	if (surplus[len] == '\n')
		len++;
	nextline = my_substr(surplus, len, my_strlen(surplus));
	free(surplus);
	return (nextline);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = my_strdup("");
	buffer[fd] = read_files(fd, buffer[fd]);
	line = extract_from_buffer(buffer[fd]);
	buffer[fd] = after_extract(buffer[fd]);
	return (line);
}

// #include <stdio.h>

// int main(void)
// {
// 	int     fd;           // File descriptor for the file to be read
// 	char    *line;        // Pointer to store each line read from the file
// 	// Open a sample file in read-only mode
// 	fd = open("./sample.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	// Read and print lines until EOF
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line); // Print the line
// 		free(line);         // Free the line after use
// 	}
// 	// Close the file after reading all lines
// 	close(fd);
// 	return (0);
// }