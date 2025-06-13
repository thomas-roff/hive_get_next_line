/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:52:38 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/10 16:00:42 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_join_free(char *temp, char *str)
{
	char	*res;

	res = ft_strjoin(temp, str);
	free(temp);
	return (res);
}

char	*ft_leftover(char *temp)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	res = ft_calloc((ft_strlen(temp) - i + 1), sizeof(char));
	if (!res)
		return (free(temp), NULL);
	j = 0;
	while (temp[i])
		res[j++] = temp[i++];
	free(temp);
	res[j] = '\0';
	return (res);
}

char	*ft_find_line(char *heap)
{
	char	*line;
	size_t	i;

	i = 0;
	while (heap[i] && heap[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (heap[i] && heap[i] != '\n')
	{
		line[i] = heap[i];
		i++;
	}
	if (heap[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(res), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(res), free(buffer), NULL);
		buffer[byte_read] = '\0';
		res = ft_join_free(res, buffer);
		if (!res)
			return (free(buffer), NULL);
		if (ft_strchr(res, '\n'))
			break ;
	}
	return (free(buffer), res);
}

char	*get_next_line(int fd)
{
	static char	*heap;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1)
		return (NULL);
	heap = ft_read_file(fd, heap);
	if (!heap)
		return (NULL);
	if (heap[0] == '\0')
	{
		if (heap)
			free(heap);
		heap = NULL;
		return (NULL);
	}
	line = ft_find_line(heap);
	if (!line)
		return (free(heap), NULL);
	heap = ft_leftover(heap);
	if (!heap)
		return (free(line), NULL);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	char	*filename;
//
// 	if (argc == 1)
// 		fd = STDIN_FILENO;
// 	if (argc >= 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		filename = argv[1];
// 		printf("%s\n", filename);
// 	}
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	return (0);
// }
//
