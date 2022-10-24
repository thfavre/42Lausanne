/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:22:05 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 16:34:12 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_ptr);
}

/*int main () {
	char src[]= "Hello_booy";
	char dest[100];
	ft_strcpy(dest, src);
	//printf("Final copied string : %s\n", dest);}
	printf("Final copied string : %s\n", ft_strcpy(dest, src));
}*/
