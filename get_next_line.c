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

typedef struct	s_line {
	char	*str;
	int		newline;
}	t_line;

char	*str_append(char *s1, char *s2, int	len)
{
	char	*new;
	size_t	i;

	if (!s1)
	{
		free(s1);
		return (ft_strdup(s2));
	}
	i = 0;
	while (s1[i])
		i++;
	new = malloc((i + len + 1) * sizeof(char));
	ft_memcpy(new, s1, i);
	free(s1);
	ft_memcpy(new + i, s2, len);
	new[i + len] = '\0';
	return (new);
}

t_line	find_newline(int fd)
{
	t_line		temp;
	static char	*leftover;
	char		*buf;
	size_t		i;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!leftover)
	{
		leftover = malloc(sizeof(char));
		leftover[0] = '\0';
	}
	i = 0;
	while (i < BUFFER_SIZE)
	{
		read(fd, &buf[i], 1);
		if(buf[i] == '\n' || buf[i] == '\0')
		{
			buf[i + 1] = '\0';
			temp.str = ft_strjoin(leftover, buf);
			temp.newline = 1;
			free(buf);
			free(leftover);
			leftover = NULL;
			return (temp);
		}
		i++;
	}
	buf[i] = '\0';
	leftover = str_append(leftover, buf, i);
	temp.newline = 0;
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	t_line		temp;
	char		*line;

	temp.newline = 0;
	while (temp.newline == 0)
		temp = find_newline(fd);
	line = ft_strdup(temp.str);
	free(temp.str);
	return (line);
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
