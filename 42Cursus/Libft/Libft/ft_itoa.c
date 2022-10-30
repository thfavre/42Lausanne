/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:22:37 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/30 17:05:32 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ten_power(int nb)
{
	int res;

	res = 1;
	while (nb--)
		res *= 10;
	return (res);
}


char	*ft_itoa(int n)
{
	long	i;
	long	b;
	char	*res;
	int		is_negativ;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	is_negativ = 0;
	if (n < 0)
	{
		is_negativ = 1;
		n *= -1;
	}
	i = 1;
	b = 0;

	while (n / i > 0)
	{
		i *= 10;
		b++;
	}
	
	
	res = malloc(sizeof(*res) * (b + 1 + is_negativ));
	if (res != NULL)
	{	
		i = 0;
		if (is_negativ)
		{
			res[i++] = '-';
			//b--;
		}

		
		while (--b >= 0)
		{
			res[i++] = n/ten_power(b) + '0';
			n %= ten_power(b);

		}
		res[i] = 0;
	}
	return (res);
}

// int main(){
//  	printf("\nres:%s\n", ft_itoa(-2147483647));
//  }