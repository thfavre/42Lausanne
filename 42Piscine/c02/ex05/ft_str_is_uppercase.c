/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:39:40 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 04:40:43 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
		{
			str++;
			continue ;
		}
		return (0);
	}
	return (1);
}

//int main(){printf("%d\n", ft_str_is_uppercase("ABZ"));}
