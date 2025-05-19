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
	size_t	i;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		read(fd, &buf[i], 1);
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			line = ft_strdup(buf);
			free(buf);
			return (line);
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*temp;

	if (argc == 1)
		fd = STDIN_FILENO;
	if (argc >= 2)
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit (1);
	temp = get_next_line(fd);
	printf("Line is: %s", temp);
	free(temp);
	if (close(fd) < 0)
		exit (1);
	return (0);
}
