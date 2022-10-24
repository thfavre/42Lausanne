/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:49:00 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 19:30:32 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*str_ptr;

	str_ptr = str;
	while (*str)
	{
		if ('a' <= *str && *str <= 'z')
		{
			*str -= ('a' - 'A');
		}
		str++;
	}
	return (str_ptr);
}

//int	main(){	char str[] = "AbczZAd;foncolkusdg asd;][-0-908765a stdbl"; 
//printf("  |-> %s", ft_strupcase(str));}
