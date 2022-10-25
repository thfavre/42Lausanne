/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:08:56 by marvin            #+#    #+#             */
/*   Updated: 2022/10/24 14:08:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

//#include <stdio.h>
//int	main(){printf("%i",ft_strncmp("12340", "12349", 3));}
