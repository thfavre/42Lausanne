/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:22:06 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/26 15:05:45 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == 0)
				return ((char *)(haystack + i));
			if (haystack[i + j] == 0)
				break ;
		}
		i++;
	}
	return (NULL);
}

//  #include <stdio.h>
//  int main() { 
// printf(" %s ", ft_strnstr("lorem ipsum dolor sit amet", "sit", 0));}