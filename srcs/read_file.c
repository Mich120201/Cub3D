/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:02:07 by mich              #+#    #+#             */
/*   Updated: 2023/05/29 09:02:08 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_line(int fd)
{
	int		byte;
	char	buffer;
	char	*line;

	byte = 1;
	line = ft_calloc(1, sizeof(char));
	while (byte)
	{
		byte = read(fd, &buffer, 1);
		if (buffer == '\n' || !byte)
			break ;
		line = ft_charjoin(line, buffer);
	}
	return (line);
}

int	count_lines(char *file)
{
	int		lines;
	int		fd;
	int		bytes;
	char	buffer;

	fd = open(file, O_RDONLY);
	if (fd < 1)
		return (-1);
	lines = 1;
	bytes = read(fd, &buffer, 1);
	while (bytes > 0)
	{
		if (buffer == '\n')
			lines++;
		bytes = read(fd, &buffer, 1);
	}
	close(fd);
	return (lines);
}

char	**read_file(char *fname)
{
	char	**file;
	int		fd;
	int		line;
	int		lines;

	lines = count_lines(fname);
	if (lines == -1)
		return ((char **)null_error("ERROR: The file does not exist"));
	file = malloc(sizeof(char *) * (lines + 1));
	if (!file)
		return ((char **)null_error("ERROR: malloc"));
	fd = open(fname, O_RDONLY);
	if (fd < 1)
		return ((char **)null_error("ERROR: The file does not exist"));
	line = 0;
	file[line] = get_next_line(fd);
	while (++line < lines - 1)
		file[line] = get_next_line(fd);
	file[line] = NULL;
	close(fd);
	return (file);
}
