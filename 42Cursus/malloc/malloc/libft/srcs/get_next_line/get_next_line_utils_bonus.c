/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:01:25 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/28 14:30:26 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	s = malloc(sizeof(*s) * (s1_len + s2_len + 1));
	if (s != NULL)
	{
		ft_memcpy(s, s1, s1_len);
		ft_memcpy(s + s1_len, s2, s2_len);
		s[s1_len + s2_len] = '\0';
	}
	return (s);
}

// calloc with ft_bzero added
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	char	*str;
	size_t	i;

	array = malloc(nmemb * size);
	if (array != NULL)
	{
		str = (char *)array;
		i = 0;
		while (i < nmemb * size)
		{
			str[i] = '\0';
			i++;
		}
	}
	return (array);
}
