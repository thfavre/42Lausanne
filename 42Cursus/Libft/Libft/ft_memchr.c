/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:25:32 by marvin            #+#    #+#             */
/*   Updated: 2022/10/25 16:14:12 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	int				i;

	string = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (string[i] == c)
			return (&string[i]);
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
int main() { 
	char data[] = {'a', 20, 30, 40, 50, 60, 70, 80, 90, 100};
    const unsigned int size = 10;
	
	int nb = 21;
    void * found = ft_memchr( data, nb, size );
    printf( "My is %s\n", ( found != NULL ? "found" : "not found" ) );
    
	void * found2 = memchr( data, nb, size );
    printf( "Official is %s\n", ( found2 != NULL ? "found" : "not found" ) );
}
*/