/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:39:53 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/04 04:41:00 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 > *s2)
			return (1);
		else if (*s2 > *s1)
		{
			return (-1);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	if (*s1 > *s2)
		return (1);
	return (-1);
}

//int main(){printf("%i", ft_strcmp("3oto", "2oto"));}
