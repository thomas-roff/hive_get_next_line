/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:52:38 by thblack-          #+#    #+#             */
/*   Updated: 2025/05/15 21:03:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;

	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (*buf != '\n')
	{
		read(fd, buf, 1);
		if (*buf == '\0')
			return (ft_strjoin(line, "\0"));
		line = ft_strjoin(line, buf);
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		fd = STDIN_FILENO;
	if (argc >= 2)
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit (1);
	printf("Line is: %s", get_next_line(fd));
	printf("Line is: %s", get_next_line(fd));
	printf("Line is: %s", get_next_line(fd));
	printf("Line is: %s", get_next_line(fd));
	if (close(fd) < 0)
		exit (1);
	return (0);
}
