/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:36:40 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/04 18:12:38 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n)
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		if (!(*s1) && !(*s2))
			return (0);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

//int	main(){printf("%i",ft_strncmp("1234", "1219", 3));}
