/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:31:46 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 04:34:24 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

//int main(){printf("%d\n", ft_str_is_numeric("0987 d 65431"));}
