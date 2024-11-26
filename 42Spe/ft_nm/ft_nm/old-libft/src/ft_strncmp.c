/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:08:56 by marvin            #+#    #+#             */
/*   Updated: 2024/11/26 18:10:51 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (!(*s1) && !(*s2))
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

// #include <stdio.h>
// int	main(){printf("%i",ft_strncmp("abcdef", "abc\375xx", 5));
// 	printf("%d",'\375' );}
