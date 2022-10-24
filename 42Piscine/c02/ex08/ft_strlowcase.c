/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:33:20 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 19:43:59 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*str_ptr;

	str_ptr = str;
	while (*str)
	{
		if ('A' <= *str && *str <= 'Z')
		{
			*str += ('a' - 'A');
		}
		str++;
	}
	return (str_ptr);
}

//int    main(){    char str[] = "AbZAd;ASbYZZolkusdg asd;][-0-9:765a sbl";
//printf("  |-> %s", ft_strlowcase(str));}
