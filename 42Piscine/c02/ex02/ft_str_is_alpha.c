/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:26:33 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 04:29:45 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
		{
			str++;
			continue ;
		}
		return (0);
	}
	return (1);
}

//int main(){printf("%d\n", ft_str_is_alpha("aklSDADjdoaxy"));}
