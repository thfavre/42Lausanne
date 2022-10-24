/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:59:19 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/12 01:52:13 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	unsigned int	t;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	t = 0;
	while (t * t <= (unsigned int)nb)
	{
		if (t * t == (unsigned int)nb)
			return (t);
		t++;
	}
	return (0);
}

int main() { 
	
	printf("%d ", ft_sqrt(921550625));  
	printf("%d ", ft_sqrt(921550625));  
	printf("%d ", ft_sqrt(121554325));  
	printf("%d ", ft_sqrt(521213525));  
	printf("%d ", ft_sqrt(321550625));  
	printf("%d ", ft_sqrt(924550625));  
	printf("%d ", ft_sqrt(3250625));  
}
