/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:15:45 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/27 15:39:53 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>
int main ()
{
	const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
//	ft_memcpy(((void *)0), ((void *)0), 3);
} 
*/