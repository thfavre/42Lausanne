/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:15:21 by marvin            #+#    #+#             */
/*   Updated: 2022/11/01 17:22:58 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_start_index(const char *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

static int	get_end_index(const char *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_strchr(set, s1[len - i - 1]) != NULL)
		i++;
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = get_start_index(s1, set);
	end = get_end_index(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = malloc(sizeof(*str) * (end - start + 1));
	if (str != NULL)
		ft_strlcpy(str, s1 + start, (end - start + 1));
	return (str);
}

// int main(){
// 	char s1[] = "abaZa";
// 	printf("|%s|", ft_strtrim(s1, "ab"));}
