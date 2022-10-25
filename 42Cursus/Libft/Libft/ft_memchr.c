/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:25:32 by marvin            #+#    #+#             */
/*   Updated: 2022/10/24 14:25:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		printf("  ]%d]  ", (int)s); // TODO how to convert this ptr to int!!??
		if ((int)(s) == c)
			return ((void *)s);
		s++; 
	}
	return (NULL);
}


#include <string.h>
#include <stdio.h>
int main() { 
	char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    const unsigned int size = 10;
	
	int nb = 20;
    void * found = ft_memchr( data, nb, size );
    printf( "My is %s\n", ( found != NULL ? "found" : "not found" ) );
    
	void * found2 = memchr( data, nb, size );
    printf( "Official is %s\n", ( found2 != NULL ? "found" : "not found" ) );
}