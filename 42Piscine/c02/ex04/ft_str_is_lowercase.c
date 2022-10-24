/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:34:47 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 04:37:06 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
		{
			str++;
			continue ;
		}
		return (0);
	}
	return (1);
}

//int main(){printf("%d\n", ft_str_is_lowercase("abcdefz"));}
