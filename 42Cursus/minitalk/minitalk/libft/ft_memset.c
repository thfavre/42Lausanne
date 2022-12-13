/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:02:09 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/31 16:24:43 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = c;
	return (b);
}

/*
#include <stdio.h>
int main()
{
	char data[] = {'a', 'b', 'c', 'd', 'e', 60, 70, 80, 90, 100};
	printf("->%s ", ft_memset(data, 'a', 3));
}*/