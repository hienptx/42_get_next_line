/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:12:16 by hipham            #+#    #+#             */
/*   Updated: 2023/12/05 17:01:35 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

static char	*save_rest(char *line)
{
	char	*temp;
	char	*start;
	char	*str;

	str = line;
	start = ft_strchr(line, '\n');
	if (start != NULL)
		line = start + 1;
	else
		return (ft_free(line));
	while (*str != 0)
		str++;
	if (*line == '\0')
		return (NULL);
	temp = malloc(sizeof(char) * (str - start + 1));
	if (temp == NULL)
		return (NULL);
	temp = ft_strncpy(temp, start, str - start);
	temp[str - start] = '\0';
	return (temp);
}

static char	*get_line(char *line)
{
	char	*return_line;
	char	*temp;
	int		i;

	i = 0;
	temp = line;
	while (*temp != 0 && *temp != '\n')
	{
		i++;
		temp++;
	}
	if (*temp == '\n')
		i++;
	return_line = malloc(sizeof(char) * (i + 1));
	if (return_line == NULL)
		return (ft_free(line));
	return_line = ft_strncpy(return_line, line, i);
	return_line[i] = '\0';
	return (return_line);
}

static char	*read_line(int fd, char *buffer)
{
	char	*temp;
	int		byte_read;
	char	*old_temp;

	temp = ft_strdup("");
	if (temp == NULL)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (ft_free(temp));
		buffer[byte_read] = '\0';
		old_temp = temp;
		temp = ft_strjoin(temp, buffer);
		if (temp == NULL)
			return (NULL);
		free(old_temp);
		if (ft_strchr(temp, '\n') != NULL)
			break ;
	}
	if (byte_read == 0 && temp[0] == '\0')
		return (ft_free(temp));
	return (temp);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*read;

	read = read_line(fd, buffer);
	if (read == NULL)
		return (NULL);
	line = get_line(read);
	if (line == NULL)
	{
		free(read);
		return (NULL);
	}
	read = save_rest(read);
	free (read);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("onlynl.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
