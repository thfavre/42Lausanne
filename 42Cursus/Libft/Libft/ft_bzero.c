/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:01:15 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/25 16:14:12 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	/*size_t			i;
	unsigned char	*string;

	string = (unsigned char *)s;
	i = 0;
	while (i < n)
		string[i++] = 0;*/
	ft_memset(s, 0, n);
}

/*#include <stdio.h>
int main(){char data[] = {'a', 'b', 'c', 'd', 'e', '6', 70, 80, 90, 100};
	ft_bzero(data, 2);
	printf("s : %s ", data);}
*/