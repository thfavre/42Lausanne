/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:22:37 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/31 15:23:06 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ten_power(int nb)
{
	int	res;

	res = 1;
	while (nb--)
		res *= 10;
	return (res);
}

int	digit_number(long n)
{
	int	len;
	int	i;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		i;
	int		digit_nbr;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	nbr = (long)n;
	digit_nbr = digit_number(nbr);
	str = malloc(sizeof(*str) * (digit_nbr + 1));
	if (str != NULL)
	{
		i = 0;
		if (nbr < 0)
			str[i++] = '-';
		if (nbr < 0)
			nbr *= -1;
		while (i < digit_nbr)
		{
			str[i] = nbr / ten_power(digit_nbr - i - 1) + '0';
			nbr %= ten_power(digit_nbr - i++ - 1);
		}
		str[i] = 0;
	}
	return (str);
}

/*
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
*/
// int main(){
//  	printf("\nres:%s\n", ft_itoa(2147483647));
//  }