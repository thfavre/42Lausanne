/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:45:08 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 04:47:40 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 127)
		{
			str++;
			continue ;
		}
		return (0);
	}
	return (1);
}

//int main(){printf("%d\n", ft_str_is_uppercase("ABZ"));}
