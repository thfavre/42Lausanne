/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:21:44 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/04 18:57:01 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*dest_start;
	unsigned int	n;

	dest_start = dest;
	while (*dest)
		dest++;
	n = 0;
	while (n < nb && *(src + n))
	{
		*(dest + n) = *(src + n);
		n++;
	}
	*(dest + n) = '\0';
	return (dest_start);
}

//int main() {char de[20] = "de"; printf("%s", ft_strncat(de, "SRc", 0));}
