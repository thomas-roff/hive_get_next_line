/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:48:28 by thblack-          #+#    #+#             */
/*   Updated: 2025/05/15 20:42:28 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*sc;
	char	cc;

	sc = (char *)s;
	cc = (char)c;
	if (cc == '\0')
		return (sc + ft_strlen(sc));
	while (*sc != '\0')
	{
		if (*sc == cc)
			return (sc);
		sc++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(src);
	if (!dst || !src || size == 0)
		return (n);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (n);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*sc;

	len = ft_strlen(s);
	sc = malloc((len + 1) * sizeof(char));
	if (!sc)
		return (NULL);
	ft_strlcpy(sc, s, len + 1);
	return (sc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destc;
	char	*srcc;

	i = 0;
	destc = (char *)dest;
	srcc = (char *)src;
	while (i < n)
	{
		destc[i] = srcc[i];
		i++;
	}
	return (dest);
}
